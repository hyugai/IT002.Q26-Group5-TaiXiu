#include <iostream>
#include <string>
#include <vector>
#include "../include/SimulationEngine.h"
#include "../include/Martingale.h"
#include "../include/Paroli.h"
#include "../include/Fibonacci.h"

using namespace std;

int main() {
    cout << "===== TAI XIU SIMULATION =====" << endl;

    // Nhập thông số mô phỏng từ người dùng
    int rounds;
    double bankroll, minBet, maxBet;

    cout << "Nhap so van choi: ";    cin >> rounds;
    cout << "Nhap von ban dau: ";    cin >> bankroll;
    cout << "Nhap minBet: ";         cin >> minBet;
    cout << "Nhap maxBet: ";         cin >> maxBet;

    // ── Danh sách chiến thuật hiện có ─────────────────────────────
    // Thêm chiến thuật mới: bỏ comment hoặc thêm dòng mới vào đây.
    // Menu sẽ tự động hiển thị thêm, không cần sửa code khác.
    vector<pair<string, StrategyFactory>> availableStrategies = {
        {"Martingale", [minBet] { return make_unique<Martingale>(minBet); }},
        {"Paroli",     [minBet] { return make_unique<Paroli>(minBet, 3); }},
        {"Fibonacci",  [minBet] { return make_unique<Fibonacci>(minBet); }},
        // {"TenChienThuat", [minBet] { return make_unique<TenChienThuat>(minBet); }},
    };
    // ──────────────────────────────────────────────────────────────

    SimulationEngine engine(rounds, bankroll, minBet, maxBet);

    // Nhập số lượng player và chiến thuật từng người
    int numPlayers;
    cout << "\nNhap so luong player: ";
    cin >> numPlayers;

    // Hiển thị danh sách chiến thuật động — tự cập nhật khi thêm chiến thuật mới
    cout << "\nCac chien thuat hien co:" << endl;
    for (int i = 0; i < (int)availableStrategies.size(); i++)
        cout << "  " << i + 1 << ". " << availableStrategies[i].first << endl;

    for (int i = 1; i <= numPlayers; i++) {
        int choice;
        cout << "Player " << i << " chon (1-" << availableStrategies.size() << "): ";
        cin >> choice;
        choice--; // Chuyển về 0-index

        // Nếu nhập sai thì dùng chiến thuật đầu tiên mặc định
        if (choice < 0 || choice >= (int)availableStrategies.size()) {
            cout << "  Khong hop le, dung " << availableStrategies[0].first << " mac dinh." << endl;
            choice = 0;
        }

        // Tên player = "PlayerN_TenChienThuat" để dễ đọc trong CSV
        string name = "Player" + to_string(i) + "_" + availableStrategies[choice].first;
        engine.addStrategy(name, availableStrategies[choice].second);
    }

    cout << "\nDang chay mo phong..." << endl;
    engine.run();

    if (engine.exportCSV("results.csv"))
        cout << "Xuat CSV thanh cong: results.csv" << endl;
    else
        cout << "Xuat CSV that bai!" << endl;

    return 0;
}
