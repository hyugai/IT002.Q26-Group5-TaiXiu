#pragma once
#include <vector>
#include "Dice.h"
#include "House.h"
#include "Player.h"
#include "RoundRecord.h" 

class Table {
private:
    std::vector<Dice> dices;
    House house;
    Player player;
    std::vector<RoundRecord> records;

public:
    // Constructor nhận vào thông tin House và Player 
    Table(const House& h, const Player& p);

    void play();
};
