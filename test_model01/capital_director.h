#pragma once
#include "firm_director.h"
class capital_director :
	public firm_director
{
public:
	capital_director(void);
	~capital_director(void);

	void produce(int workers, double labor_productivity, double raw_labor_productivity, double &raw, double raw_productivity, double &capital, double capital_productivity, double amortization, double &quantity);
};

