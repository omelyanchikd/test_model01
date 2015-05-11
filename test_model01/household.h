#pragma once

#include "firm.h"

#include <vector>
#include <string>

using namespace std;

class firm;

class household
{
public:
	household(void);

	void fire();
	void find_work(vector<double> probabilities, vector<firm*> firms);

private:
	
	double money;

	firm *employer;
	double salary;

	bool employed;

	int get_random(vector<double> probabilities);
};

