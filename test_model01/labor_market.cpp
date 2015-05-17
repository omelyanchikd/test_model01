#include "StdAfx.h"
#include "labor_market.h"


labor_market::labor_market(void)
{
}

void labor_market::set_vacancies()
{
	for (int i = 0; i < firms.size(); i++)
	{
		if (firms[i]->get_needed_workers() > 0);
			probabilities[firms[i]] = (firms[i]->get_salary());
	}
	probabilities = allocate<firm*>(probabilities);
}

void labor_market::set_workers()
{
	for (int i = 0; i < households.size(); i++)
	{
		set_vacancies();
		households[i]->find_work(probabilities);
	};
}

