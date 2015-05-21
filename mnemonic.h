#ifndef MNEMONIC_H
#define MNEMONIC_H
#include "single_word.h"
#include "import.h"
#include <iostream>
#include <string>
#include <vector>

class mnemonic
{
public:
    mnemonic(std::string word,std::string s):word(word),file_name(s){}
    //std::string check_bracket(std::string ,int&);
    //single_word print_to_single_word(std::string s);
    void start_creat();//
    void print_relative();
    ~mnemonic(){}
private:
    std:: string get_left(std::string s);
    bool check_relative(std::string s);
    
    std::string word;//the word created for relavitives
    std::string file_name;//file found from
    std::vector<single_word> words_relative;
};

#endif // MNEMONIC_H
