#pragma once
class firm_director
{
public:
	firm_director(void);
	~firm_director(void);

	virtual void produce(int workers, float labor_productivity, float raw_labor_productivity, float &raw, float raw_productivity, float &capital, float capital_productivity, float amortization, float &quantity) = 0;
	
	virtual float pricing(int workers, float salary, float raw_investments, float capital_investments, float amortization, float elasticity, float production, float price) = 0;

	virtual void learn(float sales, float salary_coefficient, float raw_coefficient, float capital_coefficient, float &salary_budget, float &raw_budget, float &capital_budget) = 0;

	virtual float investments(float plan, int workers, float labor_productivity, float raw_labor_productivity, float capital_productivity, float capital_capacity) = 0;

	virtual float get_profits(int workers, float salary, float sales, float raw_investments, float capital_investments, float amortization) = 0;
	
	float min(float a, float b, float c);
};

