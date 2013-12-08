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
		1610612741}; //Size is 26


emrickgjTrends::emrickgjTrends(){
	numOfEntries = 0;
	numCollisions = 0;
	dummyNode = new Data();
	dummyNode -> nextPopularKey = -1;
	dummyNode -> lastPopularKey = -1;
	mainTableSize = 97;
	collisionTableSize = 53;
	mainTable = new Data[97];
	collisionTable = new Data[53];

	dummyNode -> data = (std::string)"-1";

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

	//std::cout << "Size: " << numOfEntries << " Search: " << search << " CollisionSize: " << numCollisions << std::endl;

	int hash = generateHash(search);

	if(mainTable[hash].data != search){
		//Search Collision Table!

		//If data is -1, or was 'deleted'
		if(mainTable[hash].data == "-1" || mainTable[hash].data == ""){

			mainTable[hash].data = search;
			mainTable[hash].frequency = num;
			mainTable[hash].nextCollisionKey = -1;
			mainTable[hash].nextPopularKey = -1;
			mainTable[hash].lastCollisionKey = -1;
			mainTable[hash].lastPopularKey = -1;
			mainTable[hash].table = 0;
			mainTable[hash].key = hash;
			numOfEntries++;
			insertNthPopular(&mainTable[hash]);

			if(numOfEntries+1 >= mainTableSize){
				//std::cout << "Am I growing?" << std::endl;
				//std::cout << "Num Entries: " << numOfEntries << " Main Size: " << mainTableSize << std::endl;
				grow();
			}

		}else{
			//std::cout << "Collision!";

			int index = mainTable[hash].nextCollisionKey;
			
			
			//std::cout << "Index" << index;

			//If the hash hasn't had a collision yet
			if(index == -1){
				//std::cout << "In loop" << std::endl;
				int index = addToTable(search, num);

				mainTable[hash].nextCollisionKey = index;
				insertNthPopular(&collisionTable[index]);
				return;
			}

				//std::cout << "Out loop" << std::endl;

			//If the has has a previously existing collision
			while(collisionTable[index].nextCollisionKey != -1){
				index = collisionTable[index].nextCollisionKey;
				if(collisionTable[index].data == search){
					collisionTable[index].frequency += num;
					updateNthPopular(&collisionTable[index]);
					return;
				}
			}

			int tempIndex = addToTable(search, num);

			//If it resized and no longer goes in the collision table
			if(tempIndex == -1) return;

			collisionTable[index].nextCollisionKey = tempIndex;
			insertNthPopular(&collisionTable[tempIndex]);
			return;
			

		}

	}else{

		//If there was no collision, simply update this data
		mainTable[hash].frequency += num;
		updateNthPopular(&mainTable[hash]);


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
		collisionTable[numCollisions].frequency = count;
		collisionTable[numCollisions].nextCollisionKey = -1;
		collisionTable[numCollisions].nextPopularKey = -1;
		collisionTable[numCollisions].lastCollisionKey = -1;
		collisionTable[numCollisions].lastPopularKey = -1;
		collisionTable[numCollisions].table = 1;
		collisionTable[numCollisions].key = numCollisions;
		return numCollisions;

	}



}
 
/**
* Returns the count of words for a given string
*/
int emrickgjTrends::getCount(std::string search){

	int hash = generateHash(search);

	if(mainTable[hash].data == search){
		return mainTable[hash].frequency;
	}else{
		int index = mainTable[hash].nextCollisionKey;

		while(true){
			if(index == -1) return -1;
			if(collisionTable[index].data == search) return collisionTable[index].frequency;

			index = collisionTable[index].nextCollisionKey;

		}

	}

	return 0;
}

/**
* Return the string representation of the "Nth" popular item
*/
std::string emrickgjTrends::getNthPopular(int key){

	Data* temp = (dummyNode -> nextPopularTable == 0)? &mainTable[dummyNode -> nextPopularKey] : &collisionTable[dummyNode -> nextPopularKey];
	if(temp -> data == "-1") return NULL;
	if(key >= numEntries()/2){ //Start from end

		temp = (dummyNode -> lastPopularTable == 0)? &mainTable[dummyNode -> lastPopularKey] : &collisionTable[dummyNode -> lastPopularKey];

		for(int i = numEntries()-key; i < key; i++){
			if(temp -> lastPopularKey == -1) return ""; //This shouldn't happen
			temp = (temp -> lastPopularTable == 0)? &mainTable[temp -> lastPopularKey] : &collisionTable[temp -> lastPopularKey];
		}

		return temp -> data;
	}else{

		for(int i = 0; i < key; i++){
			if(temp -> nextPopularKey == -1) return "";
			temp = (temp -> nextPopularTable == 0)? &mainTable[temp -> nextPopularKey] : &collisionTable[temp -> nextPopularKey];
		}


	}
	return temp -> data;


}

/**
* Get the number of entries in the overall hashtable, UNIQUE ones
*/
int emrickgjTrends::numEntries(){
	return numOfEntries + numCollisions;
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

void emrickgjTrends::insertNthPopular(Data* item){
	if(dummyNode -> nextPopularKey == -1){
		dummyNode -> nextPopularKey = item -> key;
		dummyNode -> nextPopularTable = item -> table;
		dummyNode -> lastPopularKey = item -> key;
		dummyNode -> lastPopularTable = item -> table;
		//std::cout << "I should run once: 1" << std::endl;
		return;
	}else{

		if(dummyNode -> nextPopularKey == dummyNode -> lastPopularKey){
			//std::cout << "I should run once 2" << std::endl;
			Data* temp = (dummyNode -> nextPopularTable == 0)? &mainTable[dummyNode -> nextPopularKey] : &collisionTable[dummyNode -> nextPopularKey];

			if(item -> frequency > temp -> frequency){
				dummyNode -> nextPopularKey = item -> key;
				dummyNode -> nextPopularTable = item -> table;

				item -> lastPopularKey = temp -> key;
				item -> lastPopularTable = temp -> table;

				temp -> nextPopularKey = item -> key;
				temp -> nextPopularTable = item -> table;
				//std::cout << "I should run once 3" << std::endl;

				return;
			}else{
				dummyNode -> lastPopularKey = item -> key;
				dummyNode -> lastPopularTable = item -> table;

				item -> nextPopularKey = temp -> key;
				item -> nextPopularTable = temp -> table;

				temp -> lastPopularKey = item -> key;
				temp -> lastPopularTable = item -> table;

				//std::cout << "I should run once 4" << std::endl;

				return;
			}

		}else{//Size is greater than 1!

			Data* temp = (dummyNode -> lastPopularTable == 0)? &mainTable[dummyNode -> lastPopularKey] : &collisionTable[dummyNode -> lastPopularKey];
			//std::cout << "Temp Table: " << temp.table << " Temp Key: " << temp.key << " Temp Last Table: " << temp.lastPopularTable << " Temp Last Key: " << temp.lastPopularKey << std::endl;
			while(true){

				//std::cout << "Temp key: " << temp.key << " Temp Freq: " << temp.frequency << " Item key: " << item.key << " Item Freq: " << item.frequency << std::endl;

				if(temp -> frequency >= item -> frequency){
					//std::cout << "Swap" << std::endl;
					if(temp -> lastPopularKey == -1){
						//std::cout << "Min" << std::endl;
						dummyNode -> lastPopularKey = item ->key;
						dummyNode -> lastPopularTable = item ->table;
					}

					//std::cout << "Temp Last Pop: " << temp.lastPopularKey << " Temp Last PopTab: " << temp.lastPopularTable << std::endl;
					//std::cout << "Item Last Pop: " << item.lastPopularKey << " Item Last PopTab: " << item.lastPopularTable << std::endl;

					item -> lastPopularKey = temp -> lastPopularKey;
					item -> lastPopularTable = temp -> lastPopularTable;

					if(temp -> lastPopularKey != -1){
						Data temp2 = (temp -> lastPopularTable == 0)? mainTable[temp -> lastPopularKey] : collisionTable[temp -> lastPopularKey];

						temp2.nextPopularKey = item -> key;
						temp2.nextPopularTable = item -> table;

					}

					temp -> lastPopularKey = item -> key;
					temp -> lastPopularTable = item -> table;

					item -> nextPopularKey = temp -> key;
					item -> nextPopularTable = temp -> table;

					//std::cout << "2Temp Last Pop: " << temp.lastPopularKey << " 2Temp Last PopTab: " << temp.lastPopularTable << std::endl;
					//std::cout << "2Item Last Pop: " << item.lastPopularKey << " 2Item Last PopTab: " << item.lastPopularTable << std::endl;


					return;
				}else{
					if(temp -> nextPopularKey == -1){
						//std::cout << "Max" << std::endl;
						//New max (unlikely)

						dummyNode -> nextPopularKey = item -> key;
						dummyNode -> nextPopularTable = item -> table;

						//std::cout << "Temp Last Pop: " << temp.lastPopularKey << " Temp Last PopTab: " << temp.lastPopularTable << std::endl;
						//std::cout << "Item Last Pop: " << item.lastPopularKey << " Item Last PopTab: " << item.lastPopularTable << std::endl;

						item -> lastPopularKey = temp -> key;
						item -> lastPopularTable = temp -> table;
						 
						temp -> nextPopularKey = item -> key;
						temp -> nextPopularTable = item -> table;


						//std::cout << "2Temp Last Pop: " << temp.lastPopularKey << " 2Temp Last PopTab: " << temp.lastPopularTable << std::endl;
						//std::cout << "2Item Last Pop: " << item.lastPopularKey << " 2Item Last PopTab: " << item.lastPopularTable << std::endl;
						return;

					}


					
				}
					temp = (temp -> nextPopularTable == 0)? &mainTable[temp -> nextPopularKey] : &collisionTable[temp -> nextPopularKey];
					//std::cout << "It!" <<std::endl;
			}
		}
		

	}
}

void emrickgjTrends::updateNthPopular(Data* item){
	//std::cout <<"My table is: " << item.table << " My Key is: " << item.key << std::endl;
	//std::cout << "Item next is: " << item.nextPopularKey << " Item last is: " << item.lastPopularKey << " Item data is: " << item.data << std::endl;
}

/**
* Grow the Arrays
*/
void emrickgjTrends::grow(){

	std::cout << "Grow!" << std::endl;

	//First let's get the next prime number
	int i = 0;

	//26 is the array size, we don't want to overshoot (if it gets that big) so less than 25
	for(i = 0; i < 25; i++){
		if(primes[i] == mainTableSize) break;
		//std::cout << "I: " << i << std::endl;
	}
	i++;

	Data* tempMainTable = mainTable;
	int tempMainTableSize = mainTableSize;
	mainTable= new Data[primes[i+1]];
	Data* tempCollisionTable = collisionTable;
	int tempCollisionTableSize = collisionTableSize;
	collisionTable = new Data[primes[i]];
	mainTableSize = primes[i+1];
	collisionTableSize = primes[i];
	delete dummyNode;
	dummyNode = new Data();
	dummyNode -> data = "-1";
	dummyNode -> nextPopularKey = -1;
	dummyNode -> lastPopularKey = -1;
	numOfEntries = 0;
	numCollisions = 0;


	for(int i = 0; i < tempMainTableSize; i++){
		if(tempMainTable[i].data != "-1" && tempMainTable[i].data != ""){
			increaseCount(tempMainTable[i].data, tempMainTable[i].frequency);
		}
	}
	for(int i = 0; i < tempCollisionTableSize; i++){
		if(tempCollisionTable[i].data != "-1" && tempCollisionTable[i].data != ""){
			increaseCount(tempMainTable[i].data, tempMainTable[i].frequency);
		}
	}

	delete[] tempMainTable;
	delete[] tempCollisionTable;


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

