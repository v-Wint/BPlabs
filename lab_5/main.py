from classes import FoodProduct, IndustrialProduct
from functions import create_food_products_list, create_industrial_products_list, display_product_list, sum_expired, sum_warehouse

def main():
    food_products = create_food_products_list(int(input("n=")))
    industrial_products = create_industrial_products_list(int(input("m=")))

    print("\nFood products:")
    display_product_list(food_products)

    print("\nIndustrial products:")
    display_product_list(industrial_products)

    print(f"\nCost of expired food products: {sum_expired(food_products):.2f}\n")
    print(f"\nCost of industrial products in warehouse: {sum_warehouse(industrial_products):.2f}\n")


if __name__ == "__main__":
    main()
