#include "../h/import.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

vector<single_word> import::v(0);
vector<vector<single_word> > import::words_back(3,std::vector<single_word>(0));

void import::init()
{
	ifstream fin(file_name);
	//system( "echo $PWD" );

	//cout <<file_name<<endl;
	if (!fin)
	{
        cout <<"ERROR OPEN WORDS FILE \"../data/newwords.txt\""<<endl;
	}
	//cout <<"in import init() function..."<<endl;
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
	//cout <<"in init()..."<<endl;
	fin.close();
}

void import::import_words_file()
{
	const char* FILE[3] = {"./data/familiar_words_file.txt",
				"./data/new_words_file.txt",
				"./data/unstable_words_file.txt"};
	for (int i = 0;i < 3;i++)
	{
		ifstream fin(FILE[i]);
		//cout <<"in "<<FILE[i]<<"..."<<endl;
		if (!fin)
		{
			cout <<"sorry ,can't find "<<FILE[i]<<endl;
			ofstream fout(FILE[i]);
			if (fout)
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
			fin >>word; saw.the_word.new_time.year = atoi(word.c_str());
			fin >>word; saw.the_word.new_time.month = atoi(word.c_str());
			fin >>word; saw.the_word.new_time.day = atoi(word.c_str());
			fin >>word; saw.the_word.review_index = atoi(word.c_str());
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
	const char* FILE[3] = {"./data/familiar_words_file.txt",
				"./data/new_words_file.txt",
				"./data/unstable_words_file.txt"};
	for (int i =0;i < 3;i++)
	{
		ofstream fout(FILE[i]);
		for (int j = 0;j < words_back[i].size();j++)
		{
			fout <<words_back[i][j].name
				<<" "<<words_back[i][j].new_time.year
				<<" "<<words_back[i][j].new_time.month
				<<" "<<words_back[i][j].new_time.day
				<<" "<<words_back[i][j].review_index
				<<endl;
			//fout << words_back[i][j].name<<" "<<words_back[i][j].review_index<<endl;
		}
		fout.close();
	}

}
