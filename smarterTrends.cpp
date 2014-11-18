#include "smarterTrends.h"
#include <algorithm>

//This function is defined in naiveTrends.cpp
bool compareFunc(std::pair<std::string, unsigned int> i, std::pair<std::string, unsigned int> j);

void smarterTrends::increaseCount(std::string s, unsigned int amount){
	unsigned int startSize = numEntries();
	naiveTrends::increaseCount(s, amount);
	if (startSize != numEntries()){
		isSorted = false;
	}
}

std::string smarterTrends::getNthPopular(unsigned int n){
	if (!isSorted){
		std::sort(wordCountVector.begin(), wordCountVector.end(), compareFunc);
		isSorted = true;
	}

	if (n <= numEntries()){
		return wordCountVector[n].first;
	}

	//If they give bad input, return empty string.
	return "";
}