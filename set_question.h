#ifndef SET_QUESTION_H
#define SET_QUESTION_H
#include "import.h"
#include "single_word.h"
#include <cstring>
#include <string>

class set_question
{
public:
    set_question(single_word word):question_for_word(word){}
    void do_question();
    //void swap_string(string&, string&);

    ~set_question(){}
private:
	void answer_question();

	int right_i;
    single_word question_for_word;
    int index;
};

#endif // SET_QUESTION_H

