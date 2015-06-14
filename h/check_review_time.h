#ifndef CHECK_REVIEW_TIME_H
#define CHECK_REVIEW_TIME_H
#include "single_word.h"
#include "import.h"
#include "set_question.h"

class check_review_time
{
public:
	check_review_time()
	{
		std::vector<int> fir(0);
		std::vector<int> sec(0);
	}
	void review_test();
	
	//static std::vector<single_word> review_words;
	
private:
	void current_time();
	bool check_time(single_word);
	void compare_time();
	void review_test_menu();
	void clear_screen();
	
	std::vector<int> fir;
	std::vector<int> sec;
	date now_time;
	single_word checked_word;
};

#endif //CHECK_REVIEW_TIME_H