#include "Trends.h"

class emrickgjTrends : public Trends{
public:

struct Data{
		int key;
		std::string data;
		int nextPopularKey;
		int lastPopularKey;
		int nextCollisionKey;
		int lastCollisionKey;
		int frequency;

};

	int generateHash(std::string string);

	Data find(int key);


	emrickgjTrends();

	virtual ~emrickgjTrends();

	virtual void increaseCount(std::string, int amount);

	virtual int getCount(std::string);

	virtual std::string getNthPopular(int n);

	virtual int numEntries();

	//My Variables go here
	static Data* mainTable;
	static Data* collisionTable;

	static int numOfEntries;
	static int mainTableSize;
	static int numCollisions;
	static int collisionTableSize;

	static Data* dummyNode;
	
};