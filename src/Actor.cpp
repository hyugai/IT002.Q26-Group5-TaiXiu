#include "../include/Actor.h"

/*
 * @brief Trả về số dư hiện tại
 * @return double
 * */
double Actor::getBalance() const { return balance; }

/*
 * @brief "Ép" số dư thành một giá trị khác
 * @return void
 * */
void Actor::setBalance(double amount) { balance = amount; }

/*
 * @brief Cập nhật số dư thêm một lượng âm hoặc dương mỗi khi thắng hoặc thua
 * @return void
 * */
void Actor::updateBalance(double amount) { balance += amount; }
