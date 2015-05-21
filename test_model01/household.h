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
	firm* find_work(map <firm*, double> probabilities);

	firm* buy(string market_type, map<firm*, double> probabilities);
	firm *buy(double &budget, map<firm*, double> probabilities);

	double get_salary();

private:
	
	double money;

	firm *employer;
	double salary;

	bool employed;

	double consumption_budget;
	double consumption_need;

};

