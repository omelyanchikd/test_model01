#include "StdAfx.h"
#include "firm.h"


firm::firm(void)
{
}

firm::firm(string firm_type)
{
	ofstream fout;
	fout.open("log.csv", ios::out | ios::trunc);
	fout<<"pointer"<<", "<<"type"<<", "<<"money"<<", "<<"price"<<", "<<"salary"<<", "<<"sales"<<", "<<"production"<<", "<<"storage"<<", "<<"workers"<<", "<<"labor_capacity"<<", "<<"plan"<<", "<<"capital_investments"<<", "<<"capital_capacity"<<", "<<"raw_investments"<<", "<<"raw_capacity"<<", "<<"profit"<<", "<<"time"<<endl; 
	fout.close();	
    fout.open("sales.csv", ios::out | ios::trunc);
	fout<<"pointer"<<", "<<"type"<<", ""capital"<<", "<<"raw"<<", "<<"time"<<endl; 
	fout.close();	
	sales = 0;
	sold = 0;
	storage = 0;
	capital = 0;
	raw = 0;
	capital_investments = 0;
	raw_investments = 0;
	raw_capacity = 0;
	capital_capacity = 0;
	price = 0;
	production = 0;
	workers.clear();
	type = firm_type;
	time = 0;
	period = 6;
	aproximation = 0.5;
	money = 10000;
	elasticity = -1.5;
	prev_sold = 0;
	prev_plan = 0;
	total_sold = 0;
	plan_coefficient = 1;
	if (type == "raw_firm")
	{
		director = new raw_director();
		labor_productivity = 10;
		raw_labor_productivity = 1;
		capital_productivity = 20;
		salary_budget = 100;
		capital_budget = 5;
		amortization = 0.5;
		plan = 20;
		salary_coefficient = 0.5;
		capital_coefficient = 0.3;
	}
	else
		if (type == "capital_firm")
		{
			director = new capital_director();
			period = 12;
			labor_productivity = 5;
			raw_labor_productivity = 1;
			capital_productivity = 30;
			raw_productivity = 0.5;
			salary_budget = 500;
			raw_budget = 100;
			capital_budget = 500;
			amortization = 0.5;
			plan = 5;
			salary_coefficient = 0.4;
			capital_coefficient = 0.2;
			raw_coefficient = 0.4;
		}
		else
		{
			director = new good_director();
			labor_productivity = 10;
			raw_labor_productivity = 1;
			capital_productivity = 2000;
			raw_productivity = 1;
			salary_budget = 50;
			raw_budget = 10; 
			capital_budget = 5;
			amortization = 0.5;
			plan = 50;
			salary_coefficient = 0.4;
			capital_coefficient = 0.2;
			raw_coefficient = 0.4;
		}
}

void firm::init(float _money, float _labor_productivity, float _raw_labor_productivity, float 
	_capital_productivity, float _amortization, float _raw_productivity, float _salary_coefficient, float _raw_coefficient, float _capital_coefficient, float _aproximation, float _period, float _salary_budget, float _raw_budget, float _capital_budget)
{
	sales = 0;
	sold = 0;
	storage = 0;
	capital = 0;
	raw = 0;
	capital_investments = 0;
	raw_investments = 0;
	raw_capacity = 0;
	capital_capacity = 0;
	price = 0;
	production = 0;
	workers.clear();
	time = 0;
	period = _period;
	aproximation = _aproximation;
	money = _money;
	elasticity = -1.5;
	labor_productivity = _labor_productivity;
	raw_labor_productivity = _raw_labor_productivity;
	capital_productivity = _capital_productivity;
	raw_productivity = _raw_productivity;	
	salary_budget = _salary_budget;
	raw_budget = _raw_budget; 
	capital_budget = _capital_budget;
	amortization = _amortization;
	plan = 10;
	salary_coefficient = _salary_coefficient;
	capital_coefficient = _capital_coefficient;
	raw_coefficient = _raw_coefficient;	
}

void firm::activate(string market_type)
{
	if (market_type == "labor_market")
	{
		set_vacancies();
	}
	else
	{
		ofstream fout;
	    fout.open("sales.csv", ios_base::app);
	    fout<<this<<", "<<type<<", "<<capital<<", "<<raw<<", "<<time<<endl; 
		fout.close();		
		produce();
		storage += production;
		price = pricing();
	}
}

void firm::decide(string market_type)
{
	if (market_type == "raw_market")
	{
		if (type == "good_firm" && capital || type == "capital_firm")
			raw_capacity = (labor_productivity * workers.size() > plan)? plan/raw_productivity: labor_productivity * workers.size()/raw_productivity; //capital_productivity * capital/raw_productivity);
		else
			raw_capacity = 0;
	}
	else
		if (market_type == "capital_market")
		{
			capital_capacity = director->investments(plan, workers.size(), labor_productivity, raw_labor_productivity, capital_productivity, capital_capacity);
		}

}

bool firm::check(string market_type)
{
	if (market_type != "labor_market")
		return (storage >= 0.001);
	return (labor_capacity - workers.size() > 0.001);
}

float firm::get_value(string market_type)
{
	if (market_type != "labor_market")
		return price;
	else
		return salary;
}

void firm::fire()
{
	while (workers.size() > labor_capacity && workers.size())
	{
		int index = rand()/RAND_MAX * (workers.size() - 1);
		workers[index]->fire();
		workers.erase(workers.begin() + index);
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
	labor_capacity = ceil(plan/labor_productivity);
	if (labor_capacity)
		salary = salary_budget/labor_capacity;
	else
		salary = 0;
	if (labor_capacity < workers.size())
		fire();
}

void firm::sell(float quantity)
{
	storage -= quantity;
	sales += quantity * price;
	sold += quantity;	
}

firm* firm::buy(string market_type, map<firm*, float> probabilities)
{
	if (market_type == "raw_market")
		return buy(raw, raw_capacity, raw_budget, raw_investments, probabilities);
	else
		return buy(capital, capital_capacity, capital_budget, capital_investments, probabilities);
}

firm* firm::buy(float &factor, float &capacity, float &budget, float &investments, map<firm*, float> probabilities)
{
	if (factor >= capacity || budget == 0)
		return NULL;
	firm* seller = get_random<firm*>(probabilities);
	float quantity = seller->get_storage();
	float price = seller->get_price();
	float need = capacity - factor;
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
		}//*/
	return seller;
}

void firm::produce()
{
/*	ofstream fout;
	fout.open("log.csv", ios_base::app);
	fout<<raw<<", "<<capital<<", ";
	fout.close();//*/
	director->produce(workers.size(), labor_productivity, raw_labor_productivity, raw, raw_productivity, capital, capital_productivity, amortization, production);
}

float firm::pricing()
{
	return (production > 0)? 1.5/(salary_coefficient + capital_coefficient * amortization + raw_coefficient) * director->pricing(workers.size(), salary, raw_investments, capital_investments, amortization, elasticity, production, price) : director->pricing(workers.size(), salary, raw_investments, capital_investments, amortization, elasticity, production, price);
}

void firm::get_profits()
{
	profit = director->get_profits(workers.size(), salary, sales, raw_investments, capital_investments, amortization);
}

float firm::get_tax(float tax)
{
	if (profit > 0)
	{
		sales -= tax * sales;
		return tax * sales;
	}
	return 0;
}

void firm::write_log()
{
	ofstream fout;
	fout.open("log.csv", ios_base::app);
	fout<<this<<", "<<type<<", "<<money<<", "<<price<<", "<<salary<<", "<<sales<<", "<<production<<", "<<storage<<", "<<workers.size()<<", "<<labor_capacity<<", "<<plan<<", "<<capital_investments<<", "<<capital_capacity<<", "<<raw_investments<<", "<<raw_capacity<<", "<<profit<<", "<<time<<endl; 
	fout.close();
}

void firm::learn()
{	
	if (time)
	{		
		if (type == "capital_firm")
		{
			if (sold >= prev_sold && sold >= production && production >= plan)
				plan = 1.1 * abs(plan - prev_plan);
			else
				if (sold < prev_sold && sold < production)
					plan = 0.9 * abs(plan - prev_plan);
				else
					plan = abs(plan - prev_plan);//*/
			prev_plan = plan;
			plan = plan_coefficient * plan;
			plan += total_sold * amortization;
			if (storage < sold) plan += sold - storage;
		}
		else
		{
			if (type == "raw_firm")
			{
			if (sold >= prev_sold && sold >= production && production >= 0.99 * plan)
				plan_coefficient = 1.1;
			else
				if (sold < prev_sold && sold < production)
					plan_coefficient = 0.9;	
				else
					plan_coefficient = 1;
			prev_plan = plan;
			plan = plan_coefficient * plan;
			//if (storage < sold) plan += sold - storage;
			}
			else
			{
			if (sold >= prev_sold && sold >= production && production >= 0.99 * plan)
				plan_coefficient = 1.1;
			else
				if (sold < prev_sold && sold < production)
					plan_coefficient = 0.9;	
				else
					plan_coefficient = 1;
			prev_plan = plan;
			plan = plan_coefficient* plan;
			}
		}

	director->learn(sales, salary_coefficient, raw_coefficient, capital_coefficient, salary_budget, raw_budget, capital_budget);
	}
	time++;
	money += profit;
	raw_investments = 0;
	capital_investments -= amortization * capital_investments;
	prev_sold = sold;
	total_sold = (1 - amortization) * total_sold + sold;
	sold = 0;
	sales = 0;


/*	if (plan - storage > 0)
	{
		plan -= storage;
	}
	else
	{
		plan = 0;
	}//*/
}

string firm::parse(float a, float b)
{
	ostringstream buffer;
	buffer << a;
	buffer << " ";
	buffer << b;
	return buffer.str();
}

float firm::get(string parameter)
{
	if (parameter == "price")
		return price;
	if (parameter == "salary")
		return salary;
	if (parameter == "workers")
		return workers.size();
	if (parameter == "sales")
		return sales;
	if (parameter == "profit")
		return profit;
	if (parameter == "labor_capacity")
		return labor_capacity;
	if (parameter == "capital_investments")
		return capital_investments;
	if (parameter == "raw_investments")
		return raw_investments;
	if (parameter == "capital_capacity")
		return capital_capacity;
	if (parameter == "raw_capacity")
		return raw_capacity;
	if (parameter == "sold")
		return sold;
	if (parameter == "production")
		return production;
	if (parameter == "plan")
		return plan;
	if (parameter == "money")
		return money;
}

string firm::get_type()
{
	return type;
}

float firm::get_salary()
{
	return salary;
}

float firm::get_needed_workers()
{
	return (labor_capacity - workers.size());
}

float firm::get_price()
{
	return price;
}

float firm::get_storage()
{
	return storage;
}