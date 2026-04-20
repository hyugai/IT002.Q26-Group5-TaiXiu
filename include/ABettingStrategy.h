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
    virtual ~ABettingStrategy() = default;

    virtual Bet calNextBet(BetResult const &) = 0;
    virtual void reset();

    double getBaseBet() const { return base_bet; }

  protected:
    ABettingStrategy(double);

    double base_bet, current_bet;
};
