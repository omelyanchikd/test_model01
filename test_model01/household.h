#pragma once

#include "firm.h"
#include "generator.h"

#include <vector>
#include <string>

using namespace std;

class firm;

class household
{
public:
	household(void);

	void fire();

	void decide();

	firm* find_work(map<firm*, double> probabilities);

	firm* buy(map<firm*, double> probabilities);
	firm* buy(double &need, double &consumption, double &budget, map<firm*, double> probabilities);


private:
	
	double money;

	firm *employer;
	double salary;

	bool employed;

	double consumption_budget;
	double consumption;
	double consumption_need;
};

