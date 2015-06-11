#include "../h/mnemonic.h"
using namespace std;


string mnemonic::get_left(string s)
{
    int i = 0;
    while (s[i] == word[i])
    {
        i++;
        if ((i == s[i])||(i == word[i]))
            break;
    }
    //cout <<"***"<<endl;
    //cout <<s <<' '<<word<<endl;
    //cout <<"i : "<<i<<endl;
    string left = "";
    if (i < s.length())//protect the same word and out of range
        left = s.substr(i,s.length()-i);//string's function substr(int a,int b)
                                            //starting get the string's character from index a ,extract b chars
    return left;
}

bool mnemonic::check_relative(string s)
{
    if (s[0] != word[0])
        return false;
    string left = get_left(s);
    int len = left.length();
    if (s.length() < (len + word.length()/2))
        return false;
    if ((len == 0)&&(s != word))
        return true;
    /*if (len >= 1){ 
        //cout <<"left : "<<left<<endl; 
        string one_left = left.substr(len-1,1);
        if ((len - one_left.length()) < 2)
            if ((one_left == "d")||(one_left == "s"))
                return true;
    }
    else
        return false;*/
    if ((left == "ed")||(left == "d")||(left == "es")||(left == "s"))
        return true;
    if (len >= 2){
        //cout <<"left : "<<left<<endl; 
        string two_left = left.substr(len-2,2);
        if ((len - two_left.length()) < 2)
            if ((two_left == "ly")||(two_left == "al"))
                return true;
    }
    else
        return false;
    if (len >= 3){
        string th_left = left.substr(len-3,3);
        if ((len - th_left.length()) < 2)
            if ((th_left == "ure")||(th_left == "ful")||(th_left == "ive")||(th_left == "ing"))
                return true;
    }
    else
        return false;
    if (len >= 4){ 
        string fou_left = left.substr(len-4,4);
        if ((len - fou_left.length()) < 2)
            if (fou_left == "ship")
                return true;
    }
    return false;
}


void mnemonic::_creat()
{
    for(unsigned int i = 0;i < import::v.size();i++)
    {
        //printf( "%d\n", i );
        if (check_relative(import::v[i].name))
        {
            words_relative.push_back(import::v[i]);
        }
    }
    print_relative();
    //check_list(words);//put on list of words relative

}

void mnemonic::print_relative()
{
    cout <<">relative words:"<<endl;
    for (int i = 0;i < words_relative.size();i++)
    {
        cout <<">                       "<<words_relative[i].name<<endl;
    }
}
