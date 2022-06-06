from random import choice, randint
from datetime import datetime, timedelta
from classes import FoodProduct, IndustrialProduct

def create_food_products_list(n: int) -> list:
    return [FoodProduct(str(randint(1000, 100000)), 
                              datetime.now() - timedelta(randint(1, 200)),
                              randint(100, 100000) / 100,
                              randint(1, 100),
                              timedelta(days=randint(1, 200)))
            for i in range(1, n+1)]

def create_industrial_products_list(n: int) -> list:
    return [IndustrialProduct(str(randint(1000, 100000)), 
                              datetime.now() - timedelta(randint(1, 200)),
                              randint(1000, 10000000) / 100,
                              randint(1, 100),
                              choice(["Standart", "Fragile", "Something"]),
                              choice(["Warehouse", "Marketplace"]))
            for i in range(1, n+1)]

def display_product_list(product_list: list) -> None:
    for product in product_list:
        print(product)


def sum_expired(food_products: list) -> float:
    sum = 0
    for product in food_products:
        if product.isOutdated():
            sum += product.get_cost()
    return sum

def sum_warehouse(industrial_products: list) -> float:
    sum = 0
    for product in industrial_products:
        if product.location == "Warehouse":
            sum += product.get_cost()
    return sum
