#include "../include/ABettingStrategy.h"

/**/
Bet::Bet(BetType t, double a) : type(t), amount(a) {}

/**/
ABettingStrategy::ABettingStrategy(double base_bet)
    : base_bet(base_bet), current_bet(base_bet) {}

/*
 * @brief
 * @return double
 * */
double ABettingStrategy::getBaseBet() const { return base_bet; }

/*
 * @brief
 * @return void
 * */
void ABettingStrategy::reset() { current_bet = base_bet; }
