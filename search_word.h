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
	bool search(std :: string word);
	void set_lable();	
	void print();
	//void print_to_single_word(std::string line,int pos);
	friend class import;
private:
	void add_word_back(LABLE);
	
	single_word the_word;
	std :: string store;
	bool can_find;
};







#endif // SEARCH_WORD_H
