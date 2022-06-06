#pragma once
#include "classes.h"

IndustrialProduct* createIndustrialProductsList(size_t n);
FoodProduct* createFoodProductsList(size_t m);

template <class T>
void displayProductList(T* productList, size_t size) {
	for (size_t i = 0; i < size; i++) {
		productList[i].print();
	}
}

double sumExpiered(FoodProduct* productList, size_t n);

double sumWarehouse(IndustrialProduct* productList, size_t m);
