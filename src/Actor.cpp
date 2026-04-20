#include "../include/Actor.h"

/* *
 * QA: add comments
 * */

double Actor::getBalance() const { return balance; }
void Actor::setBalance(double amount) { balance = amount; }
void Actor::updateBalance(double amount) { balance += amount; }
