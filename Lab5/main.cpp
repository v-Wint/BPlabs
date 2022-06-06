#include "classes.h"
#include "functions.h"

int main() {
	srand(time(NULL));

	int n, m;

	std::cout << "n= ";  std::cin >> n;
	std::cout << "m= "; std::cin >> m;

	FoodProduct* foodProductList = createFoodProductsList(n);
	IndustrialProduct* industrialProductList = createIndustrialProductsList(m);

	printf("\nFood products: ");
	displayProductList(foodProductList, n);
	
	printf("\nIndustrial products: ");
	displayProductList(industrialProductList, m);

	printf("\nCost of expired food products: %.2f\n", sumExpiered(foodProductList, n));

	printf("\nCost of industrial products in warehouse: %.2f\n", sumWarehouse(industrialProductList, m));
}
