#pragma once
#include "PairOfShoes.h"
#define DEFAULT_INIT_STORAGE_SIZE 4


namespace OOP_Hw1 {
	class ShoeStorage
	{
	private:
		PairOfShoes** shoes; // Array of pointers to PairOfShoes. Some of them are nullptr
		int arraySize;
		int emptySpace = 0;

	public:
		ShoeStorage(int initStorageSize = DEFAULT_INIT_STORAGE_SIZE);
		
		//applying big three rule since allocating memory and using assignment operator

		//copy c'tor
		ShoeStorage(const ShoeStorage& storage);

		//assignment operator
		ShoeStorage& operator=(const ShoeStorage& storage);

		// desctructor for dynmically allocated array
		~ShoeStorage();

		void duplicateArr(); // function to duplicate array size

		void AddPairOfShoes(const PairOfShoes& pair);

		void RemovePairOfShoes(const std::string& shoeName);

		double GetPrice(const std::string& shoeName) const;

		double AverageShoePrice() const;
	};
}
