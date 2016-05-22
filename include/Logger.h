#ifndef LOGGER_H
#define LOGGER_H


#include <fstream>
#include <ctime>
#include <string>
#include <iostream>
class Logger
{
public:
    Logger();
    void logwrite(const char* file, const char* func, const int line, const char* name, const auto value)
    {

        log<<file<<" ";
        log<<func<< " ";
        log<<line;
        log<<" ";
        log<<name<<"=";
        log<<value;
        log<<std::endl;

    }
    void show()
    {
        std::cout<<"i`m live";
    };
    ~Logger()
    {
        log.close();
    };


private:
    std::ofstream log;
};

#endif // LOGGER_H
