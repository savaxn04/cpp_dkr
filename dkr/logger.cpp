#include <iostream>
#include <vector>
#include <fstream>

// Клас для логування
class Logger {
    std::ofstream logFile;
public:
    Logger(const std::string& filename) {
        logFile.open(filename, std::ios::out | std::ios::app);
    }
    ~Logger() {
        if (logFile.is_open()) {
            logFile.close();
        }
    }
    void log(const std::string& message) {
        logFile << message << std::endl;
    }
};