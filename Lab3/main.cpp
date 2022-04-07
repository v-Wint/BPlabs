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
	printf("\nThe oldest student:\n%s\n", getTheOldestStudent(studentList, size).getStudentInformation().c_str());

}