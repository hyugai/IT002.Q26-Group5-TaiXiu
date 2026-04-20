#include "../include/Player.h"

/* *
 * QA: add comments
 * */

Player::Player(double initial_balance) : current_bet(BetType::Xiu, 0.0) {
    setBalance(initial_balance);
    strategy = nullptr;
}

void Player::setStrategy(unique_ptr<ABettingStrategy> newStrategy) {
    strategy = std::move(newStrategy);
}

void Player::placeBet(BetResult const &prev_result) {
    if (strategy != nullptr) {
        current_bet = strategy->calNextBet(prev_result);
    }
}

Bet Player::getCurrentBet() const { return current_bet; }
