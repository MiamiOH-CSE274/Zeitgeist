#include "naiveTrends.h"

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

std::string naiveTrends::getNthPopular(int n){
	//TODO: Sort the vector, then return the nth item
	return "";
}

int naiveTrends::numEntries(){
	return wordCountVector.size();
}