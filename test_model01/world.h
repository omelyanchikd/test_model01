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
	world(int number_raw, int number_capital, int number_good, int number_household, double money_household);

	void step();
	void change_tax(double new_tax);

	void init(string type, double money, double labor_productivity, double raw_labor_productivity, double capital_productivity, double amortization, double raw_productivity, double salary_coefficient, double raw_coefficient, double capital_coefficient, double aproximation, double period); 

	vector<firm*> get_firms();
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
	void get_profits(string type);

	void taxation();
	
	void write_log();
	void write_log(string type);

	void learn();
	void learn(string type);
};

vector<firm*> append(vector<firm*> old, vector<firm*> neu);

