#include "StdAfx.h"
#include "raw_market.h"


raw_market::raw_market(void)
{
}

void raw_market::sell()
{
	for (int i = 0; i < sellers.size(); i++)
	{
		if (sellers[i]->get_quantity())
			probabilities[sellers[i]] = sellers[i]->get_price();
	}
	probabilities = allocate<firm*>(invert (probabilities));
}

void raw_market::buy()
{
	for (int i = 0; i < buyers.size(); i++)
	{
		while (!empty())
		{
			firm *seller = buyers[i]->buy_raw(probabilities);
			if (seller == NULL)
				break;
			update(seller);
		}
	}
}

void raw_market::update(firm *seller)
{
	if (seller->get_quantity() == 0)
	{
		probabilities.erase(seller);
		probabilities = allocate<firm*>(probabilities);
	}
}


bool raw_market::empty()
{
	return (sellers.empty());
}

