#pragma once

enum class BetType
{
  Tai,
  Xiu
};
enum class BetResult
{
  Win,
  Lose
};

struct Bet
{
  BetType type;
  double dAmount;
  // Nên có Constructor để tạo Bet nhanh
  Bet(BetType t, double a) : type(t), dAmount(a) {}
};

struct ABettingStrategy
{
  // 2 hàm này bắt buộc lớp con phải tự viết (vì có = 0)
  virtual Bet calNextBet(BetResult const &prevResult) = 0;
  virtual void reset();

  virtual ~ABettingStrategy() = default;

protected:
  double dBaseBet, dCurrentBet;

  // Constructor cho lớp cha
  ABettingStrategy(double baseBet) : dBaseBet(baseBet), dCurrentBet(baseBet) {}
};
