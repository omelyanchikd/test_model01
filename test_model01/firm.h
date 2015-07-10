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

	void init(float _money, float _labor_productivity, float _raw_labor_productivity, float 
	_capital_productivity, float _amortization, float _raw_productivity, float _salary_coefficient, float _raw_coefficient, float _capital_coefficient, float _aproximation, float _period, float _salary_budget, float _raw_budget, float _capital_budget);

	void activate(string market_type);
	void decide(string market_type);

	bool check(string market_type);
	float get_value(string market_type);

	void fire();
	void hire(household* worker);
	void quit(household* worker);

	void set_vacancies();

	firm* buy(string market_type, map<firm*, float> probabilities);
	firm* buy(float &factor, float &capacity, float &budget, float &investments, map<firm*, float> probabilities);

	float pricing();
	float get_tax(float tax);

	void produce();
	
	void sell(float quantity);

	void get_profits();

	void write_log();

	void learn();

	string get_type();

	float get(string parameter);

	float get_salary();
	float get_needed_workers();
	float get_price();
	float get_storage();


private:

	string type;
	firm_director *director;

	float money;
	float salary;
	float price;
	float plan;
	
	float raw_budget;
	float capital_budget;
	float salary_budget;

//	float needed_workers;

	float labor_capacity;
	float raw_capacity;
	float capital_capacity;

	float labor_productivity;
	float raw_labor_productivity;
	float raw_productivity;
	float capital_productivity;
	float amortization;

	float elasticity;

	float capital;
	float raw;

	float capital_investments;
	float raw_investments;

	float production;
	float storage;

	float aproximation;
	float period;
	float time;
	vector<float> history;

	float salary_coefficient;
	float raw_coefficient;
	float capital_coefficient;

	float plan_coefficient;

	vector<household*> workers;
	float sold;

	float prev_sold;
	float prev_plan;

	float total_sold;

	float sales;
	float profit;

	string parse(float a, float b);	
};

