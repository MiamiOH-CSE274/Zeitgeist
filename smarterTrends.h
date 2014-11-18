#include "naiveTrends.h"

class smarterTrends : public naiveTrends {
public:
	virtual void increaseCount(std::string s, int amount);
	virtual std::string getNthPopular(unsigned int n);

protected:
	bool isSorted = false;
};