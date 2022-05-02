#ifndef STOCK_H
#define STOCK_H

#include <iostream>
#include <string>

using namespace std;
class Stock
{
private:
	std::string name;
	std::string symbol;
	double price;
public:
	Stock();
	Stock(std::string, std::string, double);
	Stock(const Stock&);
	void display() const;
	std::string getName() const;
	std::string getSymbol() const;
	double getPrice() const;
	int hash(int);
	bool operator ==(const Stock&) const;
	bool operator !=(const Stock&) const;
	bool operator <(const Stock&) const;
	bool operator >(const Stock&) const;
	friend std::ostream& operator <<(std::ostream&, const Stock&);
	friend std::istream& operator >>(std::istream&, Stock&);
};

Stock::Stock()
{
	name = "";
	symbol = "";
	price = 0;
}

Stock::Stock(std::string n, std::string s, double p)
{
	name = p;
	symbol = s;
	price = p;
}

Stock::Stock(const Stock& s)
{
	name = s.name;
	symbol = s.symbol;
	price = s.price;
}

void Stock::display()const
{
	std::cout << getName() << getSymbol() << getPrice() << std::endl;
}

std::string Stock::getName()const
{
	return name;
}

std::string Stock::getSymbol()const
{
	return symbol;
}

double Stock::getPrice()const
{
	return price;
}

bool Stock::operator==(const Stock& rhs) const
{
	return rhs.symbol == symbol;
}

bool Stock::operator!=(const Stock& rhs) const
{
	return !(rhs.symbol == symbol);
}

bool Stock::operator<(const Stock& r) const
{
	return r.symbol < symbol;
}

bool Stock::operator>(const Stock& r) const
{
	return !(r.symbol < symbol);
}

int Stock::hash(int size)
{
	return size % 10;
}

std::ostream& operator <<(std::ostream& os, const Stock& s)
{
	os << s.getName() << std::endl;
	os << s.getSymbol() << std::endl;
	os << s.getPrice() << std::endl;

	return os;
}

std::istream& operator >>(std::istream& is, Stock& s)
{
	is >> s.name;
	is >> s.symbol;
	is >> s.price;
	
	return is;
}
#endif