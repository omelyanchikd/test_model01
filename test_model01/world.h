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
	world(int number_raw, int number_capital, int number_good, int number_household, float money_household);

	void step();
	void change_tax(float new_tax);

	void init(string type, float money, float labor_productivity, float raw_labor_productivity, float capital_productivity, float amortization, float raw_productivity, float salary_coefficient, float raw_coefficient, float capital_coefficient, float aproximation, float period); 

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

	float tax;
	float total_taxes;

	void get_profits();
	void get_profits(string type);

	void taxation();
	
	void write_log();
	void write_log(string type);

	void learn();
	void learn(string type);
};

vector<firm*> append(vector<firm*> old, vector<firm*> neu);

