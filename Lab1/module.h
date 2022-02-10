#include <string>
/**
* create a file from the user input, the input ends when one of the control characters are entered
* @param name the path to the file to be created
*/
void createFile(const char* name);

/**
* find the first character of the last word in a string
* @param s string which is being proceeded
* @return the first character of the last word in a string
*/
char findFirstCharLastWord(std::string s);

/**
* create a new file getting the lines of the orig file and putting the first character of the last word in them in the beginning
* @param name1 the path to the original file
* @param name2 the path to the file to be created
*/
void createNewFile(const char* name1, const char* name2);

/**
* display the text in the file
* @param name the path to the file
*/
void displayFile(const char* name);