#pragma once
#include <string>
#include <vector>
#include "RoundRecord.h"

class CSVExporter {
    std::string sFilename;
public:
    CSVExporter(const std::string& filename);
    void exportToCSV(const std::vector<RoundRecord>& records);
};
