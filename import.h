#ifndef IMPORT_H
#define IMPORT_H
#include "single_word.h"
#include <string>
#include <vector>

class import
{
public:
	import(const char* file):file_name(file){}
	void init();
	std::string check_bracket(std::string line,int& i);
	single_word print_to_single_word(std::string);
	~import(){}
	static std::vector<single_word> v;
private:
	const char* file_name;
};


#endif //IMPORT_H