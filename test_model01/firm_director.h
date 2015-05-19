#pragma once
class firm_director
{
public:
	firm_director(void);
	~firm_director(void);

	virtual void produce(int workers, double labor_productivity, double raw_labor_productivity, double &raw, double raw_productivity, double &capital, double capital_productivity, double amortization, double &quantity) = 0;

	double min(double a, double b, double c);
};

