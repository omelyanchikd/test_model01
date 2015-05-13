#include "StdAfx.h"
#include "raw_market.h"


raw_market::raw_market(void)
{
}

void raw_market::sell()
{
	vector<double> prices;
	vector<double> quantity;
	for (int i = 0; i < sellers.size(); i++)
	{
		prices.push_back(sellers[i]->get_price());
		quantity.push_back(sellers[i]->get_quantity());
	}
	probabilities = allocate(invert(prices));
}

void raw_market::buy()
{
	for (int i = 0; i < buyers.size(); i++)
	{
		buyers[i]->buy_raw(probabilities, sellers);
	}
}

