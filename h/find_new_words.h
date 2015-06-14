#ifndef __find_new_words__find_new_words__
#define __find_new_words__find_new_words__

//#include <stdio.h>
//#include "import.h"
//#include "search_word.h"
#include <iostream>
#include <string>
//#include <cstring>
#include <fstream>
#include <vector>
class find_words_from_a_file
{
public:
	find_words_from_a_file(const char* a);
	~find_words_from_a_file();
    //void open_file();
    void read_file();
    bool is_letter(char a);
   // bool is_symble(const char& a);
    void clear(std :: string& s);
	void find_words();
    void fuckyou();
	void print()
	{
		for(int i = 0; i < v2.size(); i ++)
		{
			std :: cout << v2[i] << " ";
		}
		std :: cout << std :: endl;
	}
	//std :: ifstream infile(std :: string);
private:
	const char* file_name;
	std :: vector<std :: string> v2;
	std :: string store;
	std :: string the_whole_file;
	std :: string words_from_English_file;
};

#endif /* defined(__find_new_words__find_new_words__) */
