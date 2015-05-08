#pragma once

#include "household.h"
#include "labor_market.h"
#include "good_market.h"
#include "capital_market.h"
#include "raw_market.h"

#include <vector>

using namespace std;

class firm
{
public:
	firm(void);
	
	void get_workers();
	void fire();
	
	void buy_raw();
	void buy_capital();

	void produce_raw();
	void produce_capital();
	void produce_good();
	
	void sell_raw();
	void sell_capital();
	void sell_good();
	
	void get_sales();

	void learn();


private:

	double money;
	double salary;
	double price;
	double plan;
	double raw_budget;
	double capital_budget;
	double salary_budget;

	double labor_capacity;
	double raw_capacity;
	double capital_capacity;

	double labor_productivity;
	double raw_productivity;
	double capital_productivity;
	double elasticity;

	double capital;
	double raw;
	double good;


	double sales;
	double profit;

	vector<household*> workers;
	labor_market *labormarket;
	raw_market *rawmarket;
	capital_market *capitalmarket;
	good_market *good_market;

};

