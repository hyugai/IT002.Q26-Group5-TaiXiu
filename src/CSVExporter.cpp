#include "../include/CSVExporter.h"
#include <fstream>

using namespace std;

/* *
 * @brief Constructor — lưu tên file để dùng khi ghi CSV
 * @param filename path dẫn tới file
 * */
CSVExporter::CSVExporter(const string &filename) : path(filename) {}

/*
 * @brief Ghi danh sách kết quả 1 chiến thuật vào file CSV
 *
 * @param strategyName Tên chiến thuật — xuất hiện ở cột Strategy trong CSV
 *
 * @param records      Danh sách RoundRecord chứa kết quả từng ván
 *
 * @param writeHeader  true → ghi dòng header (chỉ dùng cho chiến thuật đầu
 * tiên)
 */
void CSVExporter::exportToCSV(const string &strategy_name,
                              const vector<RoundRecord> &records,
                              bool write_header) {

    ofstream file(
        path,
        write_header
            ? ios::out
            : ios::app); //  Dùng ios::app để append — nhiều chiến thuật ghi nối
                         //  tiếp vào cùng 1 file mà không ghi đè nhau.

    if (!file.is_open())
        return;

    if (write_header) // writeHeader chỉ true cho chiến thuật đầu tiên.
        file << "strategy,round,side,amount,result,bankroll\n";

    int round = 1;
    for (const auto &r : records) {
        file << strategy_name << "," << round++ << ","
             << (r.bet.type == BetType::Xiu ? "Xiu" : "Tai") << ","
             << r.bet.amount << ","
             << (r.result == BetResult::Win ? "Win" : "Lose") << ","
             << r.current_bankroll << "\n";
    }
}
