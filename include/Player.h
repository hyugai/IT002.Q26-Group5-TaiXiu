#pragma once

#include <memory>
#include "Actor.h"
#include "ABettingStrategy.h"

// Phải có : public Actor
class Player : public Actor
{
private:
    // Đã dùng ABettingStrategy mới
    std::unique_ptr<ABettingStrategy> strategy;

    // Biến lưu giữ cược của ván hiện tại (như trong Sơ đồ UML)
    Bet currentBet;

public:
    Player(double initialBalance);

    void setStrategy(std::unique_ptr<ABettingStrategy> newStrategy);

    // Theo UML mới, Player chỉ có 1 hàm placeBet() thay vì 2 hàm cũ
    void placeBet(BetResult const &prevResult);

    Bet getCurrentBet() const;
};
