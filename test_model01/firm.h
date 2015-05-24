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
#include <fstream>

using namespace std;

class household;

//enum firm_type {raw_firm, capital_firm, good_firm};

class firm
{
public:
	
	firm(void);
	firm(string firm_type);

	void activate(string market_type);
	void decide(string market_type);

	bool check(string market_type);
	double get_value(string market_type);

	void fire();
	void hire(household* worker);
	void quit(household* worker);

	void set_vacancies();

	firm* buy(string market_type, map<firm*, double> probabilities);
	firm* buy(double &factor, double &capacity, double &budget, double &investments, map<firm*, double> probabilities);

	double pricing();
	void produce();
	
	void sell(double quantity);

	void get_profits();

	void write_log();

	void learn();

	string get_type();

	double get_salary();
	double get_needed_workers();
	double get_price();
	double get_storage();


private:

	string type;
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

	double capital_investments;
	double raw_investments;

	double production;
	double storage;

	double aproximation;
	double period;
	double time;
	vector<double> history;

	double salary_coefficient;
	double raw_coefficient;
	double capital_coefficient;

	vector<household*> workers;
	double sold;

	double sales;
	double profit;

	string parse(double a, double b);	
};

