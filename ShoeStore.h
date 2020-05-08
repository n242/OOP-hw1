#pragma once

#include "ShoeStorage.h"

#define DEFAULT_DISCOUNT 0.0

namespace OOP_Hw1 {
	class ShoeStore
	{
	private:
		ShoeStorage shoeStorage;
		double currentDiscountPrecent;
	public:

		// no dynamic allocation or need of applying assignment operator (default is enough), so not applying the
		// big three
		ShoeStore(double discountPercent = DEFAULT_DISCOUNT);

		void SetDiscountPercent(int discount);
		double GetDiscountPercent() const;

		void AddShoes(const std::string& name, double price, int amount = 1);
		void RemoveOnePair(const std::string& name);

		double AverageShoePrice() const;
		double GetShoePrice(const std::string& shoeName) const;

	};
}
