#define _CRT_SECURE_NO_WARNINGS
#include "classes.h"
#include <string>

FoodProduct* createFoodProductsList(size_t n) {
	time_t DAY = 24 * 60 * 60;
	std::string conditions[3] = { "Standart", "Fragile", "Something" };
	std::string locations[2] = { "Warehouse", "Marketplace" };

	FoodProduct* foodProductsList = new FoodProduct[n];

	time_t time = std::time(0);

	for (size_t i = 0; i < n; i++) {
		time_t newTime = time - (rand() % 199 + 1) * DAY;
		tm* tmp = std::localtime(&newTime);
		Date date = { tmp->tm_year + 1900, tmp->tm_mon + 1, tmp->tm_mday };

		foodProductsList[i] = FoodProduct(std::to_string(rand() % 99000 + 1000), date, ((rand() % 99900 + 100) / 100.0), rand() % 99 + 1, rand() % 199 + 1);
	}

	return foodProductsList;
}

IndustrialProduct* createIndustrialProductsList(size_t m) {
	time_t DAY = 24 * 60 * 60;
	std::string conditions[3] = { "Standart", "Fragile", "Something" };
	std::string locations[2] = { "Warehouse", "Marketplace"};

	IndustrialProduct* industrialProductsList = new IndustrialProduct[m];

	time_t time = std::time(0);

	for (size_t i = 0; i < m; i++) {
		time_t newTime = time - (rand() % 199 + 1) * DAY;
		tm* tmp = std::localtime(&newTime);
		Date date = { tmp->tm_year + 1900, tmp->tm_mon + 1, tmp->tm_mday };

		industrialProductsList[i] = IndustrialProduct(std::to_string(rand() % 99000 + 1000), date, ((rand() % 9990000 + 1000) / 100.0), rand() % 99 + 1, conditions[rand() % 3], locations[rand() % 2]);
	}

	return industrialProductsList;
}

double sumExpiered(FoodProduct* productList, size_t n) {
	double sum = 0;
	for (size_t i = 0; i < n; i++)
		if (productList[i].isOutdated())
			sum += productList[i].getCost();
	return sum;
}

double sumWarehouse(IndustrialProduct* productList, size_t m) {
	double sum = 0;
	for (size_t i = 0; i < m; i++)
		if (productList[i].getLocation() == "Warehouse")
			sum += productList[i].getCost();
	return sum;
}
