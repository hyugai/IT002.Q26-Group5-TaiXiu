#include "Player.h"

// 1. Constructor: Khởi tạo vốn thông qua hàm của Actor
Player::Player(double initialBalance) : currentBet(BetType::Xiu, 0.0)
{
    setBalance(initialBalance);
    this->strategy = nullptr;
}

// 2. Hàm gán chiến thuật
void Player::setStrategy(std::unique_ptr<ABettingStrategy> newStrategy)
{
    this->strategy = std::move(newStrategy);
}

// 3. Hàm cốt lõi: Uỷ quyền cho chiến thuật tính toán và cập nhật currentBet
void Player::placeBet(BetResult const &prevResult)
{
    if (strategy != nullptr)
    {
        // Chiến thuật sẽ tính toán trả về Object Bet (bao gồm cửa cược và số tiền)
        currentBet = strategy->calNextBet(prevResult);
    }
}

// 4. Hàm lấy thông tin ván cược hiện tại
Bet Player::getCurrentBet() const
{
    return currentBet;
}
