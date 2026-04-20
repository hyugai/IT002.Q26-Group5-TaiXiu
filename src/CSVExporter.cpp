#include "../include/CSVExporter.h"
#include <fstream>

using namespace std;

/* *
 * @brief Khởi tạo CSVExporter với tên file đầu ra
 * @param s Đường dẫn tới file output
 * */
CSVExporter::CSVExporter(const string &s) : path(s) {}

/* *
 * @brief Ghi toàn bộ danh sách kết quả các ván chơi ra file CSV
 * @param records Danh sách RoundRecord chứa thông tin từng ván
 * @return void
 * */
void CSVExporter::exportToCSV(const vector<RoundRecord> &records) {
    ofstream file(path);
    if (!file.is_open()) {
        return;
    }

    file << "side,amount,result,current_bankroll\n";

    for (const auto &record : records) {
        file << (record.bet.type == BetType::Xiu ? "xiu" : "tai") << ","
             << record.bet.amount << ","
             << (record.result == BetResult::Win ? "win" : "lose") << ","
             << record.current_bankroll << "\n";
    }

    file.close();
}
