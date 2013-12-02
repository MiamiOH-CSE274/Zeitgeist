#include "emrickgjTrends.h"
#include <iostream>
/**
*
* Start my Class implementation
*
*/
int primes [] = {53, 97, 193, 389, 769, 1543, 3079, 6151, 12289, 
		24593, 49157, 98317, 196613, 393241, 786433, 1572869, 3145739, 6291469, 
		12582917, 25165843, 50331653, 100663319, 201326611, 402653189, 805306457, 
		1610612741};


emrickgjTrends::emrickgjTrends(){
	numOfEntries = 0;
	numCollisions = 0;
	dummyNode = new Data();
	mainTableSize = 0;
	collisionTableSize = 0;
	mainTable = new Data[10];
	collisionTable = new Data[5];

	dummyNode -> data = (std::string)"";

	std::cout << "1:" << generateHash("Hey") << std::endl;
	std::cout << "2:" << generateHash("Gey") << std::endl;
	std::cout << "3:" << generateHash("Way") << std::endl;
	std::cout << "4:" << generateHash("Heys") << std::endl;
	std::cout << "5:" << generateHash("Hi") << std::endl;

}

emrickgjTrends::~emrickgjTrends(){

}

/**
* Increase the count of the given string
*/
void emrickgjTrends::increaseCount(std::string search, int num){

}

/**
* Returns the count of words for a given string
*/
int emrickgjTrends::getCount(std::string search){
	return 0;
}

/**
* Return the string representation of the "Nth" popular item
*/
std::string emrickgjTrends::getNthPopular(int key){
	return "";
}

/**
* Get the number of entries in the overall hashtable, UNIQUE ones
*/
int emrickgjTrends::numEntries(){
	return numOfEntries;
}

/**
* Generate the Hash based on the String value given
*/
int emrickgjTrends::generateHash(std::string value){

	unsigned int hash = 0;
	unsigned int strLength = strlen(value.c_str());
	for(int i = 0; i < strLength; i++){
		//Start accumlating the hash for each value in the array
		hash = 257 * hash + value[i]; //Using a very large prime number to make these unique!
	}

	return hash ^ (hash >> 16);
}

/**
* Find the data with the given key, if no such data exists, through an exception
*/
emrickgjTrends::Data* emrickgjTrends::find(int key){
	//throw "Oopsie";

	return new Data();
}

