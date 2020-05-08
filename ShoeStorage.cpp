#include <iostream> // IO
#include <string>
#include "ShoeStorage.h"

	namespace OOP_Hw1 {

	//default c'tor
	ShoeStorage::ShoeStorage(int initStorageSize) {
		this->arraySize = initStorageSize;
		this->emptySpace = 0;
		int i;
		this->shoes = new PairOfShoes * [initStorageSize];
		for (i = 0; i < arraySize; i++) {
			shoes[i] = nullptr;
		}
	}

	// assignment operator
	ShoeStorage& ShoeStorage:: operator=(const ShoeStorage& storage) {
		if (this != &storage) {
			delete[] this->shoes;
			this->arraySize = storage.arraySize;
			shoes = new PairOfShoes * [arraySize];
			for (int i = 0; i < this->arraySize; i++) {
				shoes[i] = new PairOfShoes(*storage.shoes[i]);
			}
			this->emptySpace = storage.emptySpace;
		}
		return *this;
	}

	//copy c'tor
	ShoeStorage::ShoeStorage(const ShoeStorage& storage) {
		this->shoes = new PairOfShoes * [storage.arraySize];
		this->arraySize = storage.arraySize;
		this->emptySpace = storage.emptySpace;
		for (int i = 0; i < arraySize; i++) {
			if (storage.shoes[i] != nullptr) {
				shoes[i] = new PairOfShoes(*storage.shoes[i]);
			}
			else { //setting shoes[] in empty spaces to nullptr
				shoes[i] = nullptr;
			}
		}
	}

	//d'tor
	ShoeStorage:: ~ShoeStorage() {
		for (int i = 0; i < arraySize; i++) {
			if (shoes[i] != nullptr) {
				delete shoes[i]; //deleting pointers to pairs of shoes
			}
		}
		delete[] shoes; // deleting pointer to array
	}

	void ShoeStorage::AddPairOfShoes(const PairOfShoes& pair) {
		if (emptySpace == arraySize) { //if array is full, duplicate it and then insert new pair
			duplicateArr();
		}
		shoes[emptySpace] = new PairOfShoes(pair.GetName(), pair.GetPrice());
		emptySpace++;
	}

	void ShoeStorage::duplicateArr() {
		PairOfShoes** newArr = new PairOfShoes * [arraySize * 2];
		for (int i = 0; i < arraySize; i++) {
			newArr[i] = shoes[i];
		}
		for (int j = arraySize; j < (2 * arraySize); j++) {
			newArr[j] = nullptr; // setting empty spaces in array to nullptr
		}
		delete[] shoes; // deleting old array
		arraySize *= 2; //updating new size
		shoes = newArr; //updating pointer - both now point to same memory

	}

	void ShoeStorage::RemovePairOfShoes(const std::string& shoeName) {
		bool deleted = false;
		int j;
		for (int i = 0; i < emptySpace && deleted == false; i++) {
			if ((shoes[i]->GetName()) == shoeName) {
				deleted = true;
				delete shoes[i];
				j = i;
				while (j < emptySpace - 1) { // shifting pairs of shoes in array backwards fill empty space
					shoes[j] = shoes[j + 1];
					shoes[j + 1] = nullptr;
					j++;
				}
				emptySpace--;
			}
		}

	}
	double ShoeStorage::GetPrice(const std::string& shoeName) const {
		for (int i = 0; i < emptySpace; i++) {
			if (shoes[i]->GetName() == shoeName) {
				return shoes[i]->GetPrice();
			}
		}
		return ZERO;
	}

	double ShoeStorage::AverageShoePrice() const {
		double sum = 0.0;
		for (int i = 0; i < emptySpace; i++) {
			sum += (shoes[i]->GetPrice());
		}
		return (sum / (double)emptySpace);
	}
}
