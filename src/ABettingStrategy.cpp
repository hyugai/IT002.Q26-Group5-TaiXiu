#include "../include/ABettingStrategy.h"

/* *
 * @brief Khởi tạo ván cược tài hoặc xỉu với số tiền cược
 * @param t Tài hoặc Xỉu
 * @param a Tiền cược
 * */
Bet::Bet(BetType t, double a) : type(t), amount(a) {}

/*
 * @brief Khởi tạo lớp cha với số tiền cược ban đầu
 * */
ABettingStrategy::ABettingStrategy(double base_bet)
    : base_bet(base_bet), current_bet(base_bet) {}

/*
 * @brief Trả về số tiền cược ban đầu
 * @return double
 * */
double ABettingStrategy::getBaseBet() const { return base_bet; }

/*
 * @brief Khi "đứt chuỗi" chiến lược, đưa số tiền cược ban đầu về ban đầu
 * @return void
 * */
void ABettingStrategy::reset() { current_bet = base_bet; }
