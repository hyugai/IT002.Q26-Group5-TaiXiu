#pragma once

#include "ABettingStrategy.h"
#include "CSVExporter.h"
#include "Table.h"
#include <functional>
#include <memory>
#include <string>
#include <vector>

using StrategyFactory = std::function<std::unique_ptr<ABettingStrategy>()>;

class SimulationEngine {
    int total_rounds;
    double initial_bankroll;
    double base_bet;
    double max_bet;
    std::vector<std::pair<std::string, StrategyFactory>> strategies;
    std::vector<std::pair<std::string, std::vector<RoundRecord>>> results;

    std::vector<RoundRecord> runOne(StrategyFactory &);

  public:
    SimulationEngine(int, double, double, double);

    void addStrategy(std::string const &, StrategyFactory);
    void run();
    bool exportCSV(std::string const &) const;
};
