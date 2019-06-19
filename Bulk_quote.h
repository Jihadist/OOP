#pragma once
#include "Quote.h"
#include "Disc_quote.h"

class Bulk_quote : public Disc_quote {

public:
	friend bool operator!=(const Bulk_quote& lhs, const Bulk_quote& rhs);
	double net_price(size_t n) const override;
	Bulk_quote() = default;
	Bulk_quote(const std::string& book, double price, std::size_t qty, double disc) :
		Disc_quote(book, price,qty,disc) {};
	Bulk_quote(const Bulk_quote&);
	Bulk_quote(Bulk_quote &&) noexcept;
	Bulk_quote& operator=(const Bulk_quote&);
	Bulk_quote& operator=(Bulk_quote&&) noexcept;
	void debug() override;
	Bulk_quote* clone() const & { return new Bulk_quote(*this); }
	Bulk_quote* clone() && { return new Bulk_quote(std::move(*this)); }
private:
	//size_t min_qty = 0;
	//double discount=0.0;
};


