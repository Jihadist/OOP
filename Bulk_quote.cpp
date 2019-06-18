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

Bulk_quote::Bulk_quote(const Bulk_quote &bq):Disc_quote(bq)
{
	std::clog << "copy constructor" << std::endl;
}

Bulk_quote::Bulk_quote(Bulk_quote &&bq) noexcept:Disc_quote(std::move(bq))
{
	std::clog << "copy(move) constructor";
}

Bulk_quote & Bulk_quote::operator=(const Bulk_quote &rhs)
{
	Disc_quote::operator=(rhs);
	std::clog << "assign constructor" << std::endl;
	return *this;
	// TODO: вставьте здесь оператор return
}

Bulk_quote & Bulk_quote::operator=(Bulk_quote &&rhs) noexcept
{
	Disc_quote::operator=(std::move(rhs));
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
