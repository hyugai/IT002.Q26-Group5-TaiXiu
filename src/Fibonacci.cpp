#include "Fibonacci.h"
#include <cstdlib>

Fibonacci::Fibonacci(double baseBet) : ABettingStrategy(baseBet)
{
    this->currentIndex = 0;
}

int Fibonacci::getFibonacciMultiplier(int n)
{
    if (n <= 0)
        return 1;
    if (n == 1)
        return 1;

    int a = 1, b = 1, c = 2;
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

Bet Fibonacci::calNextBet(BetResult const &prevResult)
{
    if (prevResult == BetResult::Win)
    {
        currentIndex -= 2;
        if (currentIndex < 0)
        {
            currentIndex = 0;
        }
    }
    else
    {
        currentIndex++;
    }

    dCurrentBet = dBaseBet * getFibonacciMultiplier(currentIndex);

    BetType side = (rand() % 2 == 0) ? BetType::Xiu : BetType::Tai;
    return Bet(side, dCurrentBet);
}

void Fibonacci::reset()
{
    ABettingStrategy::reset(); // Gọi hàm của lớp cha để reset tiền
    this->currentIndex = 0;    // Tự reset thêm biến vị trí của con
}