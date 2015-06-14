OS = windows
ifeq ($(shell uname), Linux)
OS = linux
endif
ifeq ($(shell uname), Darwin)
OS = mac
endif

hpath = .\\h\\
cpppath = .\\cpp\\
remove = del
ifeq ($(OS), linux)
hpath = ./h/
cpppath = ./cpp/
remove = rm
endif
ifeq ($(OS), mac)
hpath = ./h/
cpppath = ./cpp/
remove = rm
endif

byyh = -O2 -std=c++11 -w
set_question_h = $(hpath)set_question.h
search_word_h = $(hpath)search_word.h
import_h = $(hpath)import.h
mnemonic_h = $(hpath)mnemonic.h
single_word_h = $(hpath)single_word.h
find_new_words_h = $(hpath)find_new_words.h
check_review_time_h = $(hpath)check_review_time.h
require_h = $(hpath)require.h
welcome_h = $(hpath)welcome.h

set_question_cpp = $(cpppath)set_question.cpp
search_word_cpp = $(cpppath)search_word.cpp
import_cpp = $(cpppath)import.cpp
mnemonic_cpp = $(cpppath)mnemonic.cpp
single_word_cpp = $(cpppath)single_word.cpp
find_new_words_cpp = $(cpppath)find_new_words.cpp
check_review_time_cpp = $(cpppath)check_review_time.cpp
main_cpp = $(cpppath)main.cpp

all_h = $(set_question_h) $(search_word_h) $(import_h) $(mnemonic_h) $(single_word_h)\
			$(find_new_words_h) $(check_review_time_h) $(require_h) $(welcome_h) 
all_cpp = $(set_question_cpp) $(search_word_cpp) $(import_cpp) $(mnemonic_cpp) $(single_word_cpp)\
			$(find_new_words_cpp) $(check_review_time_cpp) $(main_cpp)
all_o = main.o\
			set_question.o search_word.o import.o mnemonic.o single_word.o find_new_words.o check_review_time.o
			
all : main.exe
main.exe : $(all_o)
	g++ $(all_o) -o main.exe
	$(remove) *.o *.gch

main.o : $(main_cpp)
	g++ -c $(main_cpp) -o main.o $(byyh)
set_question.o : $(set_question_cpp)
	g++ -c $(set_question_cpp) -o set_question.o $(byyh)
search_word.o : $(set_question_cpp)
	g++ -c $(search_word_cpp) -o search_word.o $(byyh)
import.o : $(import_cpp)
	g++ -c $(import_cpp) -o import.o $(byyh)
mnemonic.o : $(mnemonic_cpp)
	g++ -c $(mnemonic_cpp) -o mnemonic.o $(byyh)
single_word.o : $(single_word_cpp)
	g++ -c $(single_word_cpp) -o single_word.o $(byyh)
find_new_words.o : $(find_new_words_cpp)
	g++ -c $(find_new_words_cpp) -o find_new_words.o $(byyh)
check_review_time.o : $(check_review_time_cpp)
	g++ -c $(check_review_time_cpp) -o check_review_time.o $(byyh)

clean:
	$(remove) *.o *.exe *.gch

#main.exe: main.o single_word.o mnemonic.o word_back.o import.o search_word.o set_question.o
#	g++ main.o single_word.o mnemonic.o word_back.o import.o search_word.o set_question.o -o main.exe
#main.o:main.cpp require.h welcome.h
#	g++ -c main.cpp -o main.o
#single_word.o:single_word.cpp single_word.h
#	g++ -c single_word.cpp -o single_word.o
#mnemonic.o:mnemonic.cpp mnemonic.h
#	g++ -c mnemonic.cpp -o mnemonic.o
#word_back.o:word_back.cpp word_back.h
#	g++ -c word_back.cpp -o word_back.o
#import.o:import.cpp import.h
#	g++ -c import.cpp -o import.o
#search_word.o:search_word.cpp search_word.h
#	g++ -c search_word.cpp -o search_word.o
#set_question.o:set_question.cpp set_question.h
#	g++ -c set_question.cpp -o set_question.o
#clean:
#	rm *.o
#	rm *.exe


