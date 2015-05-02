main.exe : single_word.cpp file_operator.cpp main.cpp mnemonic.cpp word_back.cpp count.cpp
	g++ single_word.cpp file_operator.cpp main.cpp mnemonic.cpp word_back.cpp count.cpp -o main.exe
clean:
	rm *.exe
	rm *.o
