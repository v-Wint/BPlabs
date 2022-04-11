#include <vector>
struct Task {
	char name[100];
	int startTime,
		duration,
		endTime;
};

/**
* create a file with tasks from the user input
* @param fileName path to file
*/
void createTaskList(const char* fileName);

/**
* display task information
*/
void displayTask(Task task);

/**
* display list of tasks
*/
void displayTaskList(std::vector<Task> taskList);

/**
* extract vector of tasks from a file
* @param fileName path to file
* @return vector of tasks
*/
std::vector<Task> getTaskList(const char* fileName);

/**
* sort list of tasks by start time
*/
void sortTaskList(std::vector<Task>& taskList);

/**
* find the nearest task to current local time and output it
*/
void findTheNearestTask(std::vector<Task> taskList);

/**
* create a list of intervals of spare time after 13:00 and save it to the file
* @param taskList list of all tasks
* @param fileName path to file to save list of spare time intervals
*/
void createSpareTimeList(std::vector<Task> taskList, const char* fileName);

/**
* display spare time list if it's not empty else print message
*/
void displaySpareTimeList(std::vector<Task> taskList);
