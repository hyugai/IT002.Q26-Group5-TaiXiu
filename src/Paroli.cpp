#include "../include/Paroli.h"
#include <cstdlib>

/* *
 * QA: add comments
 * */

Paroli::Paroli(double base_bet, int target_wins) : ABettingStrategy(base_bet) {
    consecutive_wins = 0;
    target_wins = target_wins;
}

Bet Paroli::calNextBet(BetResult const &prev_result) {
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

void Paroli::reset() {
    ABettingStrategy::reset();
    consecutive_wins = 0;
}
