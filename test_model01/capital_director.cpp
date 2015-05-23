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
	quantity = (capital_productivity * capital + raw_labor_productivity * (workers - capital_productivity * capital/labor_productivity) > raw_productivity * raw)? capital_productivity * capital + raw_labor_productivity * (workers - capital_productivity * capital/labor_productivity) : raw_productivity * raw;
	capital -= amortization * capital;
	raw -= quantity/raw_productivity;
}

double capital_director::pricing(int workers, double salary, double raw_investments, double capital_investments, double amortization, double elasticity, double production, double price)
{
	return ((production > 0)?((workers * salary + amortization * capital_investments + raw_investments) / (production * (1 + 1/elasticity))):price);
}

double capital_director::investments(double plan, int workers, double labor_productivity, double raw_labor_productivity, double capital_productivity)
{
	return (labor_productivity * (plan - raw_labor_productivity * workers))/(capital_productivity * (labor_productivity - raw_labor_productivity));
}

void capital_director::learn(double sales, double salary_coefficient, double raw_coefficient, double capital_coefficient, double &salary_budget, double &raw_budget, double &capital_budget)
{
	salary_budget = salary_coefficient * sales;
	raw_budget = raw_coefficient * sales;
	capital_budget = capital_coefficient * sales;
}