#include "StdAfx.h"
#include "raw_director.h"


raw_director::raw_director(void)
{
}


raw_director::~raw_director(void)
{
}

void raw_director::produce(int workers, double labor_productivity, double raw_labor_productivity, double &raw, double raw_productivity, double &capital, double capital_productivity, double amortization, double &quantity)
{
	if (workers)
		quantity = capital_productivity * capital + raw_labor_productivity * (workers - capital_productivity * capital/labor_productivity);
	else
		quantity = 0;
	if (capital)
		capital -= amortization * capital;	
}

double raw_director::pricing(int workers, double salary, double raw_investments, double capital_investments, double amortization, double elasticity, double production, double price)
{
	return ((production > 0)? 1.5 * ((workers * salary + amortization * capital_investments) / production ):price);
}

double raw_director::investments(double plan, int workers, double labor_productivity, double raw_labor_productivity, double capital_productivity, double capital_capacity)
{
	if (plan - raw_labor_productivity * workers > 0 && workers)
		return (labor_productivity * (plan - raw_labor_productivity * workers))/(capital_productivity * (labor_productivity - raw_labor_productivity));
	return capital_capacity;
}

double raw_director::get_profits(int workers, double salary, double sales, double raw_investments, double capital_investments, double amortization)
{
	return (sales - workers * salary - capital_investments * amortization);
}

void raw_director::learn(double sales, double salary_coefficient, double raw_coefficient, double capital_coefficient, double &salary_budget, double &raw_budget, double &capital_budget)
{
	if (sales)
	{
		salary_budget = salary_coefficient * sales;
		capital_budget = capital_coefficient * sales;
	}
}