#ifndef LOGGING_H
#define LOGGING_H
#include <fstream>
#include <iostream>

class Logging
{
public:
    Logging();
    void loggingIntoTextFile(std::string logText);
    void openLogFile() const;
    void clearLogFile();
};

#endif // LOGGING_H
