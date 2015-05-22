#include "word_back.h"
#include "search_word.h"
//#include "import.h"???can't
#include <iostream>
#include <string>
using namespace std;

int main(){
	const char* file_name = "newwords.txt";
	import iprt0(file_name);
	iprt0.init();
	iprt0.import_words_file();
	//cout <<import::v[0]<<endl;
	//cout <<"***"<<endl;
	
	cout << "Welcome !" << endl;
    cout << "Please choose the function you want: " << endl;
    cout << "/: Search for a word." << endl;
    cout << "/w: Search and set lable for it."<<endl;
    cout << "h: help for word back." << endl;
	string choice;
	cin >> choice;

	while(choice != "/" && choice != "h" && choice != "/w")
	{
		cout << "Please input the correct choice!" << endl;
		cin >> choice;
	}
	if(choice[0] == '/')
	{
		search_a_word sw;
		cout << "Please input the word you want to search for: \n"
			<<"(tips:if you input character 'q',you 'll back to the main menu.)"<<endl;
		string word_you_want = "find";
		cin >> word_you_want;
		while(word_you_want != "q")
		{
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
		/*int position = sw.search(word_you_want);
		sw.print_to_single_word(position);*/
	}
	else if(choice == "h")
	{
		//
	}
	return 0;
}
