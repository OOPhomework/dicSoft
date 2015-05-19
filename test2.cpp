#include <iostream>
#include <cstring>
#include <string>
using namespace std;

string check_bracket(string line,int& i)
{
    int match = 0;
    while(line[i] != '[')
    {
        match ++;
        i++;
    }
    int start = ++i;
    int num = 0;
    while(match != 0)
    {
        if (line[i] == '[')
            match++;
        else if (line[i] == ']')
            match--;
        i++;num++;
    }
    i--;
    string s = line.substr(start,num-1);//string's function substr(int a,int b)
                                    //starting get the string's character from index a ,extract b chars
    return s;
}

int main()
{
	string s = "{[abe[dfe]nd****][ə'bend][异常结束][]}";
	int i = 0;
	string ss = check_bracket(s,i);
	cout <<ss<<endl;
	cout <<i<<endl;
	return 0;
}