#pragma once

#include "RoundRecord.h"
#include <string>
#include <vector>
using namespace std;
class CSVExporter {
    string path;

  public:
    CSVExporter(const string &);

    void exportToCSV(const string &strategyName,
                     const vector<RoundRecord> &records,
                     bool writeHeader = false);
};
