#include "StdAfx.h"
#include "good_director.h"


good_director::good_director(void)
{
}


good_director::~good_director(void)
{
}

void good_director::produce(int workers, float labor_productivity, float raw_labor_productivity, float &raw, float raw_productivity, float &capital, float capital_productivity, float amortization, float &quantity)
{
	quantity = min(workers * labor_productivity, raw * raw_productivity, capital * capital_productivity);
	capital -= amortization * capital;
	raw -= quantity/raw_productivity;
}

float good_director::pricing(int workers, float salary, float raw_investments, float capital_investments, float amortization, float elasticity, float production, float price)
{
	return (production > 0)?(workers * salary + amortization * capital_investments + raw_investments) / production :price;
}

float good_director::investments(float plan, int workers, float labor_productivity, float raw_labor_productivity, float capital_productivity, float capital_capacity)
{
	if (workers && plan)
		return (plan/capital_productivity > labor_productivity * workers/capital_productivity)? labor_productivity * workers/capital_productivity : plan/capital_productivity;
	return capital_capacity;
}

float good_director::get_profits(int workers, float salary, float sales, float raw_investments, float capital_investments, float amortization)
{
	return (sales - workers * salary - raw_investments - capital_investments * amortization);
}


void good_director::learn(float sales, float salary_coefficient, float raw_coefficient, float capital_coefficient, float &salary_budget, float &raw_budget, float &capital_budget)
{
	if (sales)
	{
		salary_budget = salary_coefficient * sales;
		raw_budget = raw_coefficient * sales;
		capital_budget = capital_coefficient * sales;
	}
}