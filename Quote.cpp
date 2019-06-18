#include "pch.h"
#include "Quote.h"
#include <iostream>
#include "Disc_quote.h"

Quote::Quote(const Quote &s):bookNo(s.bookNo),price(s.price)
{
	std::clog << "copy constructor" << std::endl;
}

Quote::Quote(Quote &&s) noexcept:bookNo(std::move(s.bookNo)),price(std::move(s.price))
{
	s.bookNo = nullptr;
	s.price = NULL;
	std::clog << "copy(move) constructor" << std::endl;
}

bool inline operator!=(const Quote& lhs, const Quote& rhs)
{
	return lhs.isbn() != rhs.isbn() && lhs.net_price() != rhs.net_price();
}

Quote & Quote::operator=(const Quote &rhs)
{
	if (*this!=rhs)
	{
		bookNo = rhs.bookNo;
		price = rhs.price;
	}
	std::clog << "assign constructor" << std::endl;
		return *this;
		
	// TODO: вставьте здесь оператор return
}

Quote & Quote::operator=(Quote &&rhs) noexcept
{
	if (this!=&rhs)
	{
		bookNo = std::move(rhs.bookNo);
		price = std::move(rhs.price);
	}
	std::clog << "assign(move) constructor" << std::endl;
	return *this;
	// TODO: вставьте здесь оператор return
}

void Quote::debug()
{
	std::clog << "bookNo: " << bookNo << "\t" << "price: " << price << "\n";
}
