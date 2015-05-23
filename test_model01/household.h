#pragma once

#include "agent.h"

#include "firm.h"
#include "generator.h"

#include <vector>
#include <string>

using namespace std;

class firm;

class household: public agent
{
public:
	household(void);

	void fire();

	void activate(string market_type);
	void decide(string market_type);

	agent* find_work(map <agent*, double> probabilities);

	agent* buy(string market_type, map<agent*, double> probabilities);
	agent *buy(double &need, double &consumption, double &budget, map<agent*, double> probabilities);

	double get_salary();

	string get_type() {return "household";};
	bool check(string market_type) {return false;};
	double get_value(string market_type) {return 0;};

	double get_storage() {return 0;};
	double get_price() {return 0;};
	void sell(double amount) {};

private:
	
	double money;

	firm *employer;
	double salary;

	bool employed;

	double consumption_budget;
	double consumption;
	double consumption_need;
};

