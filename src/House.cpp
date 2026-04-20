#include "../include/House.h"

/* *
 * @brief Khởi tạo House với các thông số luật chơi
 * @param commission_rate Tỉ lệ tiền xâu (ví dụ: 0.05 = 5%)
 * @param min_bet         Mức cược tối thiểu
 * @param max_bet         Mức cược tối đa
 * */
House::House(double commission_rate, double min_bet, double max_bet)
    : commission_rate(commission_rate), min_bet(min_bet), max_bet(max_bet) {
    balance = 0.0;
}

double House::getCommissionRate() const { return commission_rate; }
double House::getMinBet() const { return min_bet; }
double House::getMaxBet() const { return max_bet; }

/* *
 * @brief Giới hạn số tiền cược trong khoảng [dMinBet, dMaxBet]
 * @param amount Số tiền muốn cược
 * @return Số tiền hợp lệ
 * */
double House::limitBet(double amount) const {
    if (amount < min_bet)
        return min_bet;
    if (amount > max_bet)
        return max_bet;
    return amount;
}
