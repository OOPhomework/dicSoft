#include "import.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

vector<single_word> import::v(0);
vector<vector<single_word> > import::words_back(3,std::vector<single_word>(0));

void import::init()
{
	ifstream fin(file_name);//must const char*??? to import a value
	if (!fin)
	{
        cout <<"ERROR OPEN WORDS FILE \"new_words_file.txt\""<<endl;
	}
	string line;
	getline (fin,line);
	string store = "";
	int count = 0;
	while (getline(fin,line))
	{
		count++;
		//cout <<"***"<<count<<endl;
		//cout <<line<<endl;
		single_word word_add= print_to_single_word(line);
		v.push_back(word_add);
	}
	fin.close();
}

void import::import_words_file()
{
	const char* FILE[3] = {"familiar_words_file.txt","new_words_file.txt","unstable_words_file.txt"};
	for (int i = 0;i < 3;i++)
	{
		ifstream fin(FILE[i]);
		if (!fin)
		{
			cout <<"sorry ,can't find "<<FILE[i]<<endl;
			ofstream fout(FILE[i]);
			cout <<"Creating "<<FILE[i]<<"......"<<endl;
			cout <<endl;
			continue ;
		}
		string word;
		search_a_word saw;
		while (fin >> word)
		{
			saw.search(word);
			//if ()
			words_back[i].push_back(saw.the_word);
		}
		fin.close();//importent or you'll get wrong
	}
}

string import::check_bracket(std::string line,int& i)
{//may appear the situation "[...[...]...]"
	while(line[i] != '[')
    {
        i++;
    }
	int match = 1;
    int start = ++i;
    int num = 0;
    while(match != 0)
    {
    	//cout <<line[i]<<endl;
        if (line[i] == '['){
        	match++;
        //cout <<match<<endl;
        }
        else if (line[i] == ']'){
        	match--;
        //cout <<match<<endl;
        }
        i++;num++;
    }
    i--;
    string s = line.substr(start,num-1);//string's function substr(int a,int b)
                                    //starting get the string's character from index a ,extract b chars
    return s;
}

single_word import::print_to_single_word(string line)
{
	single_word the_word;
	int count = 0;
	the_word.name = check_bracket(line,count);
	the_word.phonetic_symbol = check_bracket(line,count);

	string s = check_bracket(line,count);
	//int size = 0;
	the_word.part_of_speech = s;

	//cout <<the_word.name<<the_word.part_of_speech<<endl;
	int index = 0;
	while(line[++count] != '}')
	{
		the_word.eg.push_back(check_bracket(line,count));
		//cout <<the_word.eg[0]<<endl;
		for (int i = 0;i < the_word.eg[index].size();i++)
		{
			if (the_word.eg[index][i] == '|')
				the_word.eg[index][i] = ' ';
		}
		index++;
	//cout <<"***"<<endl;
	}
	return the_word;
}

import::~import()
{
	const char* FILE[3] = {"familiar_words_file.txt","new_words_file.txt","unstable_words_file.txt"};
	for (int i =0;i < 3;i++)
	{
		ofstream fout(FILE[i]);
		for (int j = 0;j < words_back[i].size();j++)
		{
			fout << words_back[i][j].name<<endl;
		}
		fout.close();
	}

}
