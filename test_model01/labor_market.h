#pragma once

#include "firm.h"
#include "household.h"

#include <vector>
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

	vector<string> vacancies;

	vector<double> probabilities;

	double summarize(vector<double> values);
	vector<double> allocate(vector<double> values);	

};

