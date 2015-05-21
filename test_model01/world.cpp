#include "StdAfx.h"
#include "world.h"


world::world(void)
{
}

void world::step()
{
	labor_market.activate();
	labor_market.match();
	capital_market.match("raw_firm");
	(_firms.get_firms("raw_firm")).produce();
	raw_market.activate();
	raw_market.match("capital_firm");
	capital_market.match("capital_firm");
	(_firms.get_firms("capital_firm")).produce();
	capital_market.activate();
	raw_market.match("good_firm");
	capital_market.match("good_firm");
	(_firms.get_firms("good_firm")).produce();
	good_market.activate();
	good_market.match();
	_firms.learn();
}

