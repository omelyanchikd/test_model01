#include "StdAfx.h"
#include "household.h"


household::household(void)
{
}

void household::fire()
{
	employed = false;
	employer = NULL;
	salary = 0;
}

firm* household::find_work(map<firm*, double> probabilities)
{
	if (employer != NULL)
		salary = employer->get_salary();
	firm* offer = get_random<firm*>(probabilities);
	if (offer->get_salary() > salary && offer->get_needed_workers() > 0)
	{
		if (employer != NULL)
		{
			employer->quit(this);
		}
		employer = offer;
		salary = offer->get_salary();
		offer->hire(this);
	}
	return employer;
}

firm* household::buy(string market_type, map<firm*, double> probabilities)
{
	if (market_type == "labor_market")
		return find_work(probabilities);
	else
		return buy(consumption_budget, probabilities);
}

firm* household::buy(double &budget, map<firm*, double> probabilities)
{
	if (budget == 0)
		return NULL;
	firm* seller = get_random<firm*>(probabilities);
	double quantity = seller->get_quantity();
	double price = seller->get_price();
	if (budget >= quantity * price)
	{
		seller->sell(quantity);
		budget -= quantity * price;
	}
	else
	{
		seller->sell(budget/price);
		budget = 0;
	}
	return seller;
}

double household::get_salary()
{
	return salary;
}