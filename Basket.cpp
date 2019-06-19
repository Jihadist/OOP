#include "pch.h"
#include "Basket.h"
#include <algorithm>
#include <iostream>


void Basket::add_item(const Quote & sale)
{
	items.insert(std::shared_ptr<Quote>(sale.clone()));
}

void Basket::add_item(Quote && sale)
{
	items.insert(std::shared_ptr<Quote>(std::move(sale.clone())));
}

/*double Basket::print_total(std::ostream & os, const Quote & iter, size_t count) const
{
	double p = iter.net_price(count);
	os << "Temp price is:" << p << std::endl;;
	return p;
}*/

double Basket::total_receipt(std::ostream & os) const
{
	double sum = 0.0;
	for (auto iter = items.cbegin();
		iter != items.cend();
		//iter = std::upper_bound(items.cbegin(),items.cend(),*iter))
		iter = items.upper_bound(*iter))
	{
		//
		std::clog << "total temp price" << print_total(os, **iter, items.count(*iter)) << std::endl;;
		sum += print_total(os, **iter, items.count(*iter));
	}
	os << "Total Sale: " << sum << std::endl;
	return sum;
}
