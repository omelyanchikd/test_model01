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

void household::activate(string market_type)
{
}

void household::decide(string market_type)
{
/*	if (money > 0.6 * salary)
		consumption_budget = money - 0.8 * (money - 0.6 * salary);
	else
		consumption_budget = money;//*/
	consumption = 0;
	consumption_need = 2;
}

agent* household::find_work(map<agent*, double> probabilities)
{
	if (employer != NULL)
		salary = employer->get_salary();
	agent* offer = get_random<agent*>(probabilities);
	if (offer->get_value("labor_market") > salary && offer->check())
	{
		if (employer != NULL)
		{
			employer->quit(this);
		}
		employer = offer;
		salary = offer->get_value("labor_market");
		offer->hire(this);
	}
	return employer;
}

agent* household::buy(string market_type, map<agent*, double> probabilities)
{
	if (market_type == "labor_market")
		return find_work(probabilities);
	else
		return buy(consumption_need, consumption, money, probabilities);
}

agent* household::buy(double &need, double &consumption, double &budget, map<agent*, double> probabilities)
{
	//if (budget == 0 || need = 0)
	if (consumption == need)
		return NULL;
	agent* seller = get_random<agent*>(probabilities);
	double quantity = seller->get_storage();
	double price = seller->get_price();
	if (need - consumption <= quantity)
	{
		seller->sell(need - consumption);
		consumption += need - consumption;
	}
	else
	{
		seller->sell(quantity);
		consumption += quantity;
	}
	/*if (budget >= quantity * price)
	{
		seller->sell(quantity);
		budget -= quantity * price;
	}
	else
	{
		seller->sell(budget/price);
		budget = 0;
	}//*/
	return seller;
}

double household::get_salary()
{
	return salary;
}