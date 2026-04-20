#include "../include/Table.h"

/*
 * @brief Khởi tạo bàn chơi với House và Player
 * @param h House chứa thông số luật
 * @param p Player — dùng std::move vì Player chứa unique_ptr (không copy được)
 */
Table::Table(const House &h, Player &&p) : house(h), player(std::move(p)) {
    dices = std::vector<Dice>(3); /* Tạo 3 viên xúc xắc */
}

/*
 * @brief Chơi 1 ván: tung xúc xắc, xác định Tài/Xỉu, cập nhật balance
 *
 * Luật:
 *   - Tổng 3 xúc xắc >= 11 → Tài, ngược lại → Xỉu
 *   - Thắng: nhận profit = bet * (1 - commissionRate)  [trừ tiền xâu]
 *   - Thua:  mất toàn bộ tiền cược
 */
void Table::play() {
    // Hết tiền thì dừng, không chơi thêm
    if (player.getBalance() <= 0)
        return;

    // Tung 3 xúc xắc, cộng tổng điểm
    int totalScore = 0;
    for (int i = 0; i < 3; ++i)
        totalScore += dices[i].roll();

    bool isTai = (totalScore >= 11); // Tài: 11-18, Xỉu: 3-10

    Bet currentBet = player.getCurrentBet();

    // Ép bet vào giới hạn [minBet, maxBet] của House trước
    currentBet.amount = house.limitBet(currentBet.amount);

    // Sau đó cap tại balance — tránh trường hợp balance < minBet bị âm
    if (currentBet.amount > player.getBalance())
        currentBet.amount = player.getBalance();

    // Xác định thắng/thua dựa trên cửa đặt và kết quả xúc xắc
    BetResult result;
    if ((isTai && currentBet.type == BetType::Tai) ||
        (!isTai && currentBet.type == BetType::Xiu))
        result = BetResult::Win;
    else
        result = BetResult::Lose;

    // Cập nhật số dư cho player và house
    if (result == BetResult::Win) {
        double profit = currentBet.amount * (1.0 - house.getCommissionRate());
        player.updateBalance(profit);
        house.updateBalance(-profit);
    } else {
        player.updateBalance(-currentBet.amount);
        house.updateBalance(currentBet.amount);
    }

    // Ghi lại kết quả ván, rồi tính cược ván tiếp theo
    records.push_back({currentBet, result, player.getBalance()});
    player.placeBet(result);
}

/*
 * @brief Trả về danh sách kết quả tất cả ván đã chơi (read-only)
 */
std::vector<RoundRecord> const &Table::getRecords() const { return records; }
