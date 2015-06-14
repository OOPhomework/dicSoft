#include "../h/search_word.h"
#include "../h/import.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
enum LABLE;

int search_a_word :: search(std :: string word_name)
{
	can_find = -1;
	for (int i = 0;i < import::v.size();i++)
	{
		if (import::v[i].name == word_name)
		{
            //cout <<i<<endl;
			the_word = import::v[i];
			can_find = i;
		}
	}
	return can_find;
}

void search_a_word::set_lable()
{
	error : cout <<"Please check a lable for the word : "<<endl;
	cout <<"A:Familiar  "
		 <<"B:New       "
		 <<"C:Unstable  " 
		 <<endl;
	char choose;
	cin >> choose;
    choose = (char)toupper(choose);//*************upper character
	if ((choose == 'B')||(choose == 'C'))
	{
		the_word.review_index = 0;
	}
	if (choose == 'A')
		the_word.lable = LABLE(0);
	else if (choose == 'B'){
		the_word.lable = LABLE(1);
		the_word.get_next_time(the_word.review_index);////////////////////////
	}
	else if (choose == 'C'){
		the_word.lable = LABLE(2);//check the lable;
		the_word.get_next_time(the_word.review_index);////////////////////////
	}
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
	if (can_find != -1){
		cout <<"********************SEARCH BERIN********************"<<endl;//25 front * ,15 back *
		cout <<the_word<<endl;
		mnemonic mne(the_word.name);
		//cout << "mne._creat" << endl;
		mne._creat();
		cout <<"*********************SEARCH END*********************"<<endl;
	}
	else
	{
		cout <<">Sorry , can't find this word!\n"
			 <<">May be you should add another thesaurus"
			 <<endl;
		can_find = -1;
	}
}
