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
	household(double _money);

	void fire();

	void decide();

	firm* find_work(map<firm*, double> probabilities);

	firm* buy(map<firm*, double> probabilities);
	firm* buy(double &capacity, double &consumption, double &budget, map<firm*, double> probabilities);


private:
	
	double money;

	firm *employer;
	double salary;

	bool employed;

	double consumption_budget;
	double consumption;
	double consumption_capacity;
};

