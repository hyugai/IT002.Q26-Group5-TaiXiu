#pragma once
#include "Actor.h"

class House : public Actor {
    double commission_rate;
    double min_bet;
    double max_bet;

  public:
    House(double, double, double);

    double getCommissionRate() const;
    double getMinBet() const;
    double getMaxBet() const;

    double limitBet(double) const;
};
