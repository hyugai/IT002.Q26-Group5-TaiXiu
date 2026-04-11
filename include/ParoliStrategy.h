#ifndef PAROLI_STRATEGY_H
#define PAROLI_STRATEGY_H

#include "IBettingStrategy.h"

class ParoliStrategy : public IBettingStrategy
{
private:
    double baseBet;      // Mức cược gốc ban đầu
    double currentBet;   // Mức cược hiện tại
    int consecutiveWins; // Số ván thắng liên tiếp hiện có
    int targetWins;      // Mục tiêu số ván thắng liên tiếp để chốt lời (ví dụ: 3)

public:
    // Constructor khởi tạo chiến thuật
    ParoliStrategy(double baseBet, int targetWins);

    // Ghi đè (override) các hàm từ interface
    double calculateNextBetAmount(bool lastBetWon) override;
    int determineBetSide() override;
    void resetStrategy() override;
};

#endif // PAROLI_STRATEGY_H