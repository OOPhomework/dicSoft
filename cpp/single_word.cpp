#include "../h/single_word.h"
#include <iostream>
#include <ctime>
using namespace std;
//#include <cstring>
//-------------------------------count----------------------------------------

int REVIEW_DAY = 30;
int monthDay[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

bool count::is_leap_year(int y)
{
	return ((y % 4 == 0) && ((y % 100 != 0) || (y % 400 == 0)));
}

void count::set_Feb_day(int i)
{
	if (is_leap_year(i))
		monthDay[2] = 29;
	else
		monthDay[2] = 28;
	return ;
}

void count::day_count (date t0)
{
	int count_day = 0;
	set_Feb_day(t0.year);
	while(count_day < REVIEW_DAY)
	{
		++count_day;
		++ t0.day;
		if (t0.day > monthDay[t0.month])
		{
			t0.day = 1;
			++t0.month;
		}
		if (t0.month > 12)
		{
			t0.month = 1;
			++t0.year;
			set_Feb_day(t0.year);
		}
	}
	next_time.year = t0.year;
	next_time.month = t0.month;
	next_time.day = t0.day;
	return ;
}
//-----------------------single_word-------------------------------------------

void single_word::current_time()
{
	time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    now_time.year = now->tm_year;
    now_time.month = now->tm_mon;
    now_time.day = now->tm_mday;
    //now-> tm_year return this year's number delete 1900;
    //now-> tm_mon return mouth;
    //now-> tm_mday return day's number;
    //we can caculate the day through to come true the time count;
}

void single_word::get_next_time()
{
	current_time();
	count_day.day_count(now_time);
	new_time.year = count_day.next_time.year;
	new_time.month = count_day.next_time.month;
	new_time.day = count_day.next_time.day;
}

void single_word::get_relative_map()
{

}

/*void set_question()
{
    cout <<name<<" : "<<endl;
    if
}*/

ostream& operator<< (ostream &os,const single_word& T)
{
	os <<">WORD			"<<T.name
		<<" [/"<<T.phonetic_symbol<<"/]"
		<<" : "<<endl;
	os <<">part_of_speech 	"<<T.part_of_speech<<endl;
	os<<">eg:"<<endl;
	for (int i = 0;i < T.eg.size()-1;i++)
	{
		os <<">			"<<T.eg[i]<<endl;
	}
	os <<">			"<<T.eg[T.eg.size()-1];
	return os;
}
