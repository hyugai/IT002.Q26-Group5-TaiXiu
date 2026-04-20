#include "../include/Paroli.h"
#include <cstdlib>

/* *
 * @brief Khởi tạo chiến thuật đặt cược Paroli với mức cược cơ sở và mục tiêu
 * thắng liên tiếp.
 * @param base_bet Mức tiền cược cơ bản ban đầu.
 *        target_wins Số trận thắng liên tiếp mục tiêu để dừng chuỗi tăng cược.
 * */
Paroli::Paroli(double base_bet, int target_wins) : ABettingStrategy(base_bet) {
    consecutive_wins = 0;
    this->target_wins = target_wins;
}

/* *
 * @brief Tính toán lượt cược tiếp theo (gấp đôi mức cược khi thắng cho đến khi
 * đạt mục tiêu, về mức cơ bản nếu thua).
 *
 * @param prev_result Kết quả của lượt cược trước đó (BetResult).
 *
 * @return Bet Đối tượng Bet chứa thông tin cửa đặt và số tiền cược được tính
 * toán.
 * */
Bet Paroli::calcNextBet(BetResult const &prev_result) {
    if (prev_result == BetResult::Win) {
        consecutive_wins++;
        if (consecutive_wins >= target_wins) {
            current_bet = base_bet;
            consecutive_wins = 0;
        } else {
            current_bet *= 2;
        }
    } else {
        current_bet = base_bet;
        consecutive_wins = 0;
    }

    BetType side = (rand() % 2 == 0) ? BetType::Xiu : BetType::Tai;
    return Bet(side, current_bet);
}

/* *
 * @brief Đặt lại trạng thái chiến thuật (reset số trận thắng liên tiếp và mức
 * cược).
 *
 * @param void
 *
 * @return void trả về giá trị.
 * */
void Paroli::reset() {
    ABettingStrategy::reset();
    consecutive_wins = 0;
}
