#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <time.h>
#include <cstdlib>
using namespace std;

void swap_string(string sa,string sb)
{
    string ss = sa;
    sa = sb;
    sb = ss;
}

void do_question()
{
    //search_a_word saw;
    //index = saw.search(question_for_word.name);/////////////////////////////////
    string means[4] = {"dkfjeifd","jelifj","dfeifhg","iiendfj"};
    
    srand(time(NULL));
    int right_i = 3;
    for(int i =0 ;i < 10;i++)
    {
        int x = rand()% 4;
        int y = rand() % 4;
        swap_string(means[x],means[y]);
        if (x == right_i)
            right_i = y;
        else if(y == right_i)
            right_i = x;
    }//random swap
    cout <<"which One:";
    char choose;
    cin >>choose;
    while ((choose != 'A')&&(choose != 'B')&&(choose != 'C')&&(choose != 'D'))
    {
        cout <<"Error input!!!"<<endl;
        cout <<"Please input your choose again:";
        cin >>choose;
    }
    if (choose == char(right_i + 'A'))
        cout <<"CONGRATULATIONS!!!"<<endl;
    else
    {
        cout <<"SORRY...-.-"<<endl;
        cout <<"The right choose is "<<char(right_i + 'A')<<endl;
    }

}

int main()
{
	do_question();

	return 0;
}