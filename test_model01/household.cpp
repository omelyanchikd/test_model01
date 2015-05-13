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

void household::buy(vector<double> probabilities, vector<firm*> firms)
{
	//if (budget 
}