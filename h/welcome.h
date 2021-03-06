#ifndef WELCOME_H
#define WELCOME_H
using namespace std;

void welcome()
{
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << ">>>     /\\                         /\\          <<<" << endl;
    cout << ">>>    /  \\        WELCOME        /  \\         <<<" << endl;
    cout << ">>>             Dragon   Dream                 <<<" << endl;
	cout << ">>>                  ___                       <<<" << endl;
    cout << ">>>                  000                       <<<" << endl;
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << "Input Enter...";
    cout.flush();
}

void init()
{
    cout << "**********************MENU************************" <<endl;
    cout << "*>>> / : Search for a word.                      *" <<endl;
    cout << "*>>> /w: Search and set lable for it.            *" <<endl;
    cout << "*>>> b : help for test word in vocabulary book.  *" <<endl;
    cout << "*>>> t : help for random word test.              *" <<endl;
    cout << "*>>> f : capture vocabulary from files.          *" <<endl;
    cout << "*>>> 0 : quit.                                   *" <<endl;
    cout << "********************MENU END**********************" <<endl;
}

void search_menu()
{
    cout << "*******************Search MENU********************" <<endl;
    cout << "*                     HELP                       *" <<endl;
    cout << "*     input word you want to search.             *" <<endl;
	cout << "*>>> -1 : back to the main menu.                 *" <<endl;
	cout << "*>>> 0  : quit.                                  *" <<endl;
    cout << "********************MENU END**********************" <<endl;
}

void word_back_menu()
{
    cout << "*****************Word Back MENU*******************" <<endl;
    cout << "*                     HELP                       *" <<endl;
	cout << "*>>> back : back to menu.                        *" <<endl;
	cout << "*>>> next : continue memorise words in           *" <<endl;
    cout << "*            vocabulary book.                    *" <<endl;
	cout << "*>>> end  : quit Dragon Dream.                   *" <<endl;
    cout << "********************MENU END**********************" <<endl;
}

void word_test_menu()
{
    cout << "*****************Word Test MENU*******************" <<endl;
    cout << "*                     HELP                       *" <<endl;
    cout << "*>>> back : back to menu.                        *" <<endl;
    cout << "*>>> next : continue memorise words in           *" <<endl;
    cout << "*            the thesaurus.                      *" <<endl;
    cout << "*>>> end  : quit Dragon Dream.                   *" <<endl;
    cout << "********************MENU END**********************" <<endl;
}

void find_words_menu()
{
	cout << "*****************Find Words MENU******************" <<endl;
    cout << "*                     HELP                       *" <<endl;
    cout << "*    Capture new words in vocabulary book        *" <<endl;
    cout << "*   from files input.Output these new words      *" <<endl;
    cout << "*in dos or terminal and file \"new_words_in_file\".*" <<endl;
    cout << "*  You can find this file in data directory.     *" <<endl;
    cout << "*>>> -1 : back to main menu.                     *" <<endl;
    cout << "*>>> 0  : quit Dragon Dream.                     *" <<endl;
	cout << "********************MENU END**********************" <<endl;
}


void check_choice(string& choice)
{
    while(choice != "/" && choice != "/w" && choice != "b" && 
    	choice != "t" && choice != "0" && choice != "f" && choice != "#")
	{
		cout << "Please input the correct choice!" << endl;
		cin >> choice;
	}
}

#endif //WELCOME_H