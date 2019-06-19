// OOP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "Bulk_quote.h"
#include "Quote.h"
#include "Basket.h"
#include <iostream>
#include <vector>
#include <algorithm>

double print_total(std::ostream &os,const Quote &item,size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
	return ret;
}

int main()
{
	//Disc_quote tes;
	Quote book1("Chester", 0xBADC0FFE);
	Quote book2("Allah Akbar", 0xDEADBEFF);
	if (book1.net_price() > book2.net_price())
		std::clog << book1.isbn() << std::endl;
	else
		std::clog << book2.isbn() << std::endl;

	Quote testQuote,a,b;
	a = book1;
	a = a;
	Quote c(a);
	Bulk_quote testBulk;
	Bulk_quote sale1("0-201-54748-8", 1337,3, 0.14);
	auto ts = static_cast<Quote> (sale1);
	//auto td = dynamic_cast<Quote> (testBulk);
	//auto td = dynamic_cast<Bulk_quote&>(testQuote);
	print_total(std::cout, book1, 1);
	print_total(std::cout, book2, 1);
	print_total(std::cout, ts, 1);
	print_total(std::cout, sale1, 3);
	//std::clog << "test";
	Bulk_quote bq1;
	Bulk_quote bq2("ss", 2.05, 12, 0.3);
	bq2 = std::move(bq2);
    std::cout << "Hello World!\n";
	std::vector<std::shared_ptr<Quote>> ptrs;
	auto item1 = std::make_shared<Bulk_quote>(sale1);
	auto item2 = std::make_shared<Bulk_quote>("0-201-54848-8", 50, 10, .25);
	auto item3 = std::make_shared<Bulk_quote>("0-211-54848-8", 54, 40, .35);
	ptrs.push_back(std::make_shared<Bulk_quote>(sale1));
	ptrs.push_back(std::make_shared<Bulk_quote>("0-201-54848-8", 50, 10, .25));
	ptrs.push_back(std::make_shared<Bulk_quote>("0-211-54848-8", 54, 40, .35));
	double counter=0.0;
	std::for_each(ptrs.begin(), ptrs.end(), 
		[ptrs,&counter](std::shared_ptr<Quote> i)
	{counter += i->net_price(15);
		std::cout<< i->net_price(15)<<std::endl;});
	std::cout << "Full price is: " << counter<<std::endl;
	Basket set;
	set.add_item(*item1);
	set.add_item(*item2);
	set.add_item(*item3);
	set.total_receipt(std::cout);
	set.print_total(std::cout,book1, 1);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
