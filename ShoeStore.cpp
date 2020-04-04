#include "ShoeStore.h"

#include <iostream> // IO
#include <string>

//#define DEFAULT_DISCOUNT 0.0

namespace OOP_Hw1
{
	//default c'tor
	ShoeStore::ShoeStore(double discountPercent = DEFAULT_DISCOUNT)
	{
	}

	//copy c'tor - necassary here?
	/*
	ShoeStore::ShoeStore(const ShoeStore& other)
	{
		ShoeStorage shoeStorage = other.shoeStorage;
		double currentDiscountPrecent = other.currentDiscountPercent;
	}
	*/


	void ShoeStore:: SetDiscountPercent(int discount)
	{
		if (discount > 0 && discount < 100)
		{
			this->currentDiscountPrecent = discount;
		}
		else
		{
			std::cout << "error discount" << std::endl;
		}
	}


	double ShoeStore::GetDiscountPercent() const
	{
		return this->currentDiscountPrecent;
	}

	void ShoeStore::AddShoes(const std::string& name, double price, int amount = 1)
	{
		int i = amount;
		while (amount > 0)
		{
			ShoeStorage::AddPairOfShoes(name);
			amount--;

			//
		}
		PairOfShoes::SetPrice(price); // all shoes with same name have the same price
		

	}

	void ShoeStore::RemoveOnePair(const std::string& name)
	{
		ShoeStorage::RemovePairOfShoes(name);
	}

	double ShoeStore::AverageShoePrice() const //  price of all shoes after discount
	{
		//sum all shoes with the same name.
		//divide by number of shoes = lastUsed
		//duplicate by discount/100
	}
	double ShoeStore::GetShoePrice(const std::string& shoeName) const //after discount
	{
		double temp;
		

		return (this->PairOfShoes::GetPrice(shoeName)* GetDiscountPercent/100);
	}
}
