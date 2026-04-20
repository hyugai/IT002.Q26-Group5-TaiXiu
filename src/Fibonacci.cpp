#include "../include/Fibonacci.h"
#include <cstdlib>

Fibonacci::Fibonacci(double base_bet) : ABettingStrategy(base_bet) {
    current_idx = 0;
}

int Fibonacci::getFibonacciMultiplier(int n) {
    if (n <= 0)
        return 1;
    if (n == 1)
        return 1;

    int a = 1, b = 1, c = 2;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

Bet Fibonacci::calNextBet(BetResult const &prev_result) {
    if (prev_result == BetResult::Win) {
        current_idx -= 2;
        if (current_idx < 0) {
            current_idx = 0;
        }
    } else {
        current_idx++;
    }

    current_bet = base_bet * getFibonacciMultiplier(current_idx);

    BetType side = (rand() % 2 == 0) ? BetType::Xiu : BetType::Tai;
    return Bet(side, current_bet);
}

void Fibonacci::reset() {
    ABettingStrategy::reset();
    current_idx = 0;
}
