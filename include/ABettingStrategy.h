#pragma once

enum class BetType { Tai, Xiu };
enum class BetResult { Win, Lose };

class Bet {
  public:
    Bet(BetType, double);

    BetType type;
    double amount;
};

class ABettingStrategy {
  public:
    // virtual ~ABettingStrategy() = default;

    virtual Bet calNextBet(BetResult const &) = 0;
    virtual void reset();

  protected:
    ABettingStrategy(double);

    double base_bet, current_bet;
};
