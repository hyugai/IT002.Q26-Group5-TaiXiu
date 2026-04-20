#pragma once
#include "ABettingStrategy.h"

class Martingale : public ABettingStrategy {
  public:
    Martingale(double);

    Bet calcNextBet(BetResult const &) override;
};
