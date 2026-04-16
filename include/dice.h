#pragma once
#include <random>

class Dice {
private:
    std::mt19937 rng;

public:
    Dice();
    int roll();
};
