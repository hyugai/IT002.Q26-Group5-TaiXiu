#include "../include/SimulationEngine.h"
#include "../include/Table.h"
#include <cstdlib>
#include <fstream>

using namespace std;

/*
 * @brief Khởi tạo SimulationEngine với các thông số mô phỏng
 * @param total_rounds     Số ván cần chạy cho mỗi chiến thuật
 * @param initial_bankroll Vốn ban đầu của người chơi
 * @param base_bet         Mức cược tối thiểu
 * @param max_bet          Mức cược tối đa
 */
SimulationEngine::SimulationEngine(int total_rounds, double initial_bankroll,
                                   double base_bet, double max_bet)
    : total_rounds(total_rounds), initial_bankroll(initial_bankroll),
      base_bet(base_bet), max_bet(max_bet) {}

/*
 * @brief Đăng ký một chiến thuật vào danh sách mô phỏng
 * @param name    Tên chiến thuật (xuất hiện trong cột Strategy của CSV)
 * @param factory Hàm tạo chiến thuật — gọi factory() trả về unique_ptr mới
 */
void SimulationEngine::addStrategy(string const &name,
                                   StrategyFactory factory) {
    strategies.emplace_back(name, std::move(factory));
}

/* *
 * @brief Chạy toàn bộ mô phỏng
 *
 * Mỗi chiến thuật được chạy riêng với srand(42) ở đầu → cùng chuỗi
 * xúc xắc → so sánh công bằng giữa các chiến thuật.
 * */
void SimulationEngine::run() {
    results.clear();
    for (auto &[name, factory] : strategies) {
        srand(42); // Reset seed để mỗi chiến thuật đối mặt cùng chuỗi xúc xắc
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
vector<RoundRecord> SimulationEngine::runOne(StrategyFactory &factory) {
    House house(0.05, base_bet, max_bet);
    Player player(initial_bankroll);
    player.setStrategy(factory()); // Gán chiến thuật mới
    player.placeBet(
        BetResult::Win); // Tính cược đầu tiên (giả sử ván trước thắng)

    Table table(house, std::move(player));
    for (int i = 0; i < total_rounds; i++)
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
bool SimulationEngine::exportCSV(string const &filename) const {
    ofstream file(filename);
    if (!file.is_open())
        return false;

    file << "strategy,round,side,amount,result,bankroll\n";

    for (auto const &[name, records] : results) {
        int round = 1;
        for (auto const &r : records) {
            file << name << "," << round++ << ","
                 << (r.bet.type == BetType::Xiu ? "Xiu" : "Tai") << ","
                 << r.bet.amount << ","
                 << (r.result == BetResult::Win ? "Win" : "Lose") << ","
                 << r.current_bankroll << "\n";
        }
    }
    return true;
}
