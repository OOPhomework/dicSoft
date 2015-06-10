main.exe: main.o single_word.o mnemonic.o word_back.o import.o search_word.o set_question.o
	g++ main.o single_word.o mnemonic.o word_back.o import.o search_word.o set_question.o -o main.exe
main.o:main.cpp require.h welcome.h
	g++ -c main.cpp -o main.o
single_word.o:single_word.cpp
	g++ -c single_word.cpp -o single_word.o
mnemonic.o:mnemonic.cpp
	g++ -c mnemonic.cpp -o mnemonic.o
word_back.o:word_back.cpp
	g++ -c word_back.cpp -o word_back.o
import.o:import.cpp import.h
	g++ -c import.cpp -o import.o
search_word.o:search_word.cpp
	g++ -c search_word.cpp -o search_word.o
set_question.o:set_question.cpp
	g++ -c set_question.cpp -o set_question.o
clean:
	rm *.o
	rm *.exe
