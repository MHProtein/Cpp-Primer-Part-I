#pragma once
#include <string>

class Sales_item
{
public:
	std::string isbn()
	{
		return ISBN;
	}

private:
	std::string ISBN;
	int price;
	int sales;

};

