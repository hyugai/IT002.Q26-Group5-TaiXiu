#include "Actor.h"

double Actor::getBalance() const
{
    return this->dBalance;
}

void Actor::setBalance(double amount)
{
    this->dBalance = amount;
}

void Actor::updateBalance(double amount)
{
    this->dBalance += amount;
}
