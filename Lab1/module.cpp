#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void createFile(const char* name) {
	ofstream f(name);
	string line;

	// errors check
	if (!f) {
		cerr << "Error: file \"" << name <<  "\" could not be opened" << endl;
		exit(1);
	}

	// read until any control character but space & EOL
	cout << "Enter your text, type any control character when finished" << endl;
	char c;
	while (cin.get(c) && (c > 31 || c == 10)) {
		f.put(c);
	}

	f.close();
}

char findFirstCharLastWord(string s) {
	s.erase(s.find_last_not_of(' ') + 1); //strip last spaces
	return s[s.find_last_of(' ') + 1];
}

void createNewFile(const char* name1, const char* name2) {
	ifstream inF(name1);
	ofstream outF(name2);
	string line;

	// errors check
	if (!inF || !outF) {
		cerr << "Error: file \"" << name1 << "\" or \"" << name2 << "\" could not be opened" << endl;
		exit(1);
	}

	getline(inF, line);
	while (1) {
		outF << findFirstCharLastWord(line) << line;
		if (getline(inF, line))  // if it is not the last line, add EOL, else end
			outF << endl;
		else
			break;
	}

	inF.close();
	outF.close();
}

void displayFile(const char* name) {
	string line;
	ifstream f(name);

	// errors check
	if (!f) {
		cerr << "Error: file \"" << name << "\" could not be opened" << endl;
		exit(1);
	}

	printf("\n----------\"%s\"----------\n", name);
	while (!f.eof()) {
		getline(f, line);
		cout << line << endl;
	}
	printf("----------%s----------\n\n", string(strlen(name) + 2, '-').c_str());

	f.close();
}	