#include "StdAfx.h"
#include "raw_market.h"


raw_market::raw_market(void)
{
}

void raw_market::sell()
{
	vector<double> prices;
	for (int i = 0; i < sellers.size(); i++)
	{
		if (sellers[i]->get_quantity())
			prices.push_back(sellers[i]->get_price());
	}
	probabilities = allocate(invert(prices));
}

void raw_market::buy()
{
	for (int i = 0; i < buyers.size(); i++)
	{
		int bought = -1;
		while (!empty())
		{
			bought = buyers[i]->buy_raw(probabilities, sellers);
			update(bought);
		}
	}
}

void raw_market::update(int bought)
{
	if (sellers[bought]->get_quantity() == 0)
	{
		probabilities.erase(probabilities.begin() + bought);
		probabilities = allocate(probabilities);
	}
}


bool raw_market::empty()
{
	return (sellers.empty());
}

