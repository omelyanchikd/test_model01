#pragma once

#include "firm.h"
#include "household.h"

#include "generator.h"

#include <vector>
#include <map>

#include <string>

using namespace std;

class labor_market
{
public:
	labor_market(void);

	void set_vacancies();
	void set_workers();


private:
	vector<household*> households;
	vector<firm*> firms;

	map<firm*, double> probabilities;

};

