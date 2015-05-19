#pragma once

#include "firm.h"
#include "household.h"

#include "generator.h"

#include <vector>
#include <map>

using namespace std;

enum market_type{raw_market, capital_market, good_market};

class market
{
public:
	market(void);
	market(string market_type, vector<void*> buyers);
	
	void buy();
	void sell();

	bool empty();
	void update(firm *seller);

private:

	market_type type;

	vector<firm*> sellers;
	vector<void*> buyers;

	map<firm*, double> probabilities;
};

