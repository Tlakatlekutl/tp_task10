#include "Logger.h"

Logger xman;

/*void Logger::logwrite(const char* file, const char* func, const int line, const auto value)
{
    log<<file<<" ";
    log<<func<< " ";
    log<<line;
    log<<" ";
    log<<value;
    log<<std::endl;
}*/
Logger::Logger()
{
    char name[80];
    time_t seconds = time(NULL);
    tm* timeinfo = localtime(&seconds);
    char* format = "%d_%Y_%I_%M_%S.log";
    strftime(name,80, format, timeinfo);
    try
    {
        log.open(name);
    }
    catch(...)
    {
        std::cout << "Ошибка сохдания лог-файла."<<std::endl;
    }
}
