#include "single_word.h"
#include "count.cpp"
#include <iostream>
#include <ctime>

int current_time()
{
	time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    //now-> tm_year return this year's number delete 1900;
    //now-> tm_mou return mouth;
    //now-> tm_mday return day's number;
    //we can caculate the day through to come true the time count;
}
