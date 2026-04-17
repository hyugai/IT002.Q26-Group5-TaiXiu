#include "Dice.h"

Dice::Dice() {
    std::random_device rd;
    rng.seed(rd());
}

int Dice::roll() {
    std::uniform_int_distribution<int> dist(1, 6);
    return dist(rng); 
}
