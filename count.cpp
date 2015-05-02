#include <iostream>
using namespace std;

int mouthDay[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

bool is_leap_year(int y)
{
	return ((y % 4 == 0) && ((y % 100 != 0) || (y % 400 == 0)));
}

void set_Feb_day(int i)
{
	if (is_leap_year(i))
		mouthDay[2] = 29;
	else
		mouthDay[2] = 28;
	return ;
}

int count (int y,int m,int d,int y0,int m0,int d0)
{
	int count_day = 0;
	set_Feb_day(y0);
	while((y0 != y)|| (m0 != m)|| (d0 != d))
	{
		++count_day;
		++ d0;
		if (d0 > mouthDay[m0])
		{
			d0 = 1;
			++m0;
		}
		if (m0 > 12)
		{
			m0 = 1;
			++y0;
			set_Feb_day(y0);
		}
	}
}
