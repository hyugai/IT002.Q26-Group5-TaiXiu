#include "../include/ABettingStrategy.h"

/* *
 * QA: add comments for methods following standard format in
 * 'refactor_check.txt'
 * */

Bet::Bet(BetType t, double a) : type(t), amount(a) {}
ABettingStrategy::ABettingStrategy(double base_bet)
    : base_bet(base_bet), current_bet(base_bet) {}
void ABettingStrategy::reset() { current_bet = base_bet; }
