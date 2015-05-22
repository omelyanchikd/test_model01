#pragma once

#include <string>

#include <map>

using namespace std;

class agent
{
public:
	agent(void);
	~agent(void);

	virtual agent* buy(string market_type, map<agent*,double> probabilities) = 0;
	virtual agent* find_work(map<agent*, double> probabilities) = 0;

	virtual void activate(string market_type) = 0;
	virtual void decide(string market_type) = 0;
	
	virtual string get_type() = 0;

	virtual double get_quantity() = 0;
	virtual double get_price() = 0;

	virtual double get_needed_workers() = 0;
	virtual double get_salary() = 0;


};

