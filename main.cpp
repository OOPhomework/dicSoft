#include "word_back.h"
#include "file_operator.h"
#include "search_word.h"
#include <iostream>
#include <string>
int main(){
	std :: cout << "Welcome !" << std :: endl;
	std :: cout << "Please choose the function you want: " << std :: endl;
	std :: cout << "/: Search for a word." << std :: endl;
	std :: cout << "h: help for word back." << std :: endl;
	char choice;
	std :: cin >> choice;
	while(choice != '/' && choice != 'h')
	{
		std :: cout << "Please input the correct choice!" << std :: endl;
		std :: cin >> choice;
	}
	if(choice == '/')
	{
		std :: cout << "Please input the word you want to search for: ";
		std :: string word_you_want;
		std :: cin >> word_you_want;
		//search_a_word sw;		//为什么无法创建该对象？
		/*int position = sw.search(word_you_want);
		sw.print_to_single_word(position);*/
	}
	else if(choice == 'h')
	{
		//
	}
	return 0;
}
