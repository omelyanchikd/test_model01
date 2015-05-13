#include "stdafx.h"
#include "generator.h"

double summarize(vector<double> values)
{
	double sum = 0;
	for (int i = 0; i < values.size(); i++)
		sum += values[i];
	return sum;
}

vector<double> allocate(vector<double> values)
{
	vector<double> allocation;
	double sum = summarize(values);
	for (int i = 0; i < values.size(); i++)
	{
		allocation.push_back(values[i]/sum);
	}
	return allocation;
}

vector<double> invert(vector<double> values)
{
	vector<double> invert_vector;
	for (int i = 0; i < values.size(); i++)
	{
		if (values[i])
			invert_vector.push_back(1/values[i]);
		else
			invert_vector.push_back(0);
	}
	return invert_vector;
}

int get_random(vector<double> probabilities)
{
	vector<double> allocation;
	allocation.push_back(0);
	for (int i = 0; i < probabilities.size(); i++)
	{
		allocation.push_back(allocation[i] + probabilities[i]);
	}
	double rand_number = rand()/(double)RAND_MAX;
	if (rand_number == 1)
		return (allocation.size() - 1);
	for (int i = 1; i < allocation.size(); i++)
	{
		if (allocation[i-1] <= rand_number && rand_number < allocation[i])
			return i;
	}	
}