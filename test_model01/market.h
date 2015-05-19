#pragma once

#include "market_sellers.h"
#include "market_buyers.h"

#include "generator.h"

#include <vector>
#include <map>

using namespace std;

enum market_type{raw_market, capital_market, good_market};

class market
{
public:
	market(void);

	void buy();
	void sell();

	bool empty();
	void update(firm *seller);

private:

	market_type type;

	vector<market_sellers*> sellers;
	vector<market_buyers*> buyers;

	map<market_sellers*, double> probabilities;
};

