#pragma once

#include "agent.h"

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
	market(string market_type, vector<agent*> _buyers, vector<agent*> _sellers);

	void activate();
	void match();
	void match(string firm_type);

	void buy();
	void sell();

	bool empty();
	void update(agent *seller);

	string get_type();

private:

	string type;

	vector<agent*> sellers;
	vector<agent*> buyers;

	map<agent*, double> probabilities;

	
};

