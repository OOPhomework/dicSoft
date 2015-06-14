#include "../h/word_back.h"
#include "../h/search_word.h"
#include "../h/find_new_words.h"
#include "../h/import.h"
#include "../h/set_question.h"
#include "../h/check_review_time.h"

#include "../h/require.h"
#include "../h/welcome.h"

#include <iostream>
#include <string>


using namespace std;
//extern string choice;

int main(){
	clear_screen();

	const char* file_name = "./data/newwords.txt";
	#ifdef _WIN32 || _WIN64
		  file_name = "./data/newwords(1).txt";
	#endif
	import iprt0(file_name);
	iprt0.init();
	iprt0.import_words_file();

    welcome();
    cin.get();
    //cin.ignore(1024,'\n');
    //cin.ignore().get();
	
	clear_screen();
	check_review_time crt;
	crt.review_test();
	
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
        	find_words_file_func();
		}
    }
	return 0;
}

