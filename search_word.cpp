#include "search_word.h"
int search_a_word :: search(std :: string word)
{
	std :: ifstream infile("newwords.txt");
	infile >> store;
	int i = 0;
	while(store[i] != word[0])
	{
		i += 1;
		if(store[i] == word[0] && store[i - 1] == '[' && store[i - 2] == '{')
		{
			int k = 0;
			for(int j = 0; j < word.length(); j += 1)
			{
				if(word[j] == store[i + j])
					k += 1;
			}
			if(k == word.length())
			{
				return i;
			}
		}
		if(i >= store.length())
		{
			std :: cout << "Can't find this word!" << std :: endl;
			return -1;
		}
	}
}

void search_a_word :: print_to_single_word(int position)
{
	int p = position, q = position;
	while(store[q] != '[')
		q += 1;
	p = q;
	while(store[q] != ']')
		q += 1;
	for(int i = p, k = 0; i < q; i += 1, k += 1)
	{
		a_word.name[k] = store[i];
	}//以上代码把单词对象的名字填充了。
	p = q;
	q += 1;
	while(store[q] != ']')
		q += 1;
	for(int i = p + 1, k = 0; i < q; i += 1, k += 1)
	{
		a_word.phonetic_symbol[k] = store[i];
	}//填充音标.
	p = q;
	q += 1;
	while(store[q] != '.')
		q += 1;
	for(int i = p + 1, k = 0; i < q; i += 1, k += 1)
	{
		a_word.part_of_speech[k] = store[i];
	}//词性
	p = q;
	q += 1;
	std :: cout << a_word.name << std :: endl;
	std :: cout << a_word.phonetic_symbol << std :: endl;
	std :: cout << a_word.part_of_speech << std :: endl;
	std :: string str;
	while(store[q] != ']')
		q += 1;
	std :: cout << "Meaning: ";
	for(int i = p + 1; i < q; i += 1)
	{
		std :: cout << store[i];
	}
	std :: cout << std :: endl;
	p = q;
	q += 1;
	while(store[q] != '}')
		q += 1;
	std :: cout << "Example: ";
	for(int i = p + 1; i < q; i += 1)
	{
		std :: cout << store[i];
	}
	std :: cout << std :: endl;
}
