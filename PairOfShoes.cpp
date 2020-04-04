#include "PairOfShoes.h"
#include <iostream> // IO
#include <string>

namespace OOP_Hw1 {

	/*
	class PairOfShoes
	{
		std:: string name;
		double price;

	public:
		// c'tor for pairofshoes
		PairOfShoes(std:: string& name, double price) : name(name), price(price)
		{}

	
		std:: string GetName() const;
	};
	*/
	

	// default c'tor - isn't necessary?

	PairOfShoes::PairOfShoes(const std::string& name, double price)
	{
		name= this->GetName;// check if correct
		// new 
		price = 0.00;
	}

	
	// check if const int or regular int
	void PairOfShoes::SetPrice(double newPrice) {
		if (newPrice > 0)
		{
			this->price = newPrice;
		}
		else
			std::cout << "error price" << std::endl;

	}
	double PairOfShoes::GetPrice() const {
		return this->price;
	}

	const std::string& PairOfShoes::GetName() const {
		return this->name;
	}
}