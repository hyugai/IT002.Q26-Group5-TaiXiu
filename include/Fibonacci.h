#pragma once

#include "ABettingStrategy.h"

class Fibonacci : public ABettingStrategy {
    int current_idx;

    int getFibonacciMultiplier(int);

  public:
    Fibonacci(double);

    Bet calNextBet(BetResult const &) override;
    void reset() override;
};
