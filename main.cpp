#include "word_back.h"
#include "search_word.h"
#include "find_new_words.h"
//#include "import.h"???can't
#include <iostream>
#include <string>
#include <cstdlib>
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

void manu()
{
    cout << "*************************MANU*********************"<<endl;
	cout << "*          WELCOME TO DRAGON DREAM               *" << endl;
}

void init()
{
    cout << "*>>> /: Search for a word.                       *" << endl;
    cout << "*>>> /w: Search and set lable for it.            *"<<endl;
    cout << "*>>> b: help for word back.                      *" << endl;
    cout << "*>>> t: help for word test.                      *" << endl;
    cout << "*>>> 0: quit.                                    *"<<endl;
    cout << "*********************MANU END*********************"<<endl;
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

    manu();
    while(choice != "0")
    {
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
            cout <<"Sorry, word_back hav't done!"<<endl;
            cout << "*************************MANU*********************"<<endl;
            //goto circle;
            //
        }
        else if(choice == "t")
        {
            cout <<"Sorry, word_test hav't done!"<<endl;
            cout << "*************************MANU*********************"<<endl;
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
{
		search_a_word sw;
		cout << "Please input the word you want to search for. \n"
			<<"tips:\n"
			<<">>> Input number -1 : back to the main menu.\n"
			<<">>> Input number  0 : quit DragonDream."
			<<endl;
		cout <<"word search:";
		string word_you_want;
		cin >> word_you_want;
		while((word_you_want != "0"))
		{
            if (word_you_want == "-1")
            {
                cout << "*************************MANU*********************"<<endl;
                return ;
            }
			//cout <<"***"<<endl;
			bool can_find	= sw.search(word_you_want);
			sw.print();
			if (can_find && (choice == "/w"))
			{
				sw.set_lable();
			}
			cout <<"word search : ";
			cin >> word_you_want;
		}		//为什么无法创建该对象？
		choice = "0";
		/*int position = sw.search(word_you_want);
		sw.print_to_single_word(position);*/
}
}
