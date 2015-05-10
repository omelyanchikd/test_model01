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
	void find_work(vector<string> vacancies);

private:
	
	double money;

	firm *employer;
	double salary;

	bool employed;
};

