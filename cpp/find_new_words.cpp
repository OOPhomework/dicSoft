#include "../h/find_new_words.h"
#include "../h/import.h"
#include <string>
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
bool find_words_from_a_file :: is_letter(char a)
{
	return ('a' <= a && a <= 'z') || ('A' <= a && a <= 'Z');
}

/*void find_words_from_a_file :: clear(std::string &s)
{
    s = "";
}*/
find_words_from_a_file :: find_words_from_a_file(const char* a)
{
	vector<string> v2(0);
	file_name = a;
	std :: ifstream infile(file_name);
	//std::cout << "fuck" << std::endl;
	if(!infile)
    {
        std :: cout << ">Error when open the English file: " <<file_name<<"!"<< std :: endl;
    }
	store = "";
	the_whole_file = "";
	words_from_English_file = "";
	infile.close();
}
void find_words_from_a_file :: read_file()
{
	std :: ifstream infile(file_name);
	while(getline(infile, store))
	{
		the_whole_file += store;
	}
	infile.close();
}

void find_words_from_a_file::check_ii(int& i,string ss)
{
	if (i >= ss.length())
		return ;
	while (!((is_letter(ss[i])) && ((i == 0) || (ss[i-1] == ' '))))
	{
		i++;
		if (i > ss.length())
			return ;
	}
		
}

void find_words_from_a_file::check_jj(int& j,string ss)
{
	if (j >= ss.length())
		return ;
	while (!((is_letter(ss[j])) && ((j == ss.length()-1) || (ss[j+1] == ' '))))
	{
		j++;
		if (j > ss.length())
			return ;
	}
		
}
void find_words_from_a_file :: find_words()
{
	//cout <<"****"<<endl;
    if(the_whole_file == "")
        return;
	for(int i = 0; i < the_whole_file.size(); i += 1)
    {    
		if (!is_letter(the_whole_file[i]))
			the_whole_file[i] = ' ';
    }
	int ii = 0,jj = 0;
	while((ii < the_whole_file.length()) && (jj < the_whole_file.length()))
	{
		check_ii(ii,the_whole_file);
		jj = ii+1;
		check_jj(jj,the_whole_file);
		if (ii < the_whole_file.length())
		{
			string ss = the_whole_file.substr(ii,jj-ii+1);
			v2.push_back(ss);
		}
		ii = jj+1;
	}
	int si = v2.size() + 3;
    int count_index[si];
    for(int i = 0; i < si; i += 1)
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
			break;
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
	//cout <<"in fuck you."<<endl;
    if(the_whole_file == "")
        return;
    std :: ofstream fout("./data/new_words_in_file");
    if(!fout)
    {
        std :: cout << ">Error when open the new_words_in_file.txt!" << std :: endl;
        return;
    }
    fout << ">The new words in the file: " << std :: endl;
    std :: cout << ">The new words in the English file: " << std :: endl;
    for(int i = 0; i < v2.size(); i += 1)
    {
        for(int j = 0; j < import :: words_back[1].size(); j += 1)
        {
            if(v2[i] == import :: words_back[1][j].name)
            {
                //std :: cout << i << " " << v2[i] << " = " << words_back[1][j].name << std :: endl;
                std :: cout <<">"<< import :: words_back[1][j] << std :: endl;
                fout <<">"<< import :: words_back[1][j] << std :: endl;
            }
        }
    }
    fout << ">The unstable words in the file: " << std :: endl;
    std :: cout << ">The unstable words in the English file: " << std :: endl;
    for(int i = 0; i < v2.size(); i += 1)
    {
        for(int j = 0; j < import :: words_back[2].size(); j += 1)
        {
            if(v2[i] == import :: words_back[2][j].name)
            {
                //std :: cout << i << " " << v2[i] << " = " << words_back[1][j].name << std :: endl;
                std :: cout <<">"<< import :: words_back[2][j] << std :: endl;
                fout <<">"<< import :: words_back[2][j] << std :: endl;
            }
        }
    }
	fout.close();
}
