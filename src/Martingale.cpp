#include "../include/Martingale.h"
#include <cstdlib> // Dùng cho rand()

// Gọi trực tiếp Constructor của lớp cha (ABettingStrategy) để nó lưu tiền gốc
Martingale::Martingale(double baseBet) : ABettingStrategy(baseBet) {}

// Hàm tính cược mới (trả về kiểu Bet)
Bet Martingale::calNextBet(BetResult const &prevResult)
{
    if (prevResult == BetResult::Win)
    {
        dCurrentBet = dBaseBet; // Thắng thì quay về mốc ban đầu
    }
    else
    {
        dCurrentBet *= 2; // Thua thì gấp đôi tiền
    }

    // Trò chơi tỷ lệ 50/50 nên chọn random Tài hoặc Xỉu
    BetType side = (rand() % 2 == 0) ? BetType::Xiu : BetType::Tai;

    return Bet(side, dCurrentBet);
}
