#pragma once

#include "firm.h"

#include <vector>

using namespace std;

class firms
{
public:
	firms(void);
	firms(vector<firm*> my_firms);
	~firms(void);

	void produce();
	void learn();

	firms get_firms(string firm_type);
	firms get_firms(string firm_type1, string firm_type2);

private:
	vector<firm*> _firms;
};

