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