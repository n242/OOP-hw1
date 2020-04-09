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
			this->arraySize = other.arraySize;
			shoes = new PairOfShoes * [arraySize];
			for(int i =0 ; i< this->arraySize; i++)
			{
				shoes[i] = other.shoes[i];
			}
			shoes = other.shoes;
		}
		return *this;
	}

	
//		this->currentNumber = storage.currentNumber;


	//copy c'tor
	ShoeStorage::ShoeStorage(const ShoeStorage& other)
	{
		this->shoes = new PairOfShoes*[other.arraySize];
		this->arraySize = other.arraySize;
	}

	//default c'tor
	//is this necessary? to initialize all to nullptr
	ShoeStorage::ShoeStorage(int initStorageSize)
	{
		arraySize = DEFAULT_INIT_STORAGE_SIZE;
		int static lastUsed = 0;
		int i;
		shoes = new PairOfShoes * [DEFAULT_INIT_STORAGE_SIZE];
		for (i = 0; i < arraySize; i++)
		{
			shoes[i] = nullptr;
		}
	}
	

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
		PairOfShoes** newArr = new PairOfShoes*[arraySize*2];

		for (int i = 0; i < arraySize; i++)
		{
			newArr[i] = shoes[i];

		}

		for(int j=arraySize; j<(2*arraySize); j++)
		{
			newArr[j] = nullptr;
		}
		
		arraySize*=2;
		shoes = newArr;

		for (int i = 0; i < arraySize; i++)
		{
			delete newArr[i];
		}
		
	}


	void ShoeStorage::RemovePairOfShoes(const std::string& shoeName)
	{
		int j;
		for (int i = 0; i < lastUsed; i++)
		{
			if((shoes[i]->PairOfShoes::GetName()) == shoeName)
				{
					j = i;
					while(j<lastUsed)
					{
						PairOfShoes *temp = shoes[j+1];
						j++;
						shoes[j] = temp;
						}
					shoes[lastUsed] = nullptr;
					delete shoes[lastUsed];
					lastUsed--;
				}
		}
	}
	double ShoeStorage::GetPrice(const std::string& shoeName) const
	{
		for (int i = 0; i < lastUsed; i++)
		{
			if ((shoes[i]->GetName()) == shoeName)
			{
				if ((!shoes[i]->GetPrice()))
				{
					std::cout << "error nullptr in shoe" << std::endl;
					return 0.0;
				}
				else
				{
					
					return shoes[i]->GetPrice();
				}
					
			}
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





