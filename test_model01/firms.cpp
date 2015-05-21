#include "StdAfx.h"
#include "firms.h"


firms::firms(void)
{
}

firms::firms(vector<firm*> my_firms)
{
	_firms = my_firms;	
}


firms::~firms(void)
{
}

void firms::produce()
{
	for (int i = 0; i < _firms.size(); i++)
		_firms[i]->produce();
}

void firms::learn()
{
	for (int i = 0; i < _firms.size(); i++)
		_firms[i]->learn();
}

firms firms::get_firms(string firm_type)
{
	vector<firm*> type_firms;
	for (int i = 0; i < _firms.size(); i++)
	{
		if (_firms[i]->get_type() == firm_type)
			type_firms.push_back(_firms[i]);
	}
	return firms(type_firms);
}

firms firms::get_firms(string firm_type1, string firm_type2)
{
	vector<firm*> type_firms;
	for (int i = 0; i < _firms.size(); i++)
	{
		if (_firms[i]->get_type() == firm_type1 || _firms[i]->get_type() == firm_type2)
			type_firms.push_back(_firms[i]);
	}
	return firms(type_firms);
}