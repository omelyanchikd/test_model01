#pragma once

#include <vector>
#include <map>

using namespace std;

double summarize(vector<double> values);

vector<double> allocate(vector<double> values);	

template <class T> map<T, double> allocate(map <T,double> values);	

vector<double> invert(vector<double> values);

template <class T> map<T,double> invert(map <T,double> values);

int get_random(vector<double> probabilities);

template <class T> T get_random(map<T,double> probabilities);

template <class T> double summarize(map<T, double> values)
{
	double sum = 0;
	for (map<T, double>::iterator i = values.begin(); i != values.end(); ++i)
		sum += i->second;
	return sum;
}

template <class T> map<T, double> allocate(map<T, double> values)
{
	map<T, double> allocation;
	double sum = summarize<T>(values);
	for (map<T, double>::iterator i = values.begin(); i != values.end(); ++i)
	{
		allocation[i->first] = (i->second/sum);
	}
	return allocation;
}

template <class T> map<T, double> invert(map<T, double> values)
{
	map<T, double> invert_vector;
	for (map<T, double>::iterator i = values.begin(); i != values.end(); ++i)
	{
		invert_vector[i->first] = (1.0/i->second);
	}
	return invert_vector;
}

template <class T> T get_random(map<T, double> probabilities)
{
	double rand_number = rand()/(double)RAND_MAX;
	if (rand_number == 1)
		return (probabilities.rbegin()->first);
	map<T, double>::iterator index = probabilities.begin();
	double first = 0;
	double last = index->second;
	while (index != probabilities.end()) 
	{
		if (first <= rand_number && rand_number < last)
			return index->first;
		first = last;
		index++;
		last = first + index->second;
	}
	return index->first;
}