#ifndef IMPORT_H
#define IMPORT_H
#include "single_word.h"
#include "search_word.h"
#include <string>
#include <vector>

class import
{
public:
	import(const char* file):file_name(file){}
	void init();
	void import_words_file();
	~import();

	static std::vector<single_word> v;
	static std::vector< std::vector<single_word> > words_back;
	//familiar_words_file.txt,new_words_file.txt,unstable_words_file.txt
private:
	std::string check_bracket(std::string line,int& i);
	single_word print_to_single_word(std::string);

	const char* file_name;
};


#endif //IMPORT_H
