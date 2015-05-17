#pragma once

#include "firm.h"
#include "household.h"

#include "generator.h"

#include <vector>
#include <map>

using namespace std;

class raw_market
{
public:
	raw_market(void);

	void buy();
	void sell();

	bool empty();
	void update(firm *seller);

private:

	vector<firm*> sellers;
	vector<firm*> buyers;

	map<firm*, double> probabilities;
};

