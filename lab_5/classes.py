from datetime import datetime, timedelta


class Product:
    def __init__(self, 
                 name: str, 
                 date: datetime, 
                 price: float, 
                 number: int) -> None:
        self.name = name
        self.date = date
        self.price = price
        self.number = number
    
    def get_cost(self) -> float:
        return self.price * self.number

    @staticmethod
    def compare_dates(date1: datetime, date2: datetime) -> bool:
        return date1 > date2

    def __repr__(self) -> str:
        return "\n".join([f"{x}: {y}" for x, y in self.__dict__.items()]) + "\n"


class IndustrialProduct(Product):
    def __init__(self, 
                 name: str, 
                 date: datetime, 
                 price: float, 
                 number: int, 
                 conditions: str, 
                 location: str) -> None:
        super().__init__(name, date, price, number)
        self.conditions = conditions
        self.location = location


class FoodProduct(Product):
    def __init__(self, 
                 name: str, 
                 date: datetime, 
                 price: float, 
                 number: int, 
                 shelf_life: timedelta) -> None:
        super().__init__(name, date, price, number)
        self.shelf_life = shelf_life
        self.expiery_date = self.date + shelf_life

    def isOutdated(self):
        return self.compare_dates(datetime.now(), self.expiery_date)
