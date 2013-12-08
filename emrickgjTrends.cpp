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
	mainTableSize = 10;
	collisionTableSize = 5;
	mainTable = new Data[10];
	collisionTable = new Data[5];

	dummyNode -> data = (std::string)"";

	std::cout << "1:" << generateHash("Hey") << std::endl;
	std::cout << "2:" << generateHash("Gey") << std::endl;
	std::cout << "3:" << generateHash("Way") << std::endl;
	std::cout << "4:" << generateHash("Heys") << std::endl;
	std::cout << "5:" << generateHash("Hiaasdf") << std::endl;

}

emrickgjTrends::~emrickgjTrends(){
	delete dummyNode;
	delete[] mainTable;
	delete[] collisionTable;
}

/**
* Increase the count of the given string
*/
void emrickgjTrends::increaseCount(std::string search, int num){
	//First search to see if the search term is in my data structure!

	int hash = generateHash(search);

	if(mainTable[hash].data != search){
		//Search Collision Table!

		//If data is -1, or was 'deleted'
		if(mainTable[hash].data == "-1"){

		}else{

			int index = mainTable[hash].nextCollisionKey;

			//If the hash hasn't had a collision yet
			if(index == -1){
				int index = addToTable(search, num);

				mainTable[hash].nextCollisionKey = index;
				insertNthPopular(collisionTable[index]);
				return;
			}

			//If the has has a previously existing collision
			while(collisionTable[index].nextCollisionKey != -1){
				index = collisionTable[index].nextCollisionKey;
			}

			int tempIndex = addToTable(search, num);

			//If it resized and no longer goes in the collision table
			if(tempIndex == -1) return;

			//
			collisionTable[index].nextCollisionKey = tempIndex;
			insertNthPopular(collisionTable[tempIndex]);
			return;
			

		}

	}else{

		//If there was no collision, simply add this data
		mainTable[hash].data = search;
		mainTable[hash].frequency += num;
		insertNthPopular(mainTable[hash]);


	}

}

/**
*
*/
int emrickgjTrends::addToTable(std::string search, int count){

	if(numCollisions+1 >= collisionTableSize){
		emrickgjTrends::grow();
		emrickgjTrends::increaseCount(search, count);
		return -1;
	}else{
		numCollisions++;

		collisionTable[numCollisions].data = search;
		collisionTable[numCollisions].frequency += count;
		return numCollisions;

	}



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
	return "Hey";
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
		hash = 257 * hash + value[i]; //Using a large prime number to make these unique!
	}

	return (hash ^ (hash >> 4)) % mainTableSize;
}

void emrickgjTrends::insertNthPopular(Data item){

}

/**
* Grow the Arrays
*/
void emrickgjTrends::grow(){

}

/**
* Remove a data item (tricky)
*/
void emrickgjTrends::removeItem(Data item){

}



/**
* Find the data with the given key, if no such data exists, through an exception
*/
emrickgjTrends::Data* emrickgjTrends::find(std::string key){
	//throw "Oopsie";

	return NULL;
}

