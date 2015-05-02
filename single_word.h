#ifndef SINGLE_WORD_H
#define SINGLE_WORD_H

#include "mnemonic.h"
#include "file_operator.h"
#include <iostream>
#include <cstring>
enum LABLE{
	familiar_word,
	new_word,
	unstable_word
}
class single_word
{
public:
	single_word();
	int current_time();//return current time;
	void get_relative_map();
	void set_lable();
	friend std::ostream& operator<< (std::ostream &os,const single_word T&);
	~single_word();
private:
	std::string phonetic_symbol;//yinbiao
	std::string part_of_speech;//cixing
	std::string paraphrase;//shiyi
	std::string eg;
	LABLE lable;
	int time;

};

std::ostream& operator<< (std::ostream &os,const single_word T&);

#endif
