#pragma once

#include "household.h"

#include <vector>

#include <string>
#include <sstream>

using namespace std;

class household;

class firm
{
public:
	firm(void);
	
	string set_vacancy();
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

	double get_salary();
	double get_needed_workers();


private:

	double money;
	double salary;
	double price;
	double plan;
	double raw_budget;
	double capital_budget;
	double salary_budget;

	double needed_workers;

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

	string parse(double a, double b);
};

