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
	void find_work(map <firm*, double> probabilities);
	void buy(map <firm*, double> probabilities);

private:
	
	double money;

	firm *employer;
	double salary;

	bool employed;

	double consumption_budget;
	double consumption_need;

};

