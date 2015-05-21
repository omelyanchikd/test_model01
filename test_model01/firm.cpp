#include "StdAfx.h"
#include "firm.h"


firm::firm(void)
{
}

firm::firm(string firm_type)
{
	type = firm_type;
	if (type == "raw_firm")
	{
		director = new raw_director();
	}
	else
		if (type == "capital_firm")
		{
			director = new capital_director();
		}
		else
		{
			director = new good_director();
		}
}

void firm::fire()
{
	while (workers.size() > labor_capacity)
	{
		workers[rand()/RAND_MAX * workers.size()]->fire();
	}
}

void firm::hire(household* worker)
{
	workers.push_back(worker);	
}

void firm::quit(household* worker)
{
	int index = -1;
	for (int i = 0; i < workers.size(); i++)
	{
		if (workers[i] == worker)
		{
			index = i;
			break;
		}
	}
	if (index > -1)
		workers.erase(workers.begin() + index);
}

void firm::get_vacancies()
{
	labor_capacity = plan/labor_productivity;
	salary = salary_budget/labor_capacity;
	if (labor_capacity > workers.size())
		fire();
}

void firm::sell(double amount)
{
	quantity -= amount;
	sales += amount * price;
}

firm* firm::buy(string market_type, map<firm*, double> probabilities)
{
	if (market_type == "raw_market")
		return buy(raw, raw_capacity, raw_budget, probabilities);
	else
		return buy(capital, capital_capacity, capital_budget, probabilities);
}

firm* firm::buy(double &factor, double &capacity, double &budget, map<firm*, double> probabilities)
{
	if (factor == capacity || budget == 0)
		return NULL;
	firm* seller = get_random<firm*>(probabilities);
	double quantity = seller->get_quantity();
	double price = seller->get_price();
	double need = capacity - factor;
	if (quantity >= need && budget >= need * price)
	{
		factor += need;
		budget -= need * price;
		seller->sell(need);
	}
	else
		if (quantity < need && budget >= quantity * price)
		{
			factor += quantity;
			seller->sell(quantity);
			budget -= quantity * price;
		}
		else
		{
			factor += budget/price;
			seller->sell(budget/price);
			budget = 0;
		}
	return seller;
}

void firm::produce()
{
	director->produce(workers.size(), labor_productivity, raw_labor_productivity, raw, raw_productivity, capital, capital_productivity, amortization, quantity);
}

string firm::parse(double a, double b)
{
	ostringstream buffer;
	buffer << a;
	buffer << " ";
	buffer << b;
	return buffer.str();
}

double firm::get_salary()
{
	return salary;
}

double firm::get_needed_workers()
{
	return (labor_capacity - workers.size());
}

double firm::get_price()
{
	return price;
}

double firm::get_quantity()
{
	return quantity;
}