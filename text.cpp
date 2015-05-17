#include <ctime>
#include <iostream>
using namespace std;

int main() {
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    cout << (now->tm_year + 1900) << '-' 
         << (now->tm_mon + 1) << '-'
         <<  now->tm_mday
         << endl;
}

---------------------search_a_word/main.cpp------------------------------------------
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

string check(string line,int i)
{
	string s = "";
	while(line[i] != '[')
	{
		i++;
	}
	int start = i;
	while(line[i] != ']')
	{
		i++;
	}
	int end = i;
	for (int index = start+1;index < end;index++)
	{
		s += line[index];
	}
	return s;
}

int main()
{
	cout <<"Please input a word: "<<endl;
	string word;
	cin >>word;
	ifstream infile("newwords.txt");
	string line;
	if (!infile)
	{
        cout <<"error!"<<endl;
	}
	getline (infile,line);
	string store = "";
	int count =0;
	while (getline(infile,line))
	{
		++count;
		cout <<"***"<<count<<endl;
   	string a_word = check(line,0);
   	if (a_word == word)
   		break;
	}//
	
	//infile >> store;
	/*unsigned int i = 0;
	std :: cout <<"***"<<std :: endl;
			//std :: cout <<store.length()<<std :: endl;
	//std :: cout << store<<std :: endl;
	while(store[i] != word)
	{
		i += 1;
			//std :: cout <<"***"<<std :: endl;
		if(store[i] == word[0] && store[i - 1] == '[' && store[i - 2] == '{')
		{
			std :: cout <<"**************"<<std :: endl;
			int k = 0;
			for(int j = 0; j < word.length(); j ++)
			{
				if(word[j] == store[i + j])
					k += 1;
			}
			if(k == word.length())
			{
				std :: cout <<i;
				goto lable;
			}
		}
		if(i >= store.length())
		{
			std :: cout << "Can't find this word!" << std :: endl;
			return -1;
		}
	}
	lable: */return 0;
}

