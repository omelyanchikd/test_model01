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

void firm::activate(string market_type)
{
	if (market_type == "labor_market")
	{
		set_vacancies();
	}
	else
	{
		produce();
		storage += production;
		price = pricing();
	}
}

void firm::decide(string market_type)
{
	if (market_type == "raw_market")
	{
		raw_capacity = min(labor_productivity * workers.size()/raw_productivity, capital_productivity * capital/raw_productivity);
	}
	else
		if (market_type == "capital_market")
		{
			capital_capacity = director->investments(plan, workers.size(), labor_productivity, raw_labor_productivity, capital_productivity);
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

void firm::set_vacancies()
{
	labor_capacity = plan/labor_productivity;
	salary = salary_budget/labor_capacity;
	if (labor_capacity > workers.size())
		fire();
}

void firm::sell(double quantity)
{
	storage -= quantity;
	sales += quantity * price;
	sold += quantity;
}

firm* firm::buy(string market_type, map<firm*, double> probabilities)
{
	if (market_type == "raw_market")
		return buy(raw, raw_capacity, raw_budget, raw_investments, probabilities);
	else
		return buy(capital, capital_capacity, capital_budget, capital_investments, probabilities);
}

firm* firm::buy(double &factor, double &capacity, double &budget, double &investments, map<firm*, double> probabilities)
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
		investments += need * price;
		budget -= need * price;
		seller->sell(need);
	}
	else
		if (quantity < need && budget >= quantity * price)
		{
			factor += quantity;
			seller->sell(quantity);
			investments += quantity * price;
			budget -= quantity * price;
		}
		else
		{
			factor += budget/price;
			seller->sell(budget/price);
			investments += budget;
			budget = 0;
		}
	return seller;
}

void firm::produce()
{
	director->produce(workers.size(), labor_productivity, raw_labor_productivity, raw, raw_productivity, capital, capital_productivity, amortization, production);
}

double firm::pricing()
{
	return director->pricing(workers.size(), salary, raw_investments, capital_investments, amortization, elasticity, production);
}

void firm::learn()
{
	raw_investments = 0;
	if (time < period)
	{
		history.push_back(sold);
		sold = 0;
	}
	else
	{
		plan = aproximation * sold + 1/period * summarize(history);
		history.erase(history.begin());
		history.push_back(sold);
		sold = 0;
	}
	director->learn(sales, salary_coefficient, raw_coefficient, capital_coefficient, salary_budget, raw_budget, capital_budget);
	time++;
}

string firm::parse(double a, double b)
{
	ostringstream buffer;
	buffer << a;
	buffer << " ";
	buffer << b;
	return buffer.str();
}

string firm::get_type()
{
	return type;
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

double firm::get_storage()
{
	return storage;
}