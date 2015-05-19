#include "StdAfx.h"
#include "labor_market.h"


labor_market::labor_market(void)
{
}

void labor_market::set_vacancies()
{
	for (int i = 0; i < firms.size(); i++)
	{
		firms[i]->get_vacancies();
		if (firms[i]->get_needed_workers() > 0);
			probabilities[firms[i]] = (firms[i]->get_salary());
	}
	probabilities = allocate<firm*>(probabilities);
}

void labor_market::set_workers()
{
	for (int i = 0; i < households.size(); i++)
	{
		firm *employer = households[i]->find_work(probabilities);
		if (employer != NULL)
			update(employer);
	};
}

void labor_market::update(firm *employer)
{
	if (employer->get_needed_workers() == 0)
	{
		probabilities.erase(employer);
		probabilities = allocate<firm*>(probabilities);
	}
}
