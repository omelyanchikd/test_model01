#include "StdAfx.h"
#include "market.h"


market::market(void)
{
}

market::market(string market_type, vector<agent*> _sellers, vector<agent*> _buyers)
{
	type = market_type;
	sellers = _sellers;
	buyers = _buyers;
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
	if (type != "labor_market")
		probabilities = allocate<agent*>(invert<agent*>(probabilities));
	else
		probabilities = allocate<agent*>(probabilities);
}

void market::match()
{
	for (int i = 0; i < buyers.size(); i++)
	{
		if (type != "labor_market")
		{
			buyers[i]->decide(type);
			while (!empty())
			{
				agent *seller = buyers[i]->buy(type, probabilities);
				if (seller == NULL)
					break;
				update(seller);
			}		
		}
		else
		{
			agent *employer = buyers[i]->buy(type, probabilities);
			if (employer != NULL)
				update(employer);
		};
	}
}

void market::match(string firm_type)
{
	for (int i = 0; i < buyers.size(); i++)
	{
		if (buyers[i]->get_type() == firm_type)
		{
			while (!empty())
			{	
				agent *seller = buyers[i]->buy(type, probabilities);
				if (seller == NULL)
					break;
				update(seller);
			}
		}
	}
}

void market::update(agent *seller)
{
	if (!(seller->check(type)))
	{
		probabilities.erase(seller);
		probabilities = allocate<agent*>(probabilities);
	}
}


bool market::empty()
{
	return (sellers.empty());
}

string market::get_type()
{
	return type;
}

