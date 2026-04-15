#include "../include/Paroli.h"
#include <cstdlib>

Paroli::Paroli(double baseBet, int targetWins) : ABettingStrategy(baseBet)
{
    this->consecutiveWins = 0;
    this->targetWins = targetWins;
}

Bet Paroli::calNextBet(BetResult const &prevResult)
{
    if (prevResult == BetResult::Win)
    {
        consecutiveWins++;
        if (consecutiveWins >= targetWins)
        {
            dCurrentBet = dBaseBet; // Chốt lời
            consecutiveWins = 0;
        }
        else
        {
            dCurrentBet *= 2; // Nhân đôi khi đang đà thắng
        }
    }
    else
    {
        dCurrentBet = dBaseBet; // Thua thì đứt chuỗi
        consecutiveWins = 0;
    }

    BetType side = (rand() % 2 == 0) ? BetType::Xiu : BetType::Tai;
    return Bet(side, dCurrentBet);
}

void Paroli::reset()
{
    dCurrentBet = dBaseBet;
    consecutiveWins = 0;
}
