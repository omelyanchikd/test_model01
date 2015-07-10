#pragma once
#include "firm_director.h"
class capital_director :
	public firm_director
{
public:
	capital_director(void);
	~capital_director(void);

	void produce(int workers, float labor_productivity, float raw_labor_productivity, float &raw, float raw_productivity, float &capital, float capital_productivity, float amortization, float &quantity);
	
	float pricing(int workers, float salary, float raw_investments, float capital_investments, float amortization, float elasticity, float production, float price);

	float investments(float plan, int workers, float labor_productivity, float raw_labor_productivity, float capital_productivity, float capital_capacity);

	void learn(float sales, float salary_coefficient, float raw_coefficient, float capital_coefficient, float &salary_budget, float &raw_budget, float &capital_budget);

	float get_profits(int workers, float salary, float sales, float raw_investments, float capital_investments, float amortization);
};

