#pragma once
#include <iostream>


struct Date {
	int year, month, day;

	Date operator+(int days);
};

class Product {
protected:
	std::string name;
	Date date;
	double price;
	int number;
public:
	Product() : name(""), date({ 0, 0, 0 }), price(0), number(0) {}
	Product(std::string name, Date date, double price, int number) : name(name), date(date), price(price), number(number) {}

	void setName(std::string name) { this->name = name; }
	void setDate(Date date) { this->date = date; }
	void setPrice(double price) { this->price = price; }
	void setNumber(int number) { this->number = number; }

	std::string getName() { return name; }
	Date getDate() { return date; }
	double getPrice() { return price; }
	int getNumber() { return number; }

	double getCost() { return price * number; }

	void print() {
		printf("\nName: %s\nDate: %0.2d-%0.2d-%0.2d\nPrice: %.2f\nNumber: %d\n", name.c_str(), date.year, date.month, date.day, price, number);
	}

	bool compareDates(Date date1, Date date2);

};

class IndustrialProduct : public Product {
protected:
	std::string conditions, location;
public:
	IndustrialProduct() : Product(), conditions(""), location("") {}
	IndustrialProduct(std::string name, Date date, double price, int number, std::string conditions, std::string location) : Product(name, date, price, number), conditions(conditions), location(location) {}

	void setConditions(std::string conditions) { this->conditions = conditions; }
	void setLocation(std::string location) { this->location = location; }

	std::string getConditions() { return conditions; }
	std::string getLocation() { return location; }

	void print() {
		Product::print();
		printf("Conditions: %s\nLocation: %s\n", conditions.c_str(), location.c_str());
	}
};

class FoodProduct : public Product {
	int shelfLifeDays;
	Date expieryDate;
public:
	FoodProduct() : Product(), shelfLifeDays(0), expieryDate({0, 0, 0}) {}
	FoodProduct(std::string name, Date date, double price, int number, int shelfLifeDays) : Product(name, date, price, number), shelfLifeDays(shelfLifeDays), expieryDate(date + shelfLifeDays) {}

	void setShelfLife(int shelfLife) { this->shelfLifeDays = shelfLife; this->expieryDate = date + shelfLifeDays; }

	int getShelfLIfeDays() { return shelfLifeDays; }
	Date getExpieryDate() { return expieryDate; }

	void print() {
		Product::print();
		printf("Shelf life: %d days\nExpiery date: %0.2d-%0.2d-%0.2d\n", shelfLifeDays, expieryDate.year, expieryDate.month, expieryDate.day);
	}

	bool isOutdated();
};
