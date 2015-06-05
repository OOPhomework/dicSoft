#include "word_back.h"
#include "search_word.h"
#include "find_new_words.h"
//#include "import.h"???can't
#include "import.h"
#include "set_question.h"
#include "require.cpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
using namespace std;
string choice = "";



void welcome()
{
	cout << "           WELCOME TO DRAGON DREAM                " << endl;
}

void init()
{
    cout << "**********************MANU************************" <<endl;
    cout << "*>>> /: Search for a word.                       *" <<endl;
    cout << "*>>> /w: Search and set lable for it.            *" <<endl;
    cout << "*>>> b: help for word back.                      *" <<endl;
    cout << "*>>> t: help for word test.                      *" <<endl;
    cout << "*>>> 0: quit.                                    *" <<endl;
    cout << "********************MANU END**********************" <<endl;
}

void search_menu()
{
    cout << "*******************Search MENU********************" <<endl;
    cout << "*                     HELP                       *" <<endl;
	cout << "*>>> -1 : back to the main menu.                 *" <<endl;
	cout << "*>>> 0  : quit.                                  *" <<endl;
    cout << "********************MANU END**********************" <<endl;
}

void word_back_menu()
{
    cout << "*****************Word Back MENU*******************" <<endl;
    cout << "*                     HELP                       *" <<endl;
	cout << "*>>>back : back to menu.                         *" <<endl;
	cout << "*>>>next : next word to test.                    *" <<endl;
	cout << "*>>>end  : quit.                                 *" <<endl;
    cout << "********************MANU END**********************" <<endl;
}

void check_choice(string& choice)
{
    while(choice != "/" && choice != "/w" && choice != "b" && choice != "t" && choice != "0" && choice != "f")
	{
		cout << "Please input the correct choice!" << endl;
		cin >> choice;
	}
}

void search_func();
//void set_question(int index,int i);
void get_question();
void word_back_func();

int main(){
	//cout << "\033[2J\033[1;1H";
	/*These are ANSI escape codes. The first one (\033[2J) clears
	the entire screen (J) from top to bottom (2). The second
	code (\033[1;1H) positions the cursor at row 1, column 1.
		All ANSI escapes begin with the sequence ESC[, have zero
	or more parameters delimited by ;, and end with a command
	letter (J and H in your case). \033 is the C-style octal
	sequence for the escape character.
	*/
	clear_screen();

	const char* file_name = "newwords.txt";
	import iprt0(file_name);
	iprt0.init();
	iprt0.import_words_file();
	//cout <<import::v[0]<<endl;
	//cout <<"***"<<endl;

    welcome();
    //system("pause");
    //cout <<"Input a enter:";
    cin.get();
    //cin.ignore().get();
    while(choice != "0")
    {
    	clear_screen();
        init();

        cout<< "Please choose the function you want: " << endl;
        cin >> choice;

        check_choice(choice);

        if (choice == "0")
            return 0;

        if(choice[0] == '/')
        {
            search_func();
        }
        else if(choice == "b")
        {
            word_back_func();
            //goto circle;
            //
        }
        else if(choice == "t")
        {
            cout <<"Sorry, word_test hav't done!"<<endl;
            //goto circle;
        }
        else if(choice == "f")
        {
        	//First, we need to open an English file.
		    cout << "PLease input the file you want to operate: ";
		    string fn1;     //The name of the file.
		    cin >> fn1;
			find_words_from_a_file f1(fn1.c_str());
			//system("pause");
			f1.read_file();
			//system("pause");
			f1.find_words();		//Now we have got all the words in the English file.
		}
    }
	return 0;
}

void search_func()
{
		clear_screen();
		search_a_word sw;
		search_menu();
		cout << ">word search:";
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
			//string pause;
			//cin >>pause;
			//cin.ignore(cin.rdbuf()->in_avail()+1);
			//cin.clear();
			//cin.get();
			cin.ignore().get(); //Pause Command for Linux Terminal
			clear_screen();
			search_menu();
			cout <<">word search : ";
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
    string ch = "";
    cout <<">Choose : "<<endl;
    cout <<">A:back  B:next  C:end"<<endl;
    cin >>ch;
    //cout <<ch<<endl;
    while(ch == "B")
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
        cin.ignore().get();
        clear_screen();
        word_back_menu();
        cout <<">Choose : "<<endl;
        cout <<">A:back  B:next  C:end"<<endl;
        cin >>ch;
    }
    if (ch == "C")
        choice = "0";
}

