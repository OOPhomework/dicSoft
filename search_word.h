#ifndef SEARCH_WORD_H
#define SEARCH_WORD_H
#include "single_word.h"
#include <string>
#include <fstream>
#include <iostream>
class search_a_word
{
private:
	single_word a_word;
	std :: string store;
public:
	search_a_word() {}
	~search_a_word() {}
	int search(std :: string word);
	void print_to_single_word(int position);
};







#endif // SEARCH_WORD_H
