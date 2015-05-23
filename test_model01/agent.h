#pragma once

#include <string>

#include <map>

using namespace std;

class agent
{
public:

	virtual void activate(string market_type) = 0;
	virtual void decide(string market_type) = 0;

	virtual agent* buy(string market_type, map<agent*, double> probabilities) = 0;
	
	virtual string get_type() = 0;

	virtual bool check(string market_type) = 0;

	virtual double get_value(string market_type) = 0;

	virtual double get_storage() = 0;
	virtual double get_price() = 0;

	virtual void sell(double amount) = 0;

	virtual void quit(agent *worker);

};

