#pragma once

#include "household.h"
#include "generator.h"

#include "raw_director.h"
#include "capital_director.h"
#include "good_director.h"

#include "firm_director.h"

#include <vector>
#include <map>

#include <string>
#include <sstream>

using namespace std;

class household;

enum firm_type {raw_firm, capital_firm, good_firm};

class firm
{
public:
	
	firm(void);
	firm(string firm_type);

	void fire();
	void hire(household* worker);
	void quit(household* worker);

	void get_vacancies();
	
	firm* buy_raw(map<firm*, double> probabilities);
	void buy_capital();

	void produce();
	
	void sell_raw(double amount);
	void sell_capital();
	void sell_good();
	
	void get_sales();

	void learn();

	double get_salary();
	double get_needed_workers();
	double get_price();
	double get_quantity();


private:

	firm_type type;
	firm_director *director;

	double money;
	double salary;
	double price;
	double plan;
	
	double raw_budget;
	double capital_budget;
	double salary_budget;

//	double needed_workers;

	double labor_capacity;
	double raw_capacity;
	double capital_capacity;

	double labor_productivity;
	double raw_labor_productivity;
	double raw_productivity;
	double capital_productivity;
	double amortization;

	double elasticity;

	double capital;
	double raw;
	double good;

	double quantity;

	double sales;
	double profit;

	vector<household*> workers;

	string parse(double a, double b);
};

