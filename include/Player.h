#ifndef PLAYER_H
#define PLAYER_H

#include <memory>
#include "IBettingStrategy.h" // Nhúng interface chiến thuật vào

class Player
{
private:
    double bankroll; // Số tiền vốn hiện tại của người chơi

    // Sử dụng Smart Pointer để quản lý bộ nhớ tự động, đây là điểm cốt lõi của Strategy Pattern
    std::unique_ptr<IBettingStrategy> currentStrategy;

public:
    // 1. Constructor: Hàm khởi tạo người chơi khi bắt đầu game
    Player(double initialBankroll);

    // 2. Các hàm tương tác với vốn (Getter / Setter)
    double getBankroll() const;
    void updateBankroll(double amount); // Cộng tiền khi thắng hoặc trừ tiền khi thua

    // 3. Hàm cốt lõi của Strategy Pattern: Cho phép người chơi đổi chiến thuật bất cứ lúc nào
    void setStrategy(std::unique_ptr<IBettingStrategy> newStrategy);

    // 4. Các hàm hành vi: Hỏi chiến thuật xem ván này đánh bao nhiêu và đánh cửa nào
    double calculateNextBet(bool lastBetWon);
    int determineBetSide(); // Ví dụ trả về 0 là Xỉu, 1 là Tài
};

#endif // PLAYER_H