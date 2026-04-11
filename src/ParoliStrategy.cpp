#include "ParoliStrategy.h"
#include <cstdlib> // Dùng cho hàm rand() nếu muốn random cửa cược

// Khởi tạo các giá trị ban đầu
ParoliStrategy::ParoliStrategy(double baseBet, int targetWins)
{
    this->baseBet = baseBet;
    this->currentBet = baseBet;
    this->consecutiveWins = 0;
    this->targetWins = targetWins;
}

// Logic cốt lõi của Paroli tính toán tiền cược
double ParoliStrategy::calculateNextBetAmount(bool lastBetWon)
{
    if (lastBetWon)
    {
        consecutiveWins++; // Tăng biến đếm chuỗi thắng

        // Kiểm tra xem đã đạt đủ chuỗi thắng kỳ vọng chưa
        if (consecutiveWins >= targetWins)
        {
            // Đã đạt mục tiêu (ví dụ thắng 3 ván thông) -> Chốt lời, quay về cược gốc
            currentBet = baseBet;
            consecutiveWins = 0;
        }
        else
        {
            // Đang trên đà thắng và chưa tới đích -> Nhân đôi tiền cược
            currentBet *= 2;
        }
    }
    else
    {
        // Nếu thua -> Mất chuỗi, quay ngay về mức cược gốc
        currentBet = baseBet;
        consecutiveWins = 0;
    }

    return currentBet;
}

// Hàm quyết định chọn cửa Tài hay Xỉu (Quy ước: 0 là Xỉu, 1 là Tài)
int ParoliStrategy::determineBetSide()
{
    // Vì tỷ lệ Tài Xỉu là 50/50, người chơi có thể đánh cố định 1 cửa hoặc random.
    // Ở đây ví dụ chọn random cửa Tài hoặc Xỉu.
    return rand() % 2;
}

// Hàm reset toàn bộ chiến thuật (dùng khi bắt đầu 1 session mới)
void ParoliStrategy::resetStrategy()
{
    currentBet = baseBet;
    consecutiveWins = 0;
}