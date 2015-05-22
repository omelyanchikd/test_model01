#pragma once
#include "firm_director.h"
class good_director :
	public firm_director
{
public:
	good_director(void);
	~good_director(void);

	void produce(int workers, double labor_productivity, double raw_labor_productivity, double &raw, double raw_productivity, double &capital, double capital_productivity, double amortization, double &quantity);

	double pricing(int workers, double salary, double raw_investments, double capital_investments, double amortization, double elasticity, double production);

	double investments(int workers, double labor_productivity, double raw_labor_productivity, double capital_productivity, double amortization, double capital, double raw_productivity, double raw);

	void learn(double sales, double salary_coefficient, double raw_coefficient, double capital_coefficient, double &salary_budget, double &raw_budget, double &capital_budget);

};

