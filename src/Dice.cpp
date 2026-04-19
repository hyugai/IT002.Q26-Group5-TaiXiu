#include "Dice.h"
#include <cstdlib>

/* Constructor không cần seed riêng — dùng chung rand() để srand(42) kiểm soát được */
Dice::Dice() {}

/* Dùng rand() để srand(42) kiểm soát toàn bộ — cùng chuỗi xúc xắc cho mọi strategy */
int Dice::roll() {
    return (rand() % 6) + 1;
}
