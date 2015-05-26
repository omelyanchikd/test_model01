#include "StdAfx.h"
#include "capital_director.h"


capital_director::capital_director(void)
{
}


capital_director::~capital_director(void)
{
}

void capital_director::produce(int workers, double labor_productivity, double raw_labor_productivity, double &raw, double raw_productivity, double &capital, double capital_productivity, double amortization, double &quantity)
{
	if (workers)
		quantity = (capital_productivity * capital + raw_labor_productivity * (workers - capital_productivity * capital/labor_productivity) < raw_productivity * raw)? capital_productivity * capital + raw_labor_productivity * (workers - capital_productivity * capital/labor_productivity) : raw_productivity * raw;
	else
		quantity = 0;
	if (capital)
		capital -= amortization * capital;
	raw -= quantity/raw_productivity;
}

double capital_director::pricing(int workers, double salary, double raw_investments, double capital_investments, double amortization, double elasticity, double production, double price)
{
	return ((production > 0)? 1.5 * ((workers * salary + amortization * capital_investments + raw_investments) / production ):price);
}

double capital_director::investments(double plan, int workers, double labor_productivity, double raw_labor_productivity, double capital_productivity, double capital_capacity)
{
	if (plan - raw_labor_productivity * workers > 0 && workers)
		return (labor_productivity * (plan - raw_labor_productivity * workers))/(capital_productivity * (labor_productivity - raw_labor_productivity));
	return capital_capacity;
}

double capital_director::get_profits(int workers, double salary, double sales, double raw_investments, double capital_investments, double amortization)
{
	return (sales - workers * salary - raw_investments - capital_investments * amortization);
}

void capital_director::learn(double sales, double salary_coefficient, double raw_coefficient, double capital_coefficient, double &salary_budget, double &raw_budget, double &capital_budget)
{
	if (sales)
	{
		salary_budget = salary_coefficient * sales;
		raw_budget = raw_coefficient * sales;
		capital_budget = capital_coefficient * sales;
	}
}

