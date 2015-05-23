#pragma once



#include "firm.h"
#include "household.h"

#include "market.h"

#include <vector>
#include <map>

using namespace std;

class world
{
public:
	world(void);

	void step();

	vector<firm*> get_firms(string firm_type);
	vector<firm*> get_firms(string firm_type1, string firm_type2);

private:

	vector<firm*> firms;
	vector<household*> households;

	market *labor_market;
	market *raw_market;
	market *good_market;
	market *capital_market;

	void learn();
};

