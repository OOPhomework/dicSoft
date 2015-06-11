#ifndef REQUIRE_H
#define REQUIRE_H

#include "welcome.h"
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;
string choice = "";

void clear_screen()
{
#ifdef WINDOWS
  std::system ( "CLS" );
#else
  // Assume POSIX
  std::system ( "clear" );
#endif
}


void search_func()
{
		clear_screen();
		search_a_word sw;
		search_menu();
		cout << ">word search:";
        cout.flush();
		string word_you_want;
		cin >> word_you_want;
		while((word_you_want != "0"))
		{
            if (word_you_want == "-1")
            {
                return ;
            }
			//cout <<"***"<<endl;
			int can_find = sw.search(word_you_want);
			sw.print();
			if ((can_find != -1) && (choice == "/w"))
			{
				sw.set_lable();
			}
            cout <<"Input Enter...";
            cout.flush();
			cin.get(); 
            cin.ignore(1024,'\n');

			clear_screen();
			search_menu();
			cout <<">word search : ";
            cout.flush();
			cin >> word_you_want;
		}		//为什么无法创建该对象？
		choice = "0";
		/*int position = sw.search(word_you_want);
		sw.print_to_single_word(position);*/
}


void get_question()
{
    int section[3] = {0,60,100};
    if (import::words_back[1].size() == 0)
        section[1] = 0;
    else if (import::words_back[2].size() == 0)
        section[1] = 100;
    srand(time(NULL));
    int num = rand() % 100;
    //cout <<"888"<<endl;
    for (int i = 0;i < 3;i++)
    {
        if (num < section[i])
        {
            //cout << num<<endl;
            float _rand = rand();
            float rand_max = RAND_MAX;
            float len = import::words_back[i].size();
            int index = static_cast<int>((_rand/rand_max)*len);
            //cout <<"set_question..."<<endl;
            set_question ss(import::words_back[i][index]);
            ss.do_question();
            break;
        }
    }
}
void word_back_func()
{
	clear_screen();
    word_back_menu();
    char ch;
    cout <<">Choose : "<<endl;
    cout <<">A:back  B:next  C:end"<<endl;
    cin >>ch;
    ch = (char)toupper(ch);//*************upper character
    //cout <<ch<<endl;
    while(ch == 'B')
    {
        if ((import::words_back[1].size() == 0)&&(import::words_back[2].size() == 0))
        {
            cout <<"You don't have any word can't remember."<<endl;
            return ;
        }
        clear_screen();
        word_back_menu();
        //cout <<"***"<<endl;
        get_question();
        cout <<"Input Enter...";
        cin.ignore().get();
        clear_screen();
        word_back_menu();
        cout <<">Choose : "<<endl;
        cout <<">A:back  B:next  C:end"<<endl;
        cin >>ch;
        ch = (char)toupper(ch);//*************upper character
    }
    if (ch == 'C')
        choice = "0";
}

void word_test_func()
{
    clear_screen();
    word_test_menu();
    char ch;
    cout <<">Choose : "<<endl;
    cout <<">A:back  B:next  C:end"<<endl;
    cin >>ch;
    ch = (char)toupper(ch);//*************upper character
    while(ch == 'B')
    {
        clear_screen();
        word_test_menu();
        //cout <<"***"<<endl;
        srand(time(NULL));
        float _rand = rand();
        float rand_max = RAND_MAX;
        float len = import::v.size();
        int index = static_cast<int>((_rand/rand_max)*len);
            //cout <<"set_question..."<<endl;
        set_question ss(import::v[index]);
        ss.do_question();

        cout <<"Input Enter...";
        cin.ignore().get();
        clear_screen();
        word_back_menu();
        cout <<">Choose : "<<endl;
        cout <<">A:back  B:next  C:end"<<endl;
        cin >>ch;
        ch = (char)toupper(ch);//****************upper character
    }
    if (ch == 'C')
        choice = "0";
}

#endif //REQUIRE_H