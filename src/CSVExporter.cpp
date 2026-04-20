#include "../include/CSVExporter.h"
#include <fstream>

using namespace std;

/*
 * @brief Constructor — lưu tên file để dùng khi ghi CSV
 *
 * Ví dụ: CSVExporter exporter("results.csv")
 * → path = "results.csv", dùng cho tất cả lần ghi sau đó
 */
CSVExporter::CSVExporter(const string &filename) : path(filename) {}

/*
 * @brief Ghi danh sách kết quả 1 chiến thuật vào file CSV
 *
 * Dùng ios::app để append — nhiều chiến thuật ghi nối tiếp vào cùng 1 file
 * mà không ghi đè nhau. writeHeader chỉ true cho chiến thuật đầu tiên.
 *
 * @param strategyName Tên chiến thuật — xuất hiện ở cột Strategy trong CSV
 * @param records      Danh sách RoundRecord chứa kết quả từng ván
 * @param writeHeader  true → ghi dòng header (chỉ dùng cho chiến thuật đầu tiên)
 */
void CSVExporter::exportToCSV(const string &strategyName,
                               const vector<RoundRecord> &records,
                               bool writeHeader) {
    // writeHeader=true → tạo file mới (ios::out), false → ghi nối tiếp (ios::app)
    ofstream file(path, writeHeader ? ios::out : ios::app);
    if (!file.is_open())
        return;

    if (writeHeader)
        file << "strategy,round,side,amount,result,bankroll\n";

    int round = 1;
    for (const auto &r : records) {
        file << strategyName << ","
             << round++ << ","
             << (r.bet.type == BetType::Xiu ? "Xiu" : "Tai") << ","
             << r.bet.amount << ","
             << (r.result == BetResult::Win ? "Win" : "Lose") << ","
             << r.current_bankroll << "\n";
    }
}
