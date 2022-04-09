class Date {
	int day, month, year;
public:
	Date() = default;
	Date(int, int, int);
	Date(std::string);
	~Date() {};
	
	std::string getDate();
	int getAgeYears();

	int getDay(){ return day; };
	int getMonth(){ return month; };
	int getYear() { return year; };
};


class FullName {
	std::string firstName, secondName, parentName;
public:
	FullName() = default;
	FullName(std::string, std::string, std::string);
	FullName(std::string);
	~FullName() {};

	std::string getFullName();

	std::string getFirstName() { return firstName; };
	std::string getSecondName() { return secondName; };
	std::string getParetName() { return parentName; };
};


class Student {
	FullName fullName;
	std::string groupNumber;
	Date birthDate;
public:
	Student() = default;
	Student(FullName, std::string, Date);
	Student(std::string, std::string, std::string);
	~Student() {};
	std::string getStudentInformation();

	FullName getFullName() { return fullName; };
	std::string getGroupNumber() { return groupNumber; };
	Date getBirthDate() { return birthDate; };
};

Student* getStudentList(const char* fullName, size_t size);
void displayStudentList(Student* studentList, size_t size);
Student getTheOldestStudent(Student* studentList, std::string groupNumber, size_t size);