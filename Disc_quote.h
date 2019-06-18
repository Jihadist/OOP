#pragma once
#include "Quote.h"
class Disc_quote :
	public Quote
{
public:
	Disc_quote()=default;
	Disc_quote(const std::string &book,double price,size_t qty,double disc):
	Quote(book,price),quantity(qty),discount(disc){};
	Disc_quote(const Disc_quote&);
	Disc_quote(Disc_quote &&) noexcept;
	Disc_quote& operator=(const Disc_quote&);
	Disc_quote& operator=(Disc_quote&&) noexcept;
	double net_price(size_t) const = 0;
protected:
	size_t quantity = 0;
	double discount = 0.0;
};

