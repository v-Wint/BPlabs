#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include "module.h"


Date::Date(std::string str) {
	using namespace std;
	stringstream ss(str);
	string n;
	getline(ss, n, '.');
	day = stoi(n);
	getline(ss, n, '.');
	month = stoi(n);
	getline(ss, n, '.');
	year = stoi(n);
}

std::string Date::getDate() {
	char buf[20];
	snprintf(buf, sizeof(buf), "%02d-%02d-%04d", month, day, year);
	return buf;
};

int Date:: getAgeYears() {
	time_t curr_time = time(NULL);
	tm* tm_local = localtime(&curr_time);
	
	int age = tm_local->tm_year + 1900 - this->year;

	int currentDay = tm_local->tm_mday, 
		currentMonth = tm_local->tm_mon;

	if (currentMonth - this->month > 0)
		return age;
	if (currentMonth - this->month < 0)
		return --age;
	if (currentDay - this->day >= 0)
		return age;
	if (currentDay - this->day < 0)
		return age--;
}

FullName::FullName(std::string fullName) {
	using namespace std;
	stringstream ss(fullName);
	string w;
	getline(ss, w, ' ');
	this->firstName = w;
	getline(ss, w, ' ');
	this->secondName = w;
	getline(ss, w, ' ');
	this->parentName = w;
}
std::string FullName::getFullName() {
	return firstName + ' ' + secondName + ' ' + parentName;
}

std::string Student::getStudentInformation() {
	using namespace std;
	stringstream ss;
	ss << left <<setw(40) << fullName.getFullName() << setw(10) << groupNumber << setw(10) << birthDate.getDate();
	return ss.str();
}

Student* getStudentList(const char* fileName, size_t size) {
	using namespace std;
	ifstream f(fileName);
	Student* studentList = new Student[size];

	// errors check
	if (!f) {
		cerr << "Error: file \"" << fileName << "\" could not be opened" << endl;
		exit(1);
	}

	//read full name, date from csv file, get random group number
	string line, w, fullName, birthDate, groupNumber;
	getline(f, line); //skip the first line
	for (size_t i = 0; (!f.eof()) && (i < size); i++) {
		getline(f, line);
		stringstream ss(line);
		for (size_t i = 0; i < 2; i++)getline(ss, w, ',');	//skip two cols
		fullName = w;
		for (size_t i = 2; i < 9; i++)getline(ss, w, ',');	//skip n cols
		birthDate = w;
		groupNumber = "ip-" + to_string(rand() % 4 + 10);	//random group number
		studentList[i] = Student(fullName, groupNumber, birthDate);
	}
	f.close();
	return studentList;
}

void displayStudentList(Student* studentList, size_t size) {
	for (size_t i = 0; i < size; i++)
		printf("%-3d%s\n", i + 1, studentList[i].getStudentInformation().c_str());
}

Student getTheOldestStudent(Student* studentList, std::string groupNumber, size_t size) {
	Student currStudent, oldestStudent;
	bool f = true;
	for (size_t i = 0; i < size; i++) {
		if (studentList[i].getGroupNumber() != groupNumber)
			continue;

		currStudent = studentList[i];
		printf("%-3d%s\n", i + 1,currStudent.getStudentInformation().c_str());

		if (f) { //first student to compare
			oldestStudent = currStudent; f = false; continue;
		}

		if (currStudent.getBirthDate().getYear() < oldestStudent.getBirthDate().getYear()){
			oldestStudent = currStudent; continue;
		}
		if (currStudent.getBirthDate().getYear() > oldestStudent.getBirthDate().getYear())
			continue;
		
		if (currStudent.getBirthDate().getMonth() < oldestStudent.getBirthDate().getMonth()) {
			oldestStudent = currStudent; continue;
		}
		if (currStudent.getBirthDate().getMonth() > oldestStudent.getBirthDate().getMonth())
			continue;

		if (currStudent.getBirthDate().getDay() < oldestStudent.getBirthDate().getDay()) {
			oldestStudent = currStudent; continue;
		}
	}
	return oldestStudent;
}