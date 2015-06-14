#include "../h/word_back.h"
#include "../h/search_word.h"
#include "../h/find_new_words.h"
#include "../h/import.h"
#include "../h/set_question.h"

#include "../h/require.h"
#include "../h/welcome.h"

#include <iostream>
#include <string>


using namespace std;
//extern string choice;

int main(){
	clear_screen();

	const char* file_name = "./data/newwords.txt";
	import iprt0(file_name);
	iprt0.init();
	iprt0.import_words_file();

    welcome();
    cin.get();
    //cin.ignore(1024,'\n');
    //cin.ignore().get();
    while(choice != "0")
    {
    	clear_screen();
        init();

        cout<< "Please enter your choice: ";
        cout.flush();
        cin >> choice;
        //(char)toupper(choice);

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
            word_test_func();
            //cout <<"Sorry, word_test hav't done!"<<endl;
            //goto circle;
        }
        else if(choice == "f")
        {
        	//First, we need to open an English file.
            cout << "PLease input the file you want to operate: ";
		    string fn1;     //The name of the file.
		    while(cin >> fn1)
            {
                //cout << "PLease input the file you want to operate: ";
                find_words_from_a_file f1(fn1.c_str());
                f1.read_file();
                f1.find_words();		//Now we have got all the words in the English file.
                //f1.print();
                cin.get();
                cin.ignore(1024, '\n');

                f1.fuckyou();
                cout << "Please choose what you want to do:" << endl;
                cout << "A. continue    B.quit" << endl;
                char choice;
                cin >> choice;
                if(choice == 'a' || choice == 'A')
                {
                    cout << "Please input the file you want to operate: ";
                    continue;
                }
                else if(choice == 'b' || choice == 'B' || choice == '0')
                    break;
                if(fn1 == "0")
                    break;
                cin.get();
                cin.ignore(1024, '\n');
            }
		}
    }
	return 0;
}

