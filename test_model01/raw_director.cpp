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
	quantity = capital_productivity * capital + raw_labor_productivity * (workers - capital_productivity * capital/labor_productivity);
	capital -= amortization * capital;	
}

double raw_director::pricing(int workers, double salary, double raw_investments, double capital_investments, double amortization, double elasticity, double production, double price)
{
	return ((production > 0)?((workers * salary + amortization * capital_investments) / (production * (1 + 1/elasticity))):price);
}

double raw_director::investments(double plan, int workers, double labor_productivity, double raw_labor_productivity, double capital_productivity)
{
	return (labor_productivity * (plan - raw_labor_productivity * workers))/(capital_productivity * (labor_productivity - raw_labor_productivity));
}


void raw_director::learn(double sales, double salary_coefficient, double raw_coefficient, double capital_coefficient, double &salary_budget, double &raw_budget, double &capital_budget)
{
	salary_budget = salary_coefficient * sales;
	capital_budget = capital_coefficient * sales;
}