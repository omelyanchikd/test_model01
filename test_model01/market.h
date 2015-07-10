#pragma once

#include "firm.h"
#include "household.h"

#include "generator.h"

#include <vector>
#include <map>

using namespace std;

class market
{
public:
	market(void);
	market(string market_type, vector<firm*> _sellers, vector<firm*> _buyers);
	market(string market_type, vector<firm*> _sellers, vector<household*> _buyers);

	void activate();
	void match();
	void match(string firm_type);

	bool empty();
	void update(firm *seller);

	string get_type();

private:

	string type;

	vector<firm*> sellers;
	vector<firm*> firm_buyers;
	vector<household*> household_buyers;

	map<firm*, float> probabilities;

	
};

