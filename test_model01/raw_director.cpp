#include "StdAfx.h"
#include "raw_director.h"


raw_director::raw_director(void)
{
}


raw_director::~raw_director(void)
{
}

void raw_director::produce(int workers, float labor_productivity, float raw_labor_productivity, float &raw, float raw_productivity, float &capital, float capital_productivity, float amortization, float &quantity)
{
	if (workers)
		quantity = capital_productivity * capital + raw_labor_productivity * (workers - capital_productivity * capital/labor_productivity);
	else
		quantity = 0;
	if (capital)
		capital -= amortization * capital;	
}

float raw_director::pricing(int workers, float salary, float raw_investments, float capital_investments, float amortization, float elasticity, float production, float price)
{
	return ((production > 0)? ((workers * salary + amortization * capital_investments) / production ):price);
}

float raw_director::investments(float plan, int workers, float labor_productivity, float raw_labor_productivity, float capital_productivity, float capital_capacity)
{
	if (plan - raw_labor_productivity * workers > 0 && workers)
		return (labor_productivity * (plan - raw_labor_productivity * workers))/(capital_productivity * (labor_productivity - raw_labor_productivity));
	return capital_capacity;
}

float raw_director::get_profits(int workers, float salary, float sales, float raw_investments, float capital_investments, float amortization)
{
	return (sales - workers * salary - capital_investments * amortization);
}

void raw_director::learn(float sales, float salary_coefficient, float raw_coefficient, float capital_coefficient, float &salary_budget, float &raw_budget, float &capital_budget)
{
	if (sales)
	{
		salary_budget = salary_coefficient * sales;
		capital_budget = capital_coefficient * sales;
	}
}