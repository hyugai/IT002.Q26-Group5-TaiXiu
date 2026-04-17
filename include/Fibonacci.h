#pragma once

#include "ABettingStrategy.h"

class Fibonacci : public ABettingStrategy
{
private:
    int currentIndex;
    int getFibonacciMultiplier(int n);

public:
    Fibonacci(double baseBet);

    Bet calNextBet(BetResult const &prevResult) override;
    void reset() override;
};
