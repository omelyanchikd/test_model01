#include "StdAfx.h"
#include "firm.h"


firm::firm(void)
{
}

void firm::get_workers()
{


}

string firm::set_vacancy()
{
	labor_capacity = plan/labor_productivity;
	if (labor_capacity > workers.size())
	{
		needed_workers = labor_capacity - workers.size();		
	}
	else
	{
		needed_workers = 0;
		fire();
	}
	salary = salary_budget/labor_capacity;
	return parse(salary, needed_workers);
}

void firm::fire()
{
	while (workers.size() > labor_capacity)
	{
		int i = rand()/RAND_MAX * workers.size();
		workers[i]->fire();
	}//*/
}

void firm::hire(household* worker)
{
	workers.push_back(worker);
	needed_workers--;
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

void firm::sell_raw(double amount)
{
	quantity -= amount;
	sales += amount * price;
}

firm* firm::buy_raw(map<firm*, double> probabilities)
{
	if (raw == raw_capacity || raw_budget == 0)
		return NULL;
	firm* seller = get_random(probabilities);
	double raw_quantity = seller->get_quantity();
	double raw_price = seller->get_price();
	double raw_need = raw_capacity - raw;
	if (raw_quantity >= raw_need && raw_budget >= raw_need * raw_price)
	{
		raw += raw_need;
		raw_budget -= raw_need * raw_price;
		seller->sell_raw(raw_need);
	}
	else
		if (raw_quantity >= raw_need && raw_budget < raw_need * raw_price)
		{
			raw += raw_budget/raw_price;
			seller->sell_raw(raw_budget/raw_price);
			raw_budget = 0;
		}
		else
			if (raw_quantity < raw_need && raw_budget >= raw_quantity * raw_price)
			{
				raw += raw_quantity;
				seller->sell_raw(raw_quantity);
				raw_budget -= raw_quantity * raw_price;
			}
			else
			{
				raw += raw_budget/raw_price;
				seller->sell_raw(raw_budget/raw_price);
				raw_budget = 0;
			}
	//recheck cases
	return seller;
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
	return needed_workers;
}

double firm::get_price()
{
	return price;
}

double firm::get_quantity()
{
	return quantity;
}