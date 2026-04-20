#pragma once
#include "Dice.h"
#include "House.h"
#include "Player.h"
#include "RoundRecord.h"
#include <vector>


class Table {
    std::vector<Dice> dices;          
    House house;                      
    Player player;                    
    std::vector<RoundRecord> records; 

  public:
   
    Table(const House& , Player&& );

    void play();

    const std::vector<RoundRecord> &getRecords() const;
};
