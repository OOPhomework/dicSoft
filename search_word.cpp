#include "search_word.h"
#include "import.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
enum LABLE;

bool search_a_word :: search(std :: string word)
{
	can_find = true;
	for (int i = 0;i < import::v.size();i++)
	{
		if (import::v[i].name == word)
		{
			the_word = import::v[i];
			return can_find;
		}
	}
	can_find = false;
	return can_find;
}

void search_a_word::set_lable()
{
	error : cout <<"Please check a lable for the word : "<<endl;
	cout <<"A : Familiar\n"
		 <<"B : New     \n"
		 <<"C : Unstable\n"
		 <<endl;
	char choose;
	cin >> choose;
	if (choose == 'A')
		the_word.lable = LABLE(0);
	else if (choose == 'B')
		the_word.lable = LABLE(1);
	else if (choose == 'c')
		the_word.lable = LABLE(2);//check the lable;
	else
	{
		cout <<"Sorry , error input!"<<endl;
		goto error;
	}
	output_file(the_word.lable);
}

void search_a_word::output_file(LABLE lable)
{
	const char* out_file;
	string s;
	if (lable == 0)
	{
		out_file = "familiar_words_file.txt";
	}
	else if(lable == 1)
	{
		out_file = "new_words_file.txt";
	}
	else if (lable == 2)
	{
		out_file = "unstable_words_file.txt";
	}
	else
	{
		cout <<"error LABLE lable!!!"<<endl;
	}

	ofstream fout(const_cast<const char*>(out_file));
	fout <<'['<<the_word.name<<']'<<endl;
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
