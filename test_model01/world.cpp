#include "StdAfx.h"
#include "world.h"


world::world(void)
{
}

void world::step()
{
	labor_market.activate();
	labor_market.match();
	capital_market.match("raw_firm");
	raw_market.activate();
	capital_market.match("capital_firm");
	raw_market.match("capital_firm");
	capital_market.activate();	
	capital_market.match("good_firm");
	raw_market.match("good_firm");
	good_market.activate();
	good_market.match();
	learn();
}

void world::learn()
{
	for (int i = 0; i < firms.size(); i++)
		firms[i]->learn();
}

vector<firm*> world::get_firms(string firm_type)
{
	vector<firm*> result;
	for (int i = 0; i < firms.size(); i++)
	{
		if (firms[i]->get_type() == firm_type)
			result.push_back(firms[i]);
	}
	return result;
}

vector<firm*> world::get_firms(string firm_type1, string firm_type2)
{
	vector<firm*> result;
	for (int i = 0; i < firms.size(); i++)
	{
		if (firms[i]->get_type() == firm_type1 || firms[i]->get_type() == firm_type2)
			result.push_back(firms[i]);
	}
	return result;
}

