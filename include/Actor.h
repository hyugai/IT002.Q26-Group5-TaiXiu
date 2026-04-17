#pragma once

struct Actor
{
  double getBalance() const;
  void setBalance(double amount);    // Bỏ const & đi
  void updateBalance(double amount); // Bỏ const & đi

  virtual ~Actor() = default;

protected: // Đổi từ private sang protected để Player và House lấy được tiền
  double dBalance;
};
