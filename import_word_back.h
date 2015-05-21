#ifndef IMPORT_WORD_BACK_H
#define IMPORT_WORD_BACK_H
#include "single_word.h"
#include "search_word.h"
#include <vector>

class import_word_back
{
public:
	import_word_back();
	~import_word_back();
private:
	std::vector<single_word> words_new;
	std::vector<single_word> words_unstable;
	std::vector<single_word> words_familiar;	
};

#endif // IMPORT_WORD_BACK_H