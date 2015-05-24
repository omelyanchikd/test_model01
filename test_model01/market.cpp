#include "StdAfx.h"
#include "market.h"


market::market(void)
{
}

market::market(string market_type, vector<firm*> _sellers, vector<firm*> _buyers)
{
	type = market_type;
	sellers = _sellers;
	firm_buyers = _buyers;
	probabilities.clear();
}

market::market(string market_type, vector<firm*> _sellers, vector<household*> _buyers)
{
	type = market_type;
	sellers = _sellers;
	household_buyers = _buyers;
	probabilities.clear();
}

void market::activate()
{
	probabilities.clear();
	for (int i = 0; i < sellers.size(); i++)
	{
		sellers[i]->activate(type);
		if (sellers[i]->check(type))
				probabilities[sellers[i]] = sellers[i]->get_value(type);
	}
	probabilities = allocate<firm*>(invert<firm*>(probabilities));
}

void market::match()
{
	if (type == "good_market")
	{
		for (int i = 0; i < household_buyers.size(); i++)
		{
			household_buyers[i]->decide();
			while (!empty())
			{
				firm *seller = household_buyers[i]->buy(probabilities);
				if (seller == NULL)
					break;
				update(seller);
			}		
		}
	}
	else
	{
		for (int i = 0; i < firm_buyers.size(); i++)
		{
			firm_buyers[i]->decide(type);
			while (!empty())
			{
				firm *seller = firm_buyers[i]->buy(type, probabilities);
				if (seller == NULL)
					break;
				update(seller);
			}		
		}
	}
}

void market::match(string firm_type)
{
	for (int i = 0; i < firm_buyers.size(); i++)
	{
		if (firm_buyers[i]->get_type() == firm_type)
		{
			while (!empty())
			{	
				firm *seller = firm_buyers[i]->buy(type, probabilities);
				if (seller == NULL)
					break;
				update(seller);
			}
		}
	}
}

void market::update(firm *seller)
{
	if (!(seller->check(type)))
	{
		probabilities.erase(seller);
		probabilities = allocate<firm*>(probabilities);
	}
}


bool market::empty()
{
	return (probabilities.empty());
}

string market::get_type()
{
	return type;
}

