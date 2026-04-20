#pragma once
#include "ABettingStrategy.h"

class Paroli : public ABettingStrategy {
    int consecutive_wins;
    int target_wins;

  public:
    Paroli(double, int);

    Bet calcNextBet(BetResult const &) override;
    void reset() override;
};
