// CopyRight 2024 Harishwar Reddy Erri

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <boost/regex.hpp>
#include "boost/date_time/posix_time/posix_time.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using boost::regex;
using boost::smatch;
using boost::regex_error;
using boost::gregorian::date;
using boost::gregorian::from_simple_string;
using boost::gregorian::date_period;
using boost::gregorian::date_duration;
using boost::posix_time::ptime;
using boost::posix_time::time_duration;

struct BootService {
    string serviceName;
    ptime bootStartTime;
    ptime bootEndTime;
};

int main(int argc, char** argv) {
    if (argc != 2) {
        cout << "usage: ./boot_report [logfile]" << endl;
        exit(1);
    }

    string logLine, logFileName(argv[1]);
    regex startPattern, successPattern;
    bool isBooting = false;

    std::ifstream logFile(logFileName);
    std::stringstream reportContent;

    if (!logFile) {
        cout << "Error opening file" << endl;
        exit(1);
    }

    try {
        startPattern = regex(R"((.*): (\(log.c.166\) server started.*))");
        successPattern =
        regex("(.*)\\.\\d*:INFO:oejs.AbstractConnector:Started "
                               "SelectChannelConnector@0.0.0.0:9080.*");
    } catch (regex_error& e) {
        cout << "Regex initialization failed: " << e.code() << endl;
        exit(1);
    }

    std::vector<BootService> bootServices;
    int lineNumber = 0;
    int initiatedBoots = 0;
    int completedBoots = 0;

    while (getline(logFile, logLine)) {
        lineNumber++;
        if (regex_match(logLine, startPattern)) {
            smatch matchResult;
            regex_match(logLine, matchResult, startPattern);
            if (isBooting) {
                reportContent << "**** Incomplete boot ****" << endl << endl;
            }
            isBooting = true;
            initiatedBoots++;

            BootService bootService;
            bootService.serviceName = matchResult[2];
            bootService.bootStartTime =
            ptime(boost::posix_time::time_from_string(matchResult[1]));
            bootServices.push_back(bootService);

            reportContent << "=== Device boot ===" << endl;
            reportContent << lineNumber << "(" << logFileName << "): "
                          << matchResult[1] << " Boot Start" << endl;
        }

        if (regex_match(logLine, successPattern)) {
            smatch matchResult;
            regex_match(logLine, matchResult, successPattern);
            if (!bootServices.empty()) {
                BootService& lastService = bootServices.back();
                lastService.bootEndTime =
                ptime(boost::posix_time::time_from_string(matchResult[1]));
                reportContent << lineNumber << "(" << logFileName << "): "
                              << matchResult[1] << " Boot Completed" << endl;
                reportContent << "\tBoot Time: "
                              << (lastService.bootEndTime -
                              lastService.bootStartTime)
                              .total_milliseconds()
                              << "ms" << endl << endl;
                completedBoots++;
            }
            isBooting = false;
        }
    }

    if (isBooting) {
        reportContent << "**** Incomplete boot ****" << endl << endl;
    }

    logFile.close();

    // Write the report to a file
    std::ofstream reportFile(logFileName + ".rpt");
    if (!reportFile) {
        cout << "Error creating report file" << endl;
        exit(1);
    }

    reportFile << "Device Boot Report" << endl << endl;
    reportFile << "InTouch log file: " << logFileName << endl;
    reportFile << "Lines Scanned: " << lineNumber << endl << endl;
    reportFile << "Device boot count: initiated = " << initiatedBoots
               << ", completed: " << completedBoots << endl << endl;
    reportFile << reportContent.str();

    reportFile.close();
    return 0;
}
