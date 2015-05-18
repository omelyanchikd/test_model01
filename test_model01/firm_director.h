#pragma once
class firm_director
{
public:
	firm_director(void);
	~firm_director(void);

	void produce(int workers, double labor_productivity, double &raw, double raw_productivity, double &capital, double capital_productivity, double &quantity);
};

