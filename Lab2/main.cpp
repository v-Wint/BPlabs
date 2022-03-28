#include "module.h"

int main()
{
	const char* taskListPath = "tasklist.bin";
	const char* spareTimePath = "sparelist.bin";

	createTaskList(taskListPath);

	std::vector<Task> taskList = getTaskList(taskListPath);
	sortTaskList(taskList);
	printf("\nList of tasks:\n");
	displayTaskList(taskList);

	findTheNearestTask(taskList);

	createSpareTimeList(taskList, spareTimePath);
	
	taskList = getTaskList(spareTimePath);
	if (!taskList.empty()) {
		printf("\nSpare time after 13:00 : \n");
		displayTaskList(taskList);
	}
	else {
		printf("\nNo spare time after 13:00\n");
	}
}	

