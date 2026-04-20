#include "../include/Martingale.h"
#include <cstdlib>

/* *
 * QA: add comments
 * */

Martingale::Martingale(double base_bet) : ABettingStrategy(base_bet) {}

Bet Martingale::calNextBet(BetResult const &prev_result) {
    if (prev_result == BetResult::Win) {
        current_bet = base_bet;
    } else {
        current_bet *= 2;
    }

    BetType side = (rand() % 2 == 0) ? BetType::Xiu : BetType::Tai;

    return Bet(side, current_bet);
}
