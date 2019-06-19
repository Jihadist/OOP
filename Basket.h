#pragma once
#include <set>
#include <memory>
#include "Quote.h"

class Basket
{
public:

	/*void add_item(const std::shared_ptr<Quote> &Sale)
	{
		items.insert(Sale);
	}*/
	void add_item(const Quote& sale);
	void add_item(Quote &&sale);
	//double print_total(std::ostream& os, const Quote& iter, size_t count) const;
	double total_receipt(std::ostream &os)const;
private:
	static bool compare(const std::shared_ptr<Quote> lhs,const std::shared_ptr<Quote> rhs)
	{
		return lhs->isbn() < rhs->isbn();
	}
	std::multiset<std::shared_ptr<Quote>, decltype(compare) *> items{ compare };
};

