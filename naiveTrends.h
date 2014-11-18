#include "Trends.h"

#include <vector>

class naiveTrends : public Trends {
public:
	virtual void increaseCount(std::string s, int amount);
	virtual int getCount(std::string s);
	virtual std::string getNthPopular(unsigned int n);
	virtual unsigned int numEntries();

protected:
	std::vector<std::pair<std::string, int> > wordCountVector;
};