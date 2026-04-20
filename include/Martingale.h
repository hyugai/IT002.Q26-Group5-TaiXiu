#pragma once
#include "ABettingStrategy.h"

class Martingale : public ABettingStrategy {
  public:
    Martingale(double);

    Bet calNextBet(BetResult const &) override;
};
