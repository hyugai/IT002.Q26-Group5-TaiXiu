#include <iostream>
#include <string>

class House {
private:
    // --- Dữ liệu (Dòng 23, 30) ---
    long long balance;         // Quỹ chi trả (dùng để chung tiền thắng cho khách)
    long long houseBankroll;   // Quỹ lợi nhuận (nơi tích lũy 5% tiền phế - Dòng 30)

    // --- Cấu hình luật (Dòng 26) ---
    long long minBet;
    long long maxBet;

    // Singleton: Private Constructor
    House() {
        balance = 100000000;   // Khởi tạo 100 triệu cho quỹ chi trả
        houseBankroll = 0;     // Quỹ phế ban đầu bằng 0
        minBet = 10000;        // Mặc định Min 10k
        maxBet = 5000000;      // Mặc định Max 5 triệu
    }

    House(const House&) = delete;
    House& operator=(const House&) = delete;

public:
    static House& getInstance() {
        static House instance;
        return instance;
    }

    // --- Xử lý cấu hình (Dòng 26) ---
    void setBetLimits(long long min, long long max) {
        this->minBet = min;
        this->maxBet = max;
    }

    // --- Hàm kiểm tra lệnh cược (Dòng 28) ---
    // Giúp trưởng nhóm kiểm tra nhanh trước khi xử lý logic ván đấu
    bool validateBet(long long amount, std::string& reason) {
        if (amount < minBet) {
            reason = "Tien cuoc thap hon muc tối thieu!";
            return false;
        }
        if (amount > maxBet) {
            reason = "Tien cuoc vuot qua muc tối đa!";
            return false;
        }
        return true;
    }

    // --- Quản lý dòng tiền (Dòng 30, 31, 32) ---

    // Khi Player thua: Nhà cái nhận toàn bộ tiền
    void receiveLossMoney(long long amount) {
        balance += amount;
    }

    // Khi Player thắng: Trả thưởng và trích phế (Dòng 30 & 32)
    void payWinMoney(long long betAmount) {
        long long commission = betAmount * 0.05; // 5% tiền phế
        long long netPayout = betAmount * 0.95;  // Trả cho khách 1:0.95

        balance -= netPayout;
        houseBankroll += commission; // Cộng dồn vào quỹ phế (Dòng 30)
    }

    // --- Hàm lấy số liệu cho Thống kê (Dòng 37) ---
    long long getBalance() const { return balance; }
    long long getBankroll() const { return houseBankroll; }
    long long getMaxBet() const { return maxBet; }
};