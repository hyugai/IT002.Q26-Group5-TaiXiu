#pragma once
#include "ABettingStrategy.h"

class Martingale : public ABettingStrategy
{
public:
    Martingale(double baseBet);

    // Dùng đúng định dạng hàm của lớp cha mới
    Bet calNextBet(BetResult const &prevResult) override;
};
