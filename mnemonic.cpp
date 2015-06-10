#include "mnemonic.h"
#include "single_word.h"
#include "import.h"
#include <iostream>
using namespace std;


string mnemonic::get_left(string s)
{
    int i = 0;
    while (s[i] == word[i])
    {
        i++;
    }
    string left;
    left = s.substr(i,s.length()-i);//string's function substr(int a,int b)
                                            //starting get the string's character from index a ,extract b chars
    return left;
}

bool mnemonic::check_relative(string s)
{
    //int l1 = s.length();
    //int l2 = word.length();
    if (s[0] != word[0])
        return false;
    string left = get_left(s);
    if (left == "ure")
        return true;
    else if ((left == "ed")||(left == "d"))
        return true;
    else if ((left == "ful")||(left == "iful"))
        return true;
    else if (left == "ive")
        return true;
    else if (left == "ship")
        return true;
    return false;
}


void mnemonic::creat()
{
    //file_operator fin(s);
    //ifstream fin(file_name);
    //string line;
    int i =0;
    while(i < import::v.size())
    {
        //string a_word = check_bracket(line,0);
        if (check_relative(import::v[i].name))
        {
            //single_word* the_word = print_to_single_word(line);
            words_relative.push_back(import::v[i]);
        }
    }
    print_relative();
    //check_list(words);//put on list of words relative

}

void mnemonic::print_relative()
{
    for (int i = 0;i < words_relative.size();i++)
    {
        cout <<words_relative[i].name<<endl;
    }
}
