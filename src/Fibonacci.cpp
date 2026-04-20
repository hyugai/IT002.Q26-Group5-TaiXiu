#include "../include/Fibonacci.h"
#include <cstdlib>

/* *
 * @brief Khởi tạo chiến thuật đặt cược Fibonacci với mức cược cơ bản.
 * @param base_bet Mức tiền cược cơ sở ban đầu.
 * @return Không có.
 * */
Fibonacci::Fibonacci(double base_bet) : ABettingStrategy(base_bet) {
    current_idx = 0;
}

/* *
 * @brief Tính toán giá trị số Fibonacci tại vị trí n để làm hệ số nhân tiền
 * cược.
 *
 * @param n Chỉ số trong dãy Fibonacci.
 *
 * @return Giá trị số Fibonacci tương ứng với chỉ số n.
 * */
int Fibonacci::getFibonacciMultiplier(int n) {
    if (n <= 0)
        return 1;
    if (n == 1)
        return 1;

    int a = 1, b = 1, c = 2;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

/* *
 * @brief Tính toán lượt cược tiếp theo dựa trên kết quả của lượt trước đó.
 * @param prev_result Kết quả của lượt cược vừa rồi (Thắng/Thua).
 * @return Đối tượng Bet chứa thông tin cửa đặt và số tiền cược mới.
 * */
Bet Fibonacci::calcNextBet(BetResult const &prev_result) {
    if (prev_result == BetResult::Win) {
        current_idx -= 2;
        if (current_idx < 0) {
            current_idx = 0;
        }
    } else {
        current_idx++;
    }

    current_bet = base_bet * getFibonacciMultiplier(current_idx);

    BetType side = (rand() % 2 == 0) ? BetType::Xiu : BetType::Tai;
    return Bet(side, current_bet);
}

/* *
 * @brief Đặt lại trạng thái của chiến thuật về mặc định (vị trí đầu tiên trong
 * dãy).
 *
 * @param Không có.
 *
 * @return Không có.
 * */
void Fibonacci::reset() {
    ABettingStrategy::reset();
    current_idx = 0;
}
