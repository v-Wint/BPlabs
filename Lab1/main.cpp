#include "module.h"

int main() {
	const char* name1 = "file1.txt";
	const char* name2 = "file2.txt";

	createFile(name1);
	createNewFile(name1, name2);

	displayFile(name1);
	displayFile(name2);
}
