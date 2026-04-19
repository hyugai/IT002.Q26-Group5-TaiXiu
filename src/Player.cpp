#include "Player.h"
#include <cstdlib>

// 1. Constructor: Khởi tạo vốn thông qua hàm của Actor
Player::Player(double initialBalance) : currentBet(BetType::Xiu, 0.0)
{
    setBalance(initialBalance);
    this->strategy = nullptr;
}

// 2. Hàm gán chiến thuật — reset state và đặt cược đầu tiên = baseBet
void Player::setStrategy(std::unique_ptr<ABettingStrategy> newStrategy)
{
    this->strategy = std::move(newStrategy);
    this->strategy->reset(); // Đảm bảo state sạch (consecutiveWins=0, index=0,...)
    // Khởi tạo cược đầu tiên trực tiếp, không qua calNextBet để tránh ảnh hưởng state
    BetType side = (rand() % 2 == 0) ? BetType::Xiu : BetType::Tai;
    currentBet = Bet(side, this->strategy->getBaseBet());
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
