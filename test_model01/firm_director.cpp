#include "StdAfx.h"
#include "firm_director.h"


firm_director::firm_director(void)
{
}


firm_director::~firm_director(void)
{
}

double firm_director::min(double a, double b, double c)
{
	if (a <= b && a <= c)
		return a;
	if (b <= a && b <= c)
		return b;
	if (c <= a && c <= b)
		return c;
	return c;
}