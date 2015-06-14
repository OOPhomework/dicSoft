#include "../h/find_new_words.h"
#include "../h/import.h"
#include <string>
#include <iostream>
#include <cstring>
#include <fstream>
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
        std :: cout << "Error when open the English file!" << std :: endl;
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
		if(the_whole_file[i + 1] == '\n')
		{
			v2.push_back(words_from_English_file);
		}
    }
    int count_index[v2.size()];
    for(int i = 0; i < v2.size(); i += 1)
        count_index[i] = -1;
    int a = 0;
    for(int i = 0; i < v2.size(); i += 1)
    {
        for(int j = (v2.size() - 1); j > i; j -= 1)
        {
            if(v2[i] == v2[j])
            {
                count_index[a] = i;
                a += 1;
            }
        }
    }
    int b = 0;
    while(count_index[b] != -1)
        b += 1;
    for(int i = b - 1; i >= 0; i -= 1)
    {
        v2.erase(v2.begin() + count_index[i]);
    }
}
find_words_from_a_file :: ~find_words_from_a_file()
{
	//
}

void find_words_from_a_file :: fuckyou()
{
    std :: ifstream fin("new_words_file.txt");
    if(!fin)
    {
        std :: cout << "Error when open the new_words_file.txt!" << std :: endl;
        return;
    }
    std :: ofstream fout("new_words_in_file");
    fout << "The new words in the file: " << std :: endl;
    if(!fout)
    {
        std :: cout << "Error when open the new_words_in_file.txt!" << std :: endl;
        return;
    }
    std :: cout << "The new words in the English file: " << std :: endl;
    for(int i = 0; i < v2.size(); i += 1)
    {
        for(int j = 0; j < import :: words_back[1].size(); j += 1)
        {
            if(v2[i] == import :: words_back[1][j].name)
            {
                //std :: cout << i << " " << v2[i] << " = " << words_back[1][j].name << std :: endl;
                std :: cout << import :: words_back[1][j] << std :: endl;
                fout << import :: words_back[1][j] << std :: endl;
            }
        }
    }
    fout << "The unstable words in the file: " << std :: endl;
    std :: ifstream fin2("unstable_words_file.txt");
    if(!fin2)
    {
        std :: cout << "Error when open the unstable_words_file.txt!" << std :: endl;
        return;
    }
    std :: cout << "The unstable words in the English file: " << std :: endl;
    for(int i = 0; i < v2.size(); i += 1)
    {
        for(int j = 0; j < import :: words_back[2].size(); j += 1)
        {
            if(v2[i] == import :: words_back[2][j].name)
            {
                //std :: cout << i << " " << v2[i] << " = " << words_back[1][j].name << std :: endl;
                std :: cout << import :: words_back[2][j] << std :: endl;
                fout << import :: words_back[2][j] << std :: endl;
            }
        }
    }
}
