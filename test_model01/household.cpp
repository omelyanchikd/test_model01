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

void household::find_work(vector<string> vacancies)
{
	if (employer != NULL)
		salary = employer->get_salary();
}