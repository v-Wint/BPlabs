#include <vector>
struct Task {
	char name[100];
	int startTime,
		duration,
		endTime;
};

using namespace std;

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
void displayTaskList(vector<Task> taskList);

/**
* extract vector of tasks from a file
* @param fileName path to file
* @return vector of tasks
*/
vector<Task> getTaskList(const char* fileName);

/**
* sort list of tasks by start time
*/
void sortTaskList(vector<Task>& taskList);

/**
* find the nearest task to current local time and output it
*/
void findTheNearestTask(vector<Task> taskList);

/**
* create a list of intervals of spare time after 13:00 and save it to the file
* @param taskList list of all tasks
* @param fileName path to file to save list of spare time intervals
*/
void createSpareTimeList(vector<Task> taskList, const char* fileName);