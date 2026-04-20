#include "../include/SimulationEngine.h"
#include "../include/Table.h"
#include <cstdlib>
#include <random>

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
 * Mỗi chiến thuật dùng cùng seed (sinh từ random_device) → cùng chuỗi xúc
 * xắc → so sánh công bằng. Seed thay đổi mỗi lần chạy chương trình.
 * */
void SimulationEngine::run() {
    results.clear();
    unsigned int seed = std::random_device{}();
    for (auto &[name, factory] : strategies) {
        srand(seed); // Cùng seed trong 1 lần chạy → so sánh các chiến thuật vẫn
                     // công bằng
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
    player.setStrategy(
        factory()); // Gán chiến thuật + tự khởi tạo cược đầu = base_bet

    Table table(house, std::move(player));
    for (int i = 0; i < total_rounds; i++)
        table.play();

    return table.getRecords();
}

/*
 * @brief Xuất kết quả tất cả chiến thuật ra 1 file CSV
 *
 * Chiến thuật đầu tiên ghi header, các chiến thuật sau append vào file.
 *
 * @param filename Tên file CSV đầu ra
 * @return true nếu mở/ghi file thành công
 */
bool SimulationEngine::exportCSV(string const &file_name) const {
    CSVExporter exporter(file_name);
    bool first = true;
    for (auto const &[name, records] : results) {
        exporter.exportToCSV(name, records,
                             first); // first=true → ghi header lần đầu
        first = false;
    }
    return true;
}
