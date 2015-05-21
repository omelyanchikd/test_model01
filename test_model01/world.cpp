#include "StdAfx.h"
#include "world.h"


world::world(void)
{
}

void world::step()
{
	labor_market.activate();
	labor_market.match();
	capital_market.activate();
	capital_market.match("raw_firm");
/*	raw_firms.produce();
	rawmarket.sell();
	rawmarket.buy(capital_firms);
	capitalmarket.buy(capital_firms);
	capital_firms.produce();
	capitalmarket.sell();
	rawmarket.buy(good_firms);
	capitalmarket.buy(good_firms);
	good_firms.produce();
	goodmarket.sell();
	goodmarket.buy();
	raw_firms.learn();
	good_firms.learn();
	capital_firms.learn();//*/

}