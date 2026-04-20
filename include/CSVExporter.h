#pragma once

#include "RoundRecord.h"
#include <string>
#include <vector>
using namespace std;
class CSVExporter {
    string path;

  public:
    CSVExporter(const string &);

    void exportToCSV(const string &, const vector<RoundRecord> &, bool = false);
};
