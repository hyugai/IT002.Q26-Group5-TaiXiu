#pragma once

#include "ABettingStrategy.h"
#include "CSVExporter.h"
#include "Table.h"
#include <functional>
#include <memory>
#include <string>
#include <vector>

/* QA:fix comment */

/*
 * @brief Hàm tạo chiến thuật — trả về một unique_ptr<ABettingStrategy> mới
 *
 * Dùng std::function để mỗi lần gọi factory() tạo ra một object chiến thuật
 * hoàn toàn mới (fresh state), tránh tái sử dụng state giữa các lần chạy.
 */
using StrategyFactory = std::function<std::unique_ptr<ABettingStrategy>()>;

/*
 * @brief Quản lý và chạy mô phỏng nhiều chiến thuật cược
 *
 * Mỗi chiến thuật được chạy độc lập với cùng seed srand(42) để đảm bảo chuỗi
 * xúc xắc giống nhau → so sánh công bằng.
 */
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
