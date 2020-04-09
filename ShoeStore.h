#pragma once

#include "ShoeStorage.h"

#define DEFAULT_DISCOUNT 0.0

namespace OOP_Hw1 {
	class ShoeStore
	{
		ShoeStorage shoeStorage;
		double currentDiscountPrecent;
	public:
		ShoeStore(double discountPercent = DEFAULT_DISCOUNT);

		void SetDiscountPercent(int discount);
		double GetDiscountPercent() const;

		void AddShoes(const std::string& name, double price, int amount = 1);
		void RemoveOnePair(const std::string& name);

		double AverageShoePrice() const;
		double GetShoePrice(const std::string& shoeName) const;

		//copy c'tor
		ShoeStore(const ShoeStore& other);

		//assignment operator
		ShoeStore& operator=(const ShoeStore& other);


		//d'tor c'tor
		~ShoeStore()
		{
			delete &shoeStorage;
		}
	};
}

