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
	if (type != "labor_market")	
	{		
		for (int i = 0; i < sellers.size(); i++)
		{
			sellers[i]->activate(type);
			if (sellers[i]->get_quantity())
				probabilities[sellers[i]] = sellers[i]->get_price();
		}
		probabilities = allocate<agent*>(invert<agent*>(probabilities));
	}
	else
	{		
		for (int i = 0; i < buyers.size(); i++)
		{
			buyers[i]->activate(type);
			if (buyers[i]->get_needed_workers() > 0)
				probabilities[buyers[i]] = (buyers[i]->get_salary());
		}
		probabilities = allocate<agent*>(probabilities);
	}
}

void market::match()
{
	if (type != "labor_market")
	{
		for (int i = 0; i < buyers.size(); i++)
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
	else
	{
		for (int i = 0; i < sellers.size(); i++)
		{
			agent *employer = sellers[i]->find_work(probabilities);
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

void market::update(agent*seller)
{
	if (seller->get_quantity() == 0)
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

