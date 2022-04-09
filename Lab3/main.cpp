#include <ctime>
#include <string>
#include <Windows.h>
#include "module.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	const char* fileName = "ip12.csv";
	size_t size = 33;

	Student* studentList = getStudentList(fileName, size);

	printf("List of students:\n");
	displayStudentList(studentList, size);

	std::string group = "ip-12";

	printf("\nList of students in %s group:\n", group.c_str());
	Student oldestStudent = getTheOldestStudent(studentList, "ip-12", size);
	printf("\nThe oldest student:\n%s\n", oldestStudent.getStudentInformation().c_str());
	printf("\nAge: %d years", oldestStudent.getBirthDate().getAgeYears());
}
