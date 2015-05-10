#include "StdAfx.h"
#include "labor_market.h"


labor_market::labor_market(void)
{
}

void labor_market::set_vacancies()
{
	vector<double> salaries;
	for (int i = 0; i < firms.size(); i++)
	{
		vacancies.push_back(firms[i]->set_vacancy());
		if (firms[i]->get_needed_workers() > 0)
			salaries.push_back(firms[i]->get_salary());
		else
			salaries.push_back(0);
	}
	probabilities = allocate(salaries);

}

void labor_market::set_workers()
{
	for (int i = 0; i < households.size(); i++)
		households[i]->find_work(vacancies);
}

double labor_market::summarize(vector<double> values)
{
	double sum = 0;
	for (int i = 0; i < values.size(); i++)
		sum += values[i];
	return sum;
}

vector<double> labor_market::allocate(vector<double> values)
{
	vector<double> allocation;
	double sum = summarize(values);
	for (int i = 0; i < values.size(); i++)
	{
		allocation.push_back(values[i]/sum);
	}
	return allocation;
}