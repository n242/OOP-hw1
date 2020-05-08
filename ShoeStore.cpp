#include "ShoeStore.h"
#include "ShoeStorage.h"
#include <iostream> // IO
#include <string>

#define DEFAULT_DISCOUNT 0.0

namespace OOP_Hw1
{
	//default c'tor
	ShoeStore::ShoeStore(double discountPercent) {
		this->currentDiscountPrecent = discountPercent;
		this->shoeStorage = shoeStorage;
	}
	
	void ShoeStore:: SetDiscountPercent(int discount) {
		if (discount >= 0 && discount <= 100) {
			this->currentDiscountPrecent = discount;
		}
		else {
			std::cout << "error discount" << std::endl;
		}
	}

	double ShoeStore::GetDiscountPercent() const {
		return this->currentDiscountPrecent;
	}

	void ShoeStore::AddShoes(const std::string& name, double price, int amount) {
		int i = amount;
		while (amount > 0) {
			PairOfShoes newShoe = PairOfShoes(name, price);
			shoeStorage.AddPairOfShoes(newShoe);
			amount--;
		}
	}

	void ShoeStore::RemoveOnePair(const std::string& name) {
		shoeStorage.RemovePairOfShoes(name);
	}

	double ShoeStore::AverageShoePrice() const { //  price of all shoes after discount
		return ( (shoeStorage.AverageShoePrice()) * ((100 - GetDiscountPercent())/100));
	}

	double ShoeStore::GetShoePrice(const std::string& shoeName) const { //after discount
		return ((shoeStorage.GetPrice(shoeName)) * (100 - GetDiscountPercent())/100);
	}
}