#pragma once
#include <string>

class Quote
{
public:
	friend bool operator!=(const Quote& lhs, const Quote& rhs);
	Quote() = default;
	Quote(const std::string &book, double sales_price):bookNo(book),price(sales_price){}
	Quote(const Quote&);
	Quote(Quote &&) noexcept;
	Quote& operator=(const Quote&);
	Quote& operator=(Quote&&) noexcept;
	virtual ~Quote() = default;
	std::string isbn() const { return bookNo; };
	virtual double net_price(size_t n=1) const { return  n * price; };
	virtual void debug();

	virtual Quote* clone() const & { return new Quote(*this); }
	virtual Quote* clone() && { return new Quote(std::move(*this)); }
private:
	std::string bookNo;
protected:
	double price = 0.0;
};

double print_total(std::ostream &os, const Quote &item, size_t n);
