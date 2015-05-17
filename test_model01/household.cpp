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

void household::find_work(map<firm*, double> probabilities)
{
	if (employer != NULL)
		salary = employer->get_salary();
	firm* offer = get_random<firm*>(probabilities);
	if (offer->get_salary() > salary && offer->get_needed_workers() > 0)
	{
		if (employer != NULL)
		{
			employer->quit(this);
		}
		employer = offer;
		salary = offer->get_salary();
		offer->hire(this);
	}
}

void household::buy(map<firm*, double> probabilities)
{
	//if (budget 
}