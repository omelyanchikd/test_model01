#include "StdAfx.h"
#include "good_director.h"


good_director::good_director(void)
{
}


good_director::~good_director(void)
{
}

void good_director::produce(int workers, double labor_productivity, double raw_labor_productivity, double &raw, double raw_productivity, double &capital, double capital_productivity, double amortization, double &quantity)
{
	quantity = min(workers * labor_productivity, raw * raw_productivity, capital * capital_productivity);
	capital -= amortization * capital;
	raw -= quantity/raw_productivity;
}

double good_director::pricing(int workers, double salary, double raw_investments, double capital_investments, double amortization, double elasticity, double production)
{
	return ((production > 0)?((workers * salary + amortization * capital_investments + raw_investments) / (production * (1 + 1/elasticity))):0);
}

double good_director::investments(double plan, int workers, double labor_productivity, double raw_labor_productivity, double capital_productivity)
{
	return (plan/capital_productivity > labor_productivity * workers/capital_productivity)? labor_productivity * workers/capital_productivity : plan/capital_productivity;
}

void good_director::learn(double sales, double salary_coefficient, double raw_coefficient, double capital_coefficient, double &salary_budget, double &raw_budget, double &capital_budget)
{
	salary_budget = salary_coefficient * sales;
	raw_budget = raw_coefficient * sales;
	capital_budget = capital_coefficient * sales;
}