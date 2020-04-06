#include "ShoeStorage.h"
#include <iostream> // IO
#include <string>
//#define DEFAULT_INIT_STORAGE_SIZE 4

//define as interest? 
//int static arraySize =4;
int static lastUsed = 0;



namespace OOP_Hw1 {


	// assignment operator
	//doesn't have to be a member func? 
	ShoeStorage& ShoeStorage:: operator=(const ShoeStorage& other)
	{
		if (this != &other)
		{
			
			delete[] this->shoes;

			// create new pair of shoes as temp - will fix the issue
			this->shoes = new ShoeStorage *[other.arraySize];
			for(int i =0 ; i<other.arraySize; i++)
			{
				this->shoes[i] = other.shoes;
			}

			shoes = other.shoes;

		}
		return *this;
	}

	//copy c'tor
	ShoeStorage::ShoeStorage(const ShoeStorage& other)
	{
		PairOfShoes** shoes = new PairOfShoes*[other.arraySize];
		arraySize = other.arraySize;
	}

	//default c'tor
	//is this necessary? to initialize all to nullptr
	ShoeStorage::ShoeStorage(int initStorageSize)
	{
		arraySize = DEFAULT_INIT_STORAGE_SIZE;
		int static lastUsed = 0;
		int i;
		for (i = 0; i < arraySize; i++)
		{
			shoes[i] = nullptr;
		}
	}
	

	//apply assignment operator here too?
	void ShoeStorage:: AddPairOfShoes(const PairOfShoes& pair)
	{
		
		if (lastUsed == arraySize)
		{
			duplicateArr(pair);
			AddPairOfShoes(pair);
		}
		else
		{
			shoes[lastUsed+1] = new PairOfShoes(pair.GetName() ,pair.GetPrice());
			lastUsed++;
		}

	}

	void ShoeStorage::duplicateArr(const PairOfShoes& pair)
	{
		PairOfShoes** newArr;

		for (int i = 0; i < arraySize; i++)
		{
			newArr[i] = shoes[i];

		}

		for(int i=arraySize; i<2*arraySize; i++)
		{
			newArr[i] = nullptr;
		}
		
		
		arraySize*=2;
		shoes = newArr;

		delete[]newArr;
	}


	void ShoeStorage::RemovePairOfShoes(const std::string& shoeName)
	{
		int tempIndex;
		for (int i = 0; i < lastUsed; i++)
		{
			if((shoes[i]->PairOfShoes::GetName()) == shoeName)
				{
					tempIndex = i;
					for (int j = tempIndex; j <lastUsed; j++)
					{
						shoes[j] = shoes[j+1];
					}
					shoes[lastUsed] = nullptr;
					lastUsed--;
				}
		}
	}
	double ShoeStorage::GetPrice(const std::string& shoeName) const
	{
		for (int i = 0; i < lastUsed; i++)
		{
			if ((shoes[i]->PairOfShoes::GetName()) == shoeName)
			{
				return shoes[i]->PairOfShoes::GetPrice();
			}

			return 0.0;
		}
	}

	double ShoeStorage::AverageShoePrice() const
	{
		double sum = 0.0;
		for (int i = 0; i < lastUsed; i++)
		{
			sum += (shoes[i]->PairOfShoes::GetPrice());
		}

		return (sum / (double)lastUsed);

	}

	//int ShoeStorage:: lastUsed = 0;
	//int ShoeStorage::arraySize = 4;
	//int** ShoeStorage:: shoes = 0;

	
	

}





