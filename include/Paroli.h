#pragma once
#include "ABettingStrategy.h"

class Paroli : public ABettingStrategy
{
private:
    int consecutiveWins;
    int targetWins;

public:
    Paroli(double baseBet, int targetWins);

    Bet calNextBet(BetResult const &prevResult) override;
    void reset() override;
};
