#include "Dice.h"
#include <cstdlib>

/* Constructor không cần seed riêng — dùng chung rand() để srand(42) kiểm soát được */
Dice::Dice() {}

/* Dùng rand() thay vì mt19937 để đảm bảo cùng seed → cùng chuỗi xúc xắc cho mọi strategy */
int Dice::roll() {
    return (rand() % 6) + 1;
}
