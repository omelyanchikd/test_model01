#pragma once

#include "firm.h"
#include "household.h"

#include <vector>

using namespace std;

class raw_market
{
public:
	raw_market(void);

	void buy();
	void sell();

private:

	vector<firm*> buyers;
	vector<firm*> sellers;

	vector<double> probabilities;
};

