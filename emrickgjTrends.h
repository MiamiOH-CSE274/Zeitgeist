#include "Trends.h"

class emrickgjTrends : public Trends{
public:

	emrickgjTrends();

	virtual ~emrickgjTrends();

	virtual void increaseCount(std::string, int amount);

	virtual int getCount(std::string);

	virtual std::string getNthPopular(int n);

	virtual int numEntries();


private:

};