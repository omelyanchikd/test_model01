#pragma once
#include "firm_director.h"
class good_director :
	public firm_director
{
public:
	good_director(void);
	~good_director(void);

	void produce(int workers, double labor_productivity, double raw_labor_productivity, double &raw, double raw_productivity, double &capital, double capital_productivity, double amortization, double &quantity);

};

