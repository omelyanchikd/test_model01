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
