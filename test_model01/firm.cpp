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