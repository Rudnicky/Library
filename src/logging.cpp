#include "logging.h"

Logging::Logging()
{

}

void Logging::loggingIntoTextFile(std::string logText)
{
    std::fstream file;
    file.open("logg.txt", std::ios::in | std::ios::app);
    if (file.good() == true) {
        file << logText;
        file.close();
    } else {
        std::cout << "Access to file has failed!\n";
    }
}

void Logging::openLogFile() const
{
    std::fstream file;
    file.open("logg.txt", std::ios::in | std::ios::out);
    if (file.good() == true) {
        std::string textfileContent;
        std::cout << "log file content: \n\n";
        while(!file.eof()) {
            getline(file, textfileContent);
            std::cout << textfileContent << "\n";
        }
        file.close();
    } else {
        std::cout << "Access to file has failed!\n";
    }
}

void Logging::clearLogFile()
{
    std::ofstream file;
    file.open("logg.txt", std::ofstream::out | std::ofstream::trunc);
    if (file.good() == true) {
        std::cout << "log file cleared...\n";
        file.close();
    } else {
        std::cout << "Access to file has failed!\n";
    }
}
