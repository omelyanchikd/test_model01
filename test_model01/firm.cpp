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
	salary = salary_budget/labor_capacity;//*/
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

int firm::buy_raw(vector<double> probabilities, vector<firm*> sellers)
{
	if (raw == raw_capacity || raw_budget == 0)
		return -1;
	int index = get_random(probabilities);
	double raw_quantity = sellers[index]->get_quantity();
	double raw_price = sellers[index]->get_price();
	double raw_need = raw_capacity - raw;
	if (raw_quantity >= raw_need && raw_budget >= raw_need * raw_price)
	{
		raw += raw_need;
		raw_budget -= raw_need * raw_price;
		sellers[index]->sell_raw(raw_need);
	}
	//add other cases
	return index;
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