#include "ShoeStore.h"

#include <iostream> // IO
#include <string>

#define DEFAULT_DISCOUNT 0.0

namespace OOP_Hw1
{
	//default c'tor - necessary?
	ShoeStore::ShoeStore(double discountPercent)
	{
		this->currentDiscountPrecent = discountPercent;
		this->shoeStorage = shoeStorage;
	}

	// copy c'tor
	ShoeStore::ShoeStore(const ShoeStore& other)
	{
		this->shoeStorage = other.shoeStorage;
		this->currentDiscountPrecent = other.currentDiscountPrecent;
	}

	// assignment operator
	//doesn't have to be a member func? 
	ShoeStore& ShoeStore:: operator=(const ShoeStore& other)
	{
		if (this != &other)
		{
			this->shoeStorage = other.shoeStorage;
			this->currentDiscountPrecent = other.currentDiscountPrecent;
		}
		return *this;
	}


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

	void ShoeStore::AddShoes(const std::string& name, double price, int amount)
	{
		int i = amount;
		while (amount > 0)
		{
			PairOfShoes newShoe = PairOfShoes(name, price);
			shoeStorage.AddPairOfShoes(newShoe);
			amount--;

			//
		}
	}

	void ShoeStore::RemoveOnePair(const std::string& name)
	{
		shoeStorage.RemovePairOfShoes(name);
	}

	double ShoeStore::AverageShoePrice() const //  price of all shoes after discount
	{
		
		return shoeStorage.AverageShoePrice() * GetDiscountPercent();

	}
	double ShoeStore::GetShoePrice(const std::string& shoeName) const //after discount
	{
		return (shoeStorage.GetPrice(shoeName)* GetDiscountPercent()/100);
	}
}
