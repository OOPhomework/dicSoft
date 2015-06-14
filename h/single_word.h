#ifndef SINGLE_WORD_H
#define SINGLE_WORD_H

//#include "mnemonic.h"
//#include "file_operator.h"
//#include "mnemonic.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <vector>

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
	count(){}
	void day_count(date,int);
	bool is_leap_year(int);
	void set_Feb_day(int);
	~count(){}
	date next_time;
private:
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
	single_word(){}
	void current_time();//return current time;
	void get_next_time(int review_index);//get the deadline of review;
	//void get_relative_map();
	//void set_question();
	friend std::ostream& operator<< (std::ostream &os,const single_word& T);
    friend std :: ofstream& operator<< (std :: ofstream& fs, const single_word& T);
    friend class find_words_from_a_file;
	friend class word_back;
	friend class search_a_word;
	friend class import;
	friend class mnemonic;
	friend class set_question;
	friend class check_review_time;
	~single_word(){}
private:
	std::string name;
	std::string phonetic_symbol;//yinbiao
	std::string part_of_speech;
	//std::vector<std::string> part_of_speech; //cixing
	//std::vector<std::string> paraphrase;//shiyi
	std::vector<std::string> eg;
	LABLE lable;

	count count_day;
	date now_time;//year,mouth,day
	date new_time;
	int review_index;
};

std::ostream& operator<< (std::ostream &os,const single_word& T);
std :: ofstream& operator<< (std :: ofstream& fs, const single_word& T);
#endif





