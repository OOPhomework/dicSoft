#include "word_back.h"
#include "search_word.h"
//#include "find_new_words.h"
#include "import.h"
#include "set_question.h"

#include "require.h"
#include "welcome.h"

#include <iostream>
#include <string>


using namespace std;
//extern string choice;

int main(){
	clear_screen();

	const char* file_name = "newwords.txt";
	import iprt0(file_name);
	iprt0.init();
	iprt0.import_words_file();

    welcome();
    cin.get();
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
        /*else if(choice == "f")
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
		}*/
    }
	return 0;
}

