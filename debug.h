#if 1
#include "Logger.h"
extern Logger xman;

#define LOG(name, value) xman.logwrite(__FILE__, __func__, __LINE__, name, value);

#else
   #define LOG(name,value) /**/
#endif // TRUE
