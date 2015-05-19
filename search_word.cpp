#include "search_word.h"
#include "import.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void search_a_word :: search(std :: string word)
{
	can_find = true;
	for (int i = 0;i < import::v.size();i++)
	{
		if (import::v[i].name == word)
		{
			the_word = import::v[i];
			return ;
		}
	}
	can_find = false;
	return ;
}

void search_a_word :: print()
{
	if (can_find)
		cout <<the_word<<endl;
	else
	{
		cout <<">Sorry , can't find this word!\n"
			<<">May be you should add another thesaurus"
			<<endl;
		can_find = true;
	}
}
