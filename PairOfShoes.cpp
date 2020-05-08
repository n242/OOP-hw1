#include "PairOfShoes.h"
#include <iostream> // IO
#include <string>


namespace OOP_Hw1 {

	// check if const 
	void PairOfShoes::SetPrice(double newPrice) {
		if (newPrice > 0) {
			this->price = newPrice;
		}
		else {
			std::cout << "error price" << std::endl;
			this->price = ZERO;
		}
	}

	double PairOfShoes::GetPrice() const {
		return this->price;
	}

	const std::string& PairOfShoes::GetName() const {
		return this->name;
	}
}