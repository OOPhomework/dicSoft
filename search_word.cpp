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
		 <<"C : Unstable"
		 <<endl;
	char choose;
	cin >> choose;
	if (choose == 'A')
		the_word.lable = LABLE(0);
	else if (choose == 'B')
		the_word.lable = LABLE(1);
	else if (choose == 'C')
		the_word.lable = LABLE(2);//check the lable;
	else
	{
		cout <<"Sorry , error input!"<<endl;
		goto error;
	}
	add_word_back(the_word.lable);
}

void search_a_word::add_word_back(LABLE lable)
{
	const char* out_file;
	string s;
	for (int i = 0;i < 3;i++)
	{
		//		cout <<"***"<<endl;
		for (int j =0;j < import::words_back[i].size();j++)
		{
			//cout <<import::words_back[i][j].name<<endl;
			//cout <<(the_word.name == import::words_back[i][j].name)<<endl;
			if (the_word.name == import::words_back[i][j].name)
			{
				if (int(lable) == i)
				{
					cout <<"You have added the word to word_note!"<<endl;
					return ;
				}
				else if (int(lable) != i)
				{
					///cout <<"***"<<endl;
					//cout <<LABLE(lable);
					import::words_back[i].erase(import::words_back[i].begin()+j);
					continue;
				}
				//remove???
			}
		}
	}
	//cout <<"***"<<endl;
	switch (int(lable))
	{
		case 0:
			import::words_back[0].push_back(the_word);cout <<">>>familiar"<<endl;break;
		case 1:
			import::words_back[1].push_back(the_word);cout <<">>>new"<<endl;break;
		case 2:
			import::words_back[2].push_back(the_word);cout <<">>>unstable"<<endl;break;
	}
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
