#pragma once
#include "Table.h"
#include "CSVExporter.h"
#include <string>

struct SimulationEngine {
    SimulationEngine(int totalRounds, double initialBankroll,
                     double baseBet,  double maxBet);
    void run();
    bool exportToCSV(std::string const& filename) const;
    std::vector<RoundRecord> const& getRoundRecords() const;

private:
    int    totalRounds;
    double initialBankroll;
    double baseBet;
    double maxBet;

    std::vector<RoundRecord> roundRecords;
};
