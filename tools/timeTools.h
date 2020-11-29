#ifndef TIME_TOOLS_PARAM
#define TIME_TOOLS_PARAM 1

#include<time.h>

char* GetTimeNow(){
    time_t rawtime;
    struct tm * timeinfo;
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    return (char*) asctime(timeinfo);
}



#endif