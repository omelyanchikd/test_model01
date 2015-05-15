#pragma once

#include "firm.h"
#include "household.h"

#include "generator.h"

#include <vector>

using namespace std;

class raw_market
{
public:
	raw_market(void);

	void buy();
	void sell();

	bool empty();
	void update(int bought);

private:

	vector<firm*> buyers;
	vector<firm*> sellers;

	vector<double> probabilities;
};

