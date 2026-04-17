#include "../include/CSVExporter.h"
#include <fstream>

using namespace std;

CSVExporter::CSVExporter(const string& filename) : sFilename(filename) {}

void CSVExporter::exportToCSV(const vector<RoundRecord>& records) {
    ofstream file(sFilename);
    if (!file.is_open()) {
        return;
    }

    file << "Bet Side,Bet Amount,Result,Current Bankroll\n";

    for (const auto& record : records) {
        file << (record.bet.type == BetType::Xiu ? "Xiu" : "Tai") << ","
             << record.bet.dAmount                                  << ","
             << (record.result == BetResult::Win ? "Win" : "Lose") << ","
             << record.dCurrentBankroll                             << "\n";
    }

    file.close();
}
