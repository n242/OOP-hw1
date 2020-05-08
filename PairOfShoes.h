#pragma once
#define ZERO 0.00
#include <string>

namespace OOP_Hw1 {
	class PairOfShoes
	{
	private:
		const std::string name;
		double price;
	public:
		PairOfShoes(const std::string& name, double price) : name(name), price(price) {};
		const std::string& GetName() const;
		double GetPrice() const;
		void SetPrice(double newPrice = ZERO);


	};
}
