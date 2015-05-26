#pragma once



#include "firm.h"
#include "household.h"

#include "market.h"
#include "labormarket.h"

#include <vector>
#include <map>
#include <fstream>

using namespace std;

class world
{
public:
	world(void);

	void step();
	void change_tax(double new_tax);

	vector<firm*> get_firms(string firm_type);
	vector<firm*> get_firms(string firm_type1, string firm_type2);

private:

	vector<firm*> firms;
	vector<household*> households;

	labormarket *labor_market;
	market *raw_market;
	market *good_market;
	market *capital_market;

	double tax;
	double total_taxes;

	void get_profits();

	void taxation();

	void write_log();

	void learn();
};

