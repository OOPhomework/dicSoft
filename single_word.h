#ifndef SINGLE_WORD_H
#define SINGLE_WORD_H

#include "mnemonic.h"
#include "file_operator.h"
#include <iostream>
#include <cstring>

//----------------------------class count & relative----------------------------------
struct date
{
	int year;
	int month;
	int day;
};

class count
{
public:
	count();
	bool is_leap_year(int);
	void set_Feb_day(int);
	void day_count(date);
	~count();
	date next_time;
};

//---------------------class single_word & relative-----------------------------------
enum LABLE{
	familiar_word,
	new_word,
	unstable_word 
};

class single_word
{
public:
	single_word(){};
	void current_time();//return current time;
	void get_next_time();//get the deadline of review;
	void get_relative_map();
	void set_lable();
	friend std::ostream& operator<< (std::ostream &os,const single_word& T);
	~single_word(){};
private:
	std::string name;
	std::string phonetic_symbol;//yinbiao
	std::string part_of_speech;//cixing
	std::string paraphrase;//shiyi
	std::string eg;
	LABLE lable;

	count count_day;
	date now_time;//year,mouth,day
	date new_time;
};

std::ostream& operator<< (std::ostream &os,const single_word& T);

#endif
