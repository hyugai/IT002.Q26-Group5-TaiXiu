#include "../include/Dice.h"
#include <cstdlib>

/* *
 * @brief Tung xúc xắc và trả về giá trị ngẫu nhiên.
 * Sử dụng rand() thay vì std::mt19937 để đảm bảo khi dùng cùng
 * một seed sẽ sinh ra cùng một chuỗi kết quả xúc xắc, giúp nhất quán
 * khi so sánh các chiến thuật khác nhau.
 * @return int Giá trị mặt xúc xắc (từ 1 đến 6)
 * */
int Dice::roll() { return (rand() % 6) + 1; }
