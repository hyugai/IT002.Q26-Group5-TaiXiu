#pragma once
#include "Dice.h"
#include "House.h"
#include "Player.h"
#include "RoundRecord.h"
#include <vector>

using namespace std;

class Table {
    vector<Dice> dices;
    House house;
    Player player;
    vector<RoundRecord> records;

  public:
    Table(House const &, Player &&);

    void play();
    vector<RoundRecord> const &getRecords() const;
};
