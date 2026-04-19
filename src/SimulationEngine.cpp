#include "../include/SimulationEngine.h"
#include "../include/Table.h"
#include <cstdlib>
#include <fstream>
#include <random>

using namespace std;

/*
 * @brief Khởi tạo SimulationEngine với các thông số mô phỏng
 * @param totalRounds     Số ván cần chạy cho mỗi chiến thuật
 * @param initialBankroll Vốn ban đầu của người chơi
 * @param baseBet         Mức cược tối thiểu
 * @param maxBet          Mức cược tối đa
 */
SimulationEngine::SimulationEngine(int totalRounds, double initialBankroll,
                                   double baseBet,  double maxBet)
    : totalRounds(totalRounds), initialBankroll(initialBankroll)
    , baseBet(baseBet), maxBet(maxBet)
{}

/*
 * @brief Đăng ký một chiến thuật vào danh sách mô phỏng
 * @param name    Tên chiến thuật (xuất hiện trong cột Strategy của CSV)
 * @param factory Hàm tạo chiến thuật — gọi factory() trả về unique_ptr mới
 */
void SimulationEngine::addStrategy(string const& name, StrategyFactory factory) {
    strategies.emplace_back(name, std::move(factory));
}

/*
 * @brief Chạy toàn bộ mô phỏng
 *
 * Mỗi chiến thuật được chạy riêng với srand(42) ở đầu → cùng chuỗi
 * xúc xắc → so sánh công bằng giữa các chiến thuật.
 */
void SimulationEngine::run() {
    results.clear();
    std::random_device rd;
    unsigned int seed = rd(); // Seed ngẫu nhiên thật từ phần cứng — khác nhau mỗi lần chạy
    for (auto& [name, factory] : strategies) {
        srand(seed); // Cùng seed trong 1 lần chạy → so sánh các chiến thuật vẫn công bằng
        results.emplace_back(name, runOne(factory));
    }
}

/*
 * @brief Chạy mô phỏng cho 1 chiến thuật
 *
 * factory() tạo object chiến thuật mới mỗi lần → state sạch, không bị
 * ảnh hưởng bởi lần chạy trước.
 *
 * @param factory Hàm tạo chiến thuật
 * @return Danh sách RoundRecord của chiến thuật đó
 */
vector<RoundRecord> SimulationEngine::runOne(StrategyFactory& factory) {
    House  house(0.05, baseBet, maxBet);
    Player player(initialBankroll);
    player.setStrategy(factory()); // Gán chiến thuật + tự khởi tạo cược đầu = baseBet

    Table table(house, std::move(player));
    for (int i = 0; i < totalRounds; i++)
        table.play();

    return table.getRecords();
}

/*
 * @brief Xuất kết quả tất cả chiến thuật ra 1 file CSV
 *
 * Format: Strategy, Round, Bet Side, Bet Amount, Result, Bankroll
 *
 * @param filename Tên file CSV đầu ra
 * @return true nếu mở/ghi file thành công
 */
bool SimulationEngine::exportCSV(string const& filename) const {
    ofstream file(filename);
    if (!file.is_open()) return false;

    // Header
    file << "Strategy,Round,Bet Side,Bet Amount,Result,Bankroll\n";

    for (auto const& [name, records] : results) {
        int round = 1;
        for (auto const& r : records) {
            file << name                                               << ","
                 << round++                                           << ","
                 << (r.bet.type == BetType::Xiu ? "Xiu" : "Tai")     << ","
                 << r.bet.dAmount                                     << ","
                 << (r.result == BetResult::Win ? "Win" : "Lose")    << ","
                 << r.dCurrentBankroll                                << "\n";
        }
    }
    return true;
}
