#include "emrickgjTrends.h"




/**
*
* Start my Class implementation
*
*/


emrickgjTrends::emrickgjTrends(){
	numOfEntries = 0;
	numCollisions = 0;
	dummyNode = new Data();
	mainTableSize = 0;
	collisionTableSize = 0;
	mainTable = new Data[10];
	collisionTable = new Data[5];

	dummyNode -> data = (std::string)"";
}

emrickgjTrends::~emrickgjTrends(){

}

/**
* Increase the count of the given string
*/
void increaseCount(std::string search, int num){

}

/**
* Returns the count of words for a given string
*/
int getCount(std::string search){
	return 0;
}

/**
* Return the string representation of the "Nth" popular item
*/
std::string getNthPopular(int key){
	return "";
}

/**
* Get the number of entries in the overall hashtable, UNIQUE ones
*/
int numEntries(){
	return emrickgjTrends::numOfEntries;
}

/**
* Generate the Hash based on the String value given
*/
int generateHash(std::string value){
	return -1;
}

/**
* Find the data with the given key, if no such data exists, through an exception
*/
emrickgjTrends::Data* find(int key){
	throw "Oopsie";

	return new emrickgjTrends::Data();
}

