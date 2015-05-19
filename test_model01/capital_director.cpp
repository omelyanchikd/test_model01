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
