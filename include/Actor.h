#pragma once

class Actor {
  public:
    virtual ~Actor() = default;

    double getBalance() const;
    void setBalance(double);
    void updateBalance(double);

  protected:
    double balance;
};
