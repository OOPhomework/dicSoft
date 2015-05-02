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
	friend ostream& operator<< (ostream &os,const single_word T&);
	~single_word();
private:
	string phonetic_symbol;//yinbiao
	string part_of_speech;//cixing
	string paraphrase;//shiyi
	string eg;
	LABLE lable;
	int time;

};

ostream& operator<< (ostream &os,const single_word T&);

#endif
