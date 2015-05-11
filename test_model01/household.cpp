#include "StdAfx.h"
#include "household.h"


household::household(void)
{
}

void household::fire()
{
	employed = false;
	employer = NULL;
	salary = 0;
}

void household::find_work(vector<double> probabilities, vector<firm*> firms)
{
	if (employer != NULL)
		salary = employer->get_salary();
	int index = get_random(probabilities);
	if (firms[index]->get_salary() > salary && firms[index]->get_needed_workers() > 0)
	{
		if (employer != NULL)
		{
			employer->quit(this);
		}
		employer = firms[index];
		salary = firms[index]->get_salary();
		firms[index]->hire(this);
	}
}

int household::get_random(vector<double> probabilities)
{
	vector<double> allocation;
	allocation.push_back(0);
	for (int i = 0; i < probabilities.size(); i++)
	{
		allocation.push_back(allocation[i] + probabilities[i]);
	}
	double rand_number = rand()/(double)RAND_MAX;
	if (rand_number == 1)
		return (allocation.size() - 1);
	for (int i = 1; i < allocation.size(); i++)
	{
		if (allocation[i-1] <= rand_number && rand_number < allocation[i])
			return i;
	}	
}