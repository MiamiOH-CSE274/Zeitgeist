#include "utilities.h"

#include <time.h>
#include <iostream>
#include <fstream>

double getTimeInMillis(){
	clock_t now = clock();
	return 1000.0*now / CLOCKS_PER_SEC;
}

std::vector<std::string> getWordList(const char* filename){
	//First, read in the file
	// I'm not doing much error checking here, because I am a bad person
	std::ifstream in(filename);
	std::string s;
	std::vector<std::string> wordlist;
	while (in >> s){
		wordlist.push_back(s);
	}

	return wordlist;
}