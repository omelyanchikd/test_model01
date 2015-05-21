#pragma once

#include "firm.h"
#include "household.h"

#include "labor_market.h"
#include "market.h"

#include <vector>
#include <map>

using namespace std;

class world
{
public:
	world(void);

	void step();

private:

	vector<firm*> firms;
	vector<household*> households;

	market labor_market;
	market raw_market;
	market good_market;
	market capital_market;

};

