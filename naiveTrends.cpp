#include "naiveTrends.h"
#include <algorithm>

void naiveTrends::increaseCount(std::string s, int amount){
	//Check to see if word is already present
	for (unsigned int i = 0; i < wordCountVector.size(); i++){
		if (wordCountVector[i].first == s){
			//If so, just increment the "amount"
			wordCountVector[i].second += amount;
			return;
		}
	}
	//If not, add a new item to the list.
	wordCountVector.push_back(std::make_pair(s, amount));
}

int naiveTrends::getCount(std::string s){
	//Check to see if word is present
	for (unsigned int i = 0; i < wordCountVector.size(); i++){
		if (wordCountVector[i].first == s){
			//If so, return the count
			return wordCountVector[i].second;
		}
	}
	//otherwise, return 0
	return 0;
}

bool compareFunc(std::pair<std::string, int> i, std::pair<std::string, int> j) {
	if (i.second == j.second){
		return (i.first < j.first);
	}

	return (i.second > j.second);
}

std::string naiveTrends::getNthPopular(unsigned int n){
	std::sort(wordCountVector.begin(), wordCountVector.end(), compareFunc);
	if (n <= numEntries()){
		return wordCountVector[n].first;
	}

	//If they give bad input, return empty string.
	return "";
}

unsigned int naiveTrends::numEntries(){
	return wordCountVector.size();
}