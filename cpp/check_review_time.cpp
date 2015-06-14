#include "../h/check_review_time.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//vector<single_word> check_review_time::review_words(0);

void check_review_time::review_test_menu()
{
	cout << "*****************Review Words MENU****************" <<endl;
    cout << "*                     HELP                       *" <<endl;
    cout << "*    Here are your words review interface.       *" <<endl;
    cout << "*>>> back : return main menu.                    *" <<endl;
    cout << "*>>> next : the next word for test.              *" <<endl;
	cout << "********************MENU END**********************" <<endl;
}

void check_review_time::clear_screen()
{
//#ifdef WINDOWS
#ifdef _WIN32 || _WIN64
  std::system ( "CLS" );
#else
  // Assume POSIX
  std::system ( "clear" );
#endif
}

void check_review_time::current_time()
{
	time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    now_time.year = now->tm_year;
    now_time.month = now->tm_mon;
    now_time.day = now->tm_mday;
    //now-> tm_year return this year's number delete 1900;
    //now-> tm_mon return mouth;
    //now-> tm_mday return day's number;
    //we can caculate the day through to come true the time count;
}

bool check_review_time::check_time(single_word time_word)
{
	current_time();
	//cout <<"checked_word_time: "<<time_word.new_time.year<<" "<<time_word.new_time.month<<" "<<time_word.new_time.day<<endl;
	//cout <<"now_time: "<<now_time.year<<" "<<now_time.month<<" "<<now_time.day<<endl;
	if (time_word.new_time.year < now_time.year)
		return true;
	if (time_word.new_time.year == now_time.year)
	{
		if (time_word.new_time.month < now_time.month)
			return true;
		if (time_word.new_time.month == now_time.month)
		{
			if (time_word.new_time.day <= now_time.day)
				return true;
		}
	}
	return false;
}

void check_review_time::compare_time()
{
	int is_re = 1;
	for (int i = 1; i < 3;i++)
		for (int j =0 ;j < import::words_back[i].size();j++)
		{
			if (check_time(import::words_back[i][j]))
			{
				if (is_re)
				{
					char is_ok;
					cout <<"Sorry Interrupt, but you have some words in vocabulary book to review."<<endl;
					cout <<"Do you want to review?[Y/N]:";
					cin >>is_ok;
					is_ok = (char)toupper(is_ok);//*************upper character
					while((is_ok != 'Y') && (is_ok != 'N'))
					{
						cout <<"Error Input!!! Try again..."<<endl;
						cin >> is_ok;
						is_ok = (char)toupper(is_ok);//*************upper character
					}
					if (is_ok == 'N')
						return ;
					is_re = 0;
				}
				fir.push_back(i);
				sec.push_back(j);
				//review_words.push_back(import::words_back[i][j]);
			}
		}
}

void check_review_time::review_test()
{
	compare_time();
	if (fir.size() == 0)
	//if (review_words.size() == 0)
		return ;
	clear_screen();
	review_test_menu();
    char ch;
    cout <<">Choose : "<<endl;
    cout <<">A:back  B:next"<<endl;
	cin >>ch;
	ch = (char)toupper(ch);//*************upper character
	
	int i =0;
	while((ch == 'B')&&(i < fir.size()))
	{
		set_question stqs(import::words_back[fir[i]][sec[i]]);
		stqs.do_question();
		int &k = import::words_back[fir[i]][sec[i]].review_index;
		if (k != 4)
			k ++;
		import::words_back[fir[i]][sec[i]].get_next_time(k);
		
		
		cout <<"Input Enter...";
		cout.flush();
		cin.ignore().get();
		
		clear_screen();
		review_test_menu();
		cout <<">Choose : "<<endl;
		cout <<">A:back  B:next"<<endl;
		cin >>ch;
		ch = (char)toupper(ch);//*************upper character
		i++;
	}
}