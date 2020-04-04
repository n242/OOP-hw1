#pragma once

#include "PairOfShoes.h"
#define DEFAULT_INIT_STORAGE_SIZE 4


namespace OOP_Hw1 {
	class ShoeStorage
	{
		PairOfShoes** shoes; // Array of pointers to PairOfShoes. Some of them are NULL
		int arraySize;
	public:
		ShoeStorage(int initStorageSize = DEFAULT_INIT_STORAGE_SIZE);

		//copy c'tor
		ShoeStorage(const ShoeStorage& storage);
		
		//assignment operator
		ShoeStorage& operator=(const ShoeStorage& storage);
		
		void duplicateArr(const PairOfShoes& pair);

		// desctructor for dynmically allocated array
		~ShoeStorage()
		{
			for (int i = 0; i < arraySize; i++)
			{
				delete[]shoes[i];
			}
		}

		void AddPairOfShoes(const PairOfShoes& pair);

		void RemovePairOfShoes(const std::string& shoeName);
		double GetPrice(const std::string& shoeName) const;

		double AverageShoePrice() const;

		static int lastUsed;
	};
}

