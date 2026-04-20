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

    virtual Bet calcNextBet(BetResult const &) = 0;
    virtual void reset();

    double getBaseBet() const;

  protected:
    ABettingStrategy(double);

    double base_bet, current_bet;
};
