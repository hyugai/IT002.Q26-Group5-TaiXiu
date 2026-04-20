#pragma once
#include "ABettingStrategy.h"
struct RoundRecord {
    Bet       bet;              
    BetResult result;           
    double    dCurrentBankroll; 

    RoundRecord(Bet b, BetResult r, double bankroll)
        : bet(b), result(r), dCurrentBankroll(bankroll) {}
};
