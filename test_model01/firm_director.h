#pragma once
class firm_director
{
public:
	firm_director(void);
	~firm_director(void);

	virtual void produce(int workers, double labor_productivity, double raw_labor_productivity, double &raw, double raw_productivity, double &capital, double capital_productivity, double amortization, double &quantity) = 0;
	
	virtual double pricing(int workers, double salary, double raw_investments, double capital_investments, double amortization, double elasticity, double production) = 0;

	virtual void learn(double sales, double salary_coefficient, double raw_coefficient, double capital_coefficient, double &salary_budget, double &raw_budget, double &capital_budget) = 0;
	
	double min(double a, double b, double c);
};

