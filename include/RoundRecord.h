#pragma once
#include "ABettingStrategy.h"

class RoundRecord {
  public:
    Bet bet;
    BetResult result;
    double current_bankroll;
};
