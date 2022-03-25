#include "module.h"

int main()
{
	createTaskList("tasklist.dat");

	std::vector<Task> taskList = getTaskList("tasklist.dat");
	sortTaskList(taskList);
	printf("\nList of tasks:\n");
	displayTaskList(taskList);

	findTheNearestTask(taskList);

	createSpareTimeList(taskList, "sparelist.dat");
	
	taskList = getTaskList("sparelist.dat");
	if (!taskList.empty()) {
		printf("\nSpare time after 13:00 : \n");
		displayTaskList(taskList);
	}
	else {
		printf("\nNo spare time after 13:00 : \n");
	}
}	

