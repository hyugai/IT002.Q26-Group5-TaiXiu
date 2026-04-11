#include "Player.h"

// 1. Constructor: Khởi tạo vốn ban đầu và đặt chiến thuật mặc định là trống (nullptr)
Player::Player(double initialBankroll)
{
    this->bankroll = initialBankroll;
    this->currentStrategy = nullptr;
}

// 2. Các hàm tương tác với vốn (Getter / Setter)
double Player::getBankroll() const
{
    return bankroll;
}

void Player::updateBankroll(double amount)
{
    // Nếu amount là số dương (thắng), vốn sẽ tăng.
    // Nếu amount là số âm (thua), vốn sẽ tự động giảm.
    bankroll += amount;
}

// 3. Hàm cốt lõi của Strategy Pattern: Cài đặt hoặc thay đổi chiến thuật
void Player::setStrategy(std::unique_ptr<IBettingStrategy> newStrategy)
{
    // Vì ta đang dùng std::unique_ptr (con trỏ độc quyền), ta không thể copy nó.
    // Bắt buộc phải dùng std::move() để "chuyển giao quyền sở hữu" chiến thuật mới cho Player.
    currentStrategy = std::move(newStrategy);
}

// 4. Các hàm hành vi: Uỷ quyền (Delegate) cho Strategy tính toán
double Player::calculateNextBet(bool lastBetWon)
{
    // Kiểm tra xem người chơi đã được gắn chiến thuật chưa
    if (currentStrategy != nullptr)
    {
        // Nếu có, gọi hàm tính tiền của chiến thuật đó
        return currentStrategy->calculateNextBetAmount(lastBetWon);
    }
    return 0.0; // Trả về 0 nếu chưa có chiến thuật
}

int Player::determineBetSide()
{
    if (currentStrategy != nullptr)
    {
        // Hỏi chiến thuật xem ván này đánh cửa nào
        return currentStrategy->determineBetSide();
    }
    return 0; // Mặc định đánh Xỉu (0) nếu chưa cài đặt chiến thuật
}