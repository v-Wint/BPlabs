class Date {
	int day, month, year;
public:
	Date() : day(1), month(1), year(1900) {};
	Date(int day, int month, int year) : day(day), month(month), year(year) {};
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
	FullName() : firstName(""), secondName(""), parentName("") {};
	FullName(std::string firstName, std::string secondName, std::string parentName) : firstName(firstName), secondName(secondName), parentName(parentName) {};
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
	Student() : fullName(FullName()), groupNumber(""), birthDate(Date()) {};
	Student(FullName fullName, std::string groupNumber, Date birthDate) : fullName(fullName), groupNumber(groupNumber), birthDate(birthDate) {};
	Student(std::string fullName, std::string groupNumber, std::string birthDate) : fullName(FullName(fullName)), groupNumber(groupNumber), birthDate(Date(birthDate)) {};
	~Student() {};

	std::string getStudentInformation();

	FullName getFullName() { return fullName; };
	std::string getGroupNumber() { return groupNumber; };
	Date getBirthDate() { return birthDate; };
};

Student* getStudentList(const char* fullName, size_t size);
void displayStudentList(Student* studentList, size_t size);
Student getTheOldestStudent(Student* studentList, std::string groupNumber, size_t size);