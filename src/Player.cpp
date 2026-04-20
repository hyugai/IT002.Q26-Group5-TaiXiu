#include "../include/Player.h"
#include <cstdlib>

/**/
Player::Player(double initial_balance) : current_bet(BetType::Xiu, 0.0) {
    setBalance(initial_balance);
    strategy = nullptr;
}

/* *
 * @brief Gán chiến thuật mới, reset state và khởi tạo cược đầu tiên = base_bet
 * @param new_strategy
 * @return void
 * */
void Player::setStrategy(unique_ptr<ABettingStrategy> new_strategy) {
    strategy = std::move(new_strategy);
    strategy->reset(); // reset() đưa strategy về trạng thái sạch — tránh
                       // Paroli/Fibonacci bị ảnh  hưởng bởi state còn sót. Cược
                       // đầu set trực tiếp thay vì gọi calcNextBet() để không
                       // làm tăng cược ngay ở ván 1.

    BetType side = (rand() % 2 == 0) ? BetType::Xiu : BetType::Tai;
    current_bet = Bet(side, strategy->getBaseBet());
}

/* *
 * @brief Thực hiện đặt cược cho lượt tiếp theo dựa trên kết quả trước đó.
 * @param prev_result Kết quả của lượt cược vừa diễn ra.
 * @return void
 * */
void Player::placeBet(BetResult const &prev_result) {
    if (strategy != nullptr) {
        current_bet = strategy->calcNextBet(prev_result);
    }
}

/* *
 * @brief Lấy thông tin về lượt cược hiện tại của người chơi.
 * @return Bet Đối tượng Bet chứa cửa đặt và số tiền cược hiện tại.
 * */
Bet Player::getCurrentBet() const { return current_bet; }
