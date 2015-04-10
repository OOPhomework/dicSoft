main.exe : a_word.cpp file_operator.cpp main.cpp mnemonic.cpp word_back.cpp
	g++ a_word.cpp file_operator.cpp main.cpp mnemonic.cpp word_back.cpp -o main.exe
clean:
	rm *.exe
	rm *.o
