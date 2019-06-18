#include "pch.h"
#include "Disc_quote.h"
#include <iostream>

Disc_quote::Disc_quote(const Disc_quote &dq):Quote(dq),quantity(dq.quantity),discount(dq.discount)
{
	std::clog << "copy constructor" << std::endl;
}

Disc_quote::Disc_quote(Disc_quote &&dq) noexcept:
Quote(std::move(dq)), quantity(std::move(dq.quantity)), discount(std::move(dq.discount))
{
	std::clog << "copy(move) constructor" << std::endl;
}

Disc_quote & Disc_quote::operator=(const Disc_quote &rhs)
{
	if (*this!=rhs)
	{
		Quote::operator=(rhs);
		quantity = rhs.quantity;
		discount = rhs.discount;
	}
	std::clog << "assignment constructor" << std::endl;
	return *this;
	// TODO: вставьте здесь оператор return
}

Disc_quote & Disc_quote::operator=(Disc_quote &&rhs) noexcept
{
	if (*this!=rhs)
	{
		Quote::operator=(rhs);
		quantity = std::move(rhs.quantity);
		discount = std::move(rhs.discount);
	}
	std::clog << "assignment(move) constructor" << std::endl;
	return *this;
	// TODO: вставьте здесь оператор return
}
