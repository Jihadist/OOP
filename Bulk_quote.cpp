#include "pch.h"
#include "Bulk_quote.h"
#include <iostream>

double Bulk_quote::net_price(size_t cnt) const
{
	if (cnt >= quantity)
		return  cnt * (1 - discount)*price;
	else
		return cnt*price;
}

Bulk_quote::Bulk_quote(const Bulk_quote &bq):Quote(bq), quantity(bq.quantity), discount(bq.discount)
{
	std::clog << "copy constructor" << std::endl;
}

Bulk_quote::Bulk_quote(Bulk_quote &&bq) noexcept:
Quote(std::move(bq)), quantity(std::move(bq.quantity)), discount(std::move(bq.discount))
{
	std::clog << "copy(move) constructor";
}

Bulk_quote & Bulk_quote::operator=(const Bulk_quote &rhs)
{
	if (*this != rhs)
	{
		Quote::operator=(rhs);
		quantity = rhs.quantity;
		discount = rhs.discount;
	}
	std::clog << "assign constructor" << std::endl;
	return *this;
	// TODO: вставьте здесь оператор return
}

Bulk_quote & Bulk_quote::operator=(Bulk_quote &&rhs) noexcept
{
	if (*this != rhs)
	{
		Quote::operator=(rhs);
		quantity = std::move(rhs.quantity);
		discount = std::move(rhs.discount);
	}
	std::clog << "assign(move) constructor" << std::endl;
	// TODO: вставьте здесь оператор return
	return *this;
}

void Bulk_quote::debug()
{
	debug();
	this->Quote::debug();
	std::clog << "min_qty: " << quantity << "\t" << "discount: " << discount << "\n";
}
