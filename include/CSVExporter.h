#pragma once

#include "RoundRecord.h"
#include <string>
#include <vector>

using namespace std;

/* QA: why do NOT use `using namespace std`*/
class CSVExporter {
    string path;

  public:
    CSVExporter(const string &);
    void exportToCSV(const vector<RoundRecord> &);
};
