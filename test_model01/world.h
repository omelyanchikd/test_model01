#pragma once

#include "firm.h"
#include "household.h"

#include "labor_market.h"
#include "raw_market.h"
#include "capital_market.h"
#include "good_market.h"

#include <vector>
#include <map>

using namespace std;

class world
{
public:
	world(void);

	void step();

private:

	vector<firm*> raw_firms;
	vector<firm*> capital_firms;
	vector<firm*> good_firms;
	vector<household*> households;

	labor_market labormarket;
	raw_market rawmarket;
	good_market goodmarket;
	capital_market capitalmarket;

};

