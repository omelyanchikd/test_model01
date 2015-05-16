#pragma once

#include <vector>
#include <map>

class firm;

using namespace std;

double summarize(vector<double> values);

double summarize(map < firm*, double > values);

vector<double> allocate(vector<double> values);	

map<firm*, double> allocate(map <firm*,double> values);	

vector<double> invert(vector<double> values);

map <firm*,double> invert(map <firm*,double> values);

int get_random(vector<double> probabilities);

firm* get_random(map <firm*,double> probabilities);