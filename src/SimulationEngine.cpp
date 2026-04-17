#include "../include/SimulationEngine.h"
#include "../include/Table.h"

using namespace std;

SimulationEngine::SimulationEngine(int totalRounds, double initialBankroll,
                                   double baseBet,  double maxBet)
    : totalRounds(totalRounds), initialBankroll(initialBankroll)
    , baseBet(baseBet), maxBet(maxBet)
{}

void SimulationEngine::run() {
    Table table(initialBankroll, baseBet, maxBet);
    for (int i = 0; i < totalRounds; i++) {
        table.play();
    }
    roundRecords = table.getRecords();
}

bool SimulationEngine::exportToCSV(string const& filename) const {
    CSVExporter exporter(filename);
    exporter.exportToCSV(roundRecords);
    return true;
}

vector<RoundRecord> const& SimulationEngine::getRoundRecords() const {
    return roundRecords;
}
