#include "../include/Martingale.h"
#include <cstdlib>

/* *
 * @brief Khởi tạo chiến thuật đặt cược Martingale.
 * @param base_bet Mức tiền cược cơ bản ban đầu.
 * @return None Không có.
 * */
Martingale::Martingale(double base_bet) : ABettingStrategy(base_bet) {}

/* *
 * @brief Tính toán lượt cược tiếp theo (gấp đôi mức cược nếu thua, về mức cơ
 * bản nếu thắng).
 *
 * @param prev_result Kết quả của lượt cược trước đó (BetResult).
 *
 * @return Bet Đối tượng Bet chứa thông tin cửa đặt và số tiền cược được tính
 * toán.
 * */
Bet Martingale::calcNextBet(BetResult const &prev_result) {
    if (prev_result == BetResult::Win) {
        current_bet = base_bet;
    } else {
        current_bet *= 2;
    }

    BetType side = (rand() % 2 == 0) ? BetType::Xiu : BetType::Tai;

    return Bet(side, current_bet);
}
