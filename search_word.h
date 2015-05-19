#ifndef SEARCH_WORD_H
#define SEARCH_WORD_H
#include "single_word.h"
#include "import.h"
#include <string>
#include <fstream>

class search_a_word
{
public:
	search_a_word() {}
	~search_a_word() {}
	void search(std :: string word);
	void print();
	//void print_to_single_word(std::string line,int pos);
private:
	single_word the_word;
	std :: string store;
	bool can_find;
};







#endif // SEARCH_WORD_H
