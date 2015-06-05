#include "find_new_words.h"
#include <string>
#include <iostream>
#include <cstring>
bool find_words_from_a_file :: is_letter(char a)
{
	return ('a' <= a && a <= 'z') || ('A' <= a && a <= 'Z');
}

void find_words_from_a_file :: clear(std::string &s)
{
    s = "";
}
find_words_from_a_file :: find_words_from_a_file(const char* a)
{
	file_name = a;
	std :: ifstream infile(file_name.c_str());
	//std::cout << "fuck" << std::endl;
	if(!infile)
    {
        std :: cout << "Error when open the file!" << std :: endl;
    }
	store = "";
	the_whole_file = "";
	words_from_English_file = "";
	infile.close();
}
void find_words_from_a_file :: read_file()
{
	std :: ifstream infile(file_name.c_str());
	while(getline(infile, store))
	{
		the_whole_file += store;
	}
	infile.close();
}
void find_words_from_a_file :: find_words()
{
	for(int i = 0; i < the_whole_file.size(); i += 1)
    {    
		if(is_letter(the_whole_file[i]))
        {
			words_from_English_file += the_whole_file[i];
        }
        else if(the_whole_file[i] == '-')
            continue;
		else
		{
			if(words_from_English_file != "")
				v2.push_back(words_from_English_file);
            clear(words_from_English_file);
		}
		if(the_whole_file[i + 1] == NULL)
		{
			v2.push_back(words_from_English_file);
		}
    }
}
find_words_from_a_file :: ~find_words_from_a_file()
{
	//
}
