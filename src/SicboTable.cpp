#include "Table.h"
#include <iostream>

Table::Table(const House& h, const Player& p)
    : house(h), player(p) {
    dices = std::vector<Dice>(3);
}

void Table::play() {
    int totalScore = 0;

    for (int i = 0; i < 3; ++i) {
        int face = dices[i].roll();
        totalScore += face;
    }

}