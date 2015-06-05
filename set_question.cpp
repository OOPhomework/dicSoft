
#include "search_word.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <time.h>
using namespace std;


#include "set_question.h"

/*void set_question::swap_string(string& sa,string& sb)
{
    string ss = sa;
    sa = sb;
    sb = ss;
}*/

void set_question::do_question()
{
    search_a_word saw;
    index = saw.search(question_for_word.name);/////////////////////////////////
    string means[4];
    //cout <<"in set_question"<<endl;
    if (index < 10)
    {
        means[0] = import::v[index+1].part_of_speech;
        means[1] = import::v[index+2].part_of_speech;
        means[2] = import::v[index+3].part_of_speech;
    }
    else if (index > import::v.size()-10)
    {
        means[0] = import::v[index-1].part_of_speech;
        means[1] = import::v[index-2].part_of_speech;
        means[2] = import::v[index-3].part_of_speech;
    }
    else
    {
        means[0] = import::v[index-1].part_of_speech;
        means[1] = import::v[index-2].part_of_speech;
        means[2] = import::v[index+1].part_of_speech;
    }
    //cout <<"index : "<<index<<endl;
    means[3] = question_for_word.part_of_speech;

    cout <<">word : "<<question_for_word.name<<endl;
    srand(time(NULL));
    int right_i = 3;
    for(int i =0 ;i < 10;i++)
    {
        int x = rand()% 4;
        int y = rand() % 4;
        //swap_string(means[x],means[y]);
        string ss = means[x];
        means[x] = means[y];
        means[y] = ss;
        if (x == right_i)
            right_i = y;
        else if(y == right_i)
            right_i = x;
    }//random swap
    for (int i = 0;i < 4;i++)
    {
        cout <<char('A' + i)<<":"<<means[i]<<endl;
    }
    cout <<">which One:";
    char choose;
    cin >>choose;
    while ((choose != 'A')&&(choose != 'B')&&(choose != 'C')&&(choose != 'D'))
    {
        cout <<"Error input!!!"<<endl;
        cout <<"Please input your choose again:";
        cin >>choose;
    }
    if (choose == char(right_i + 'A'))
        cout <<"Congratulations!!!"<<endl;
    else
    {
        cout <<"...SORRY...-.-"<<endl;
        cout <<"The right choose is "<<char(right_i + 'A')<<endl;
    }

}


