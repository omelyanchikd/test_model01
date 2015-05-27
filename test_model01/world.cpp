#include "StdAfx.h"
#include "world.h"


world::world(void)
{
	tax = 0.2;
	firms.clear();
	households.clear();
	for (int i = 0; i < 5; i++)
		firms.push_back(new firm("raw_firm"));
	for (int i = 0; i < 2; i++)
		firms.push_back(new firm("capital_firm"));
	for (int i = 0; i < 1; i++)
		firms.push_back(new firm("good_firm"));
	for (int i = 0; i < 100; i++)
		households.push_back(new household());
	labor_market = new labormarket(firms, households);
	raw_market = new market("raw_market", get_firms("raw_firm"), get_firms("capital_firm", "good_firm"));
	capital_market = new market("capital_market", get_firms("capital_firm"), firms);
	good_market = new market("good_market", get_firms("good_firm"), households);
	ofstream fout;
	fout.open("taxes.txt", ios::out | ios::trunc);	
	fout.close();	
}

void world::step()
{
	learn("raw_firm");
	learn("good_firm");
	labor_market->activate();
	labor_market->match();
	capital_market->match("raw_firm");
	raw_market->activate();
	capital_market->match("capital_firm");
	get_profits("capital_firm");
	write_log("capital_firm");
	learn("capital_firm");
	raw_market->match("capital_firm");
	capital_market->activate();	
	capital_market->match("good_firm");
	raw_market->match("good_firm");
	good_market->activate();
	good_market->match();
	get_profits("raw_firm");
	get_profits("good_firm");
	write_log("raw_firm");
	write_log("good_firm");
//	taxation();


}

void world::change_tax(double new_tax)
{
	tax = new_tax;
}

void world::taxation()
{
	total_taxes = 0;
	for (int i = 0; i < firms.size(); i++)
		total_taxes += firms[i]->get_tax(tax);
	ofstream fout;
	fout.open("taxes.txt", ios_base::app);
	fout<<total_taxes<<endl;
	fout.close();	
}

void world::get_profits()
{
	for (int i = 0; i < firms.size(); i++)
		firms[i]->get_profits();
}

void world::get_profits(string type)
{
	vector<firm*> chosen = get_firms(type);
	for (int i = 0; i < chosen.size(); i++)
		chosen[i]->get_profits();
}

void world::write_log()
{
	for (int i = 0; i < firms.size(); i++)
		firms[i]->write_log();
}

void world::write_log(string type)
{
	vector<firm*> chosen = get_firms(type);
	for (int i = 0; i < chosen.size(); i++)
		chosen[i]->write_log();
}

void world::learn()
{
	for (int i = 0; i < firms.size(); i++)
		firms[i]->learn();
}

void world::learn(string type)
{
	vector<firm*> chosen = get_firms(type);
	for (int i = 0; i < chosen.size(); i++)
		chosen[i]->learn();
}

vector<firm*> world::get_firms(string firm_type)
{
	vector<firm*> result;
	for (int i = 0; i < firms.size(); i++)
	{
		if (firms[i]->get_type() == firm_type)
			result.push_back(firms[i]);
	}
	return result;
}

vector<firm*> world::get_firms(string firm_type1, string firm_type2)
{
	vector<firm*> result;
	for (int i = 0; i < firms.size(); i++)
	{
		if (firms[i]->get_type() == firm_type1 || firms[i]->get_type() == firm_type2)
			result.push_back(firms[i]);
	}
	return result;
}

