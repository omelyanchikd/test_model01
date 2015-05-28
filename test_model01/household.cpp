#include "StdAfx.h"
#include "household.h"


household::household(void)
{
	money = 1000;
	employed = false;
	employer = NULL;
	salary = 0;
}

household::household(double _money)
{
	money = _money;
	employed = false;
	employer = NULL;
	salary = 0;

}

void household::fire()
{
	employed = false;
	employer = NULL;
	salary = 0;
}

void household::decide()
{
/*	if (money > 0.6 * salary)
		consumption_budget = money - 0.8 * (money - 0.6 * salary);
	else
		consumption_budget = money;//*/
	consumption_budget = 0.8 * salary;
	//consumption_budget = 20;
	consumption = 0;
	consumption_need = 2;
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

firm* household::buy(map<firm*, double> probabilities)
{
	return buy(consumption_need, consumption, consumption_budget, probabilities);
}

firm* household::buy(double &need, double &consumption, double &budget, map<firm*, double> probabilities)
{
	//if (budget == 0 || need = 0)
	if (consumption == need)
	//if (budget == 0)
		return NULL;
	firm* seller = get_random<firm*>(probabilities);
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
	}//*/
/*	if (budget >= quantity * price)
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
