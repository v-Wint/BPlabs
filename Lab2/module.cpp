#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "module.h"

using namespace std;

void createTaskList(const char* fileName) {
	int numOfTasks, h, m;
	string s = "";
	Task task;

	ofstream outF(fileName, ios::binary);
	if (!outF) {
		cerr << "Error: file \"" << fileName << "\" could not be opened" << endl;
		exit(1);
	}

	cout << "Enter number of tasks: "; cin >> numOfTasks;
	cin.ignore();

	for (int i = 1; i <= numOfTasks; i++) {
		// task name
		do {
			printf("(%d) Task name: ", i); getline(cin, s);
		} while (s.size() > 100);

		strcpy(task.name, s.c_str());

		//start time
		do {
			cout << "Time of start (seaparate hours and minutes with space): "; cin >> h >> m; cin.ignore();
		} while (h < 0 || h >= 24 || m < 0 || m >= 60);

		task.startTime = h * 60 + m;

		//duration 
		do {
			cout << "Duration (seaparate hours and minutes with space): "; cin >> h >> m; cin.ignore();
		} while (h < 0 || h >= 24 || m < 0 || m >= 60);

		task.duration = h * 60 + m;
		task.endTime = task.startTime + task.duration;


		outF.write((char*)&task, sizeof(Task));
	}
	outF.close();
}

void displayTask(Task task) {
	printf("%15s:   %02d:%02d--->%02d:%02d--->%02d:%02d\n", task.name, task.startTime / 60, task.startTime % 60,
		task.duration / 60, task.duration % 60,
		task.endTime / 60, task.endTime % 60);
}

void displayTaskList(vector<Task> taskList) {
	Task task;
	for (size_t i = 0; i < taskList.size(); i++)
		displayTask(taskList.at(i));
}

vector<Task> getTaskList(const char* fileName) {
	Task task;
	vector<Task> taskList;

	ifstream inF(fileName, ios::binary);
	if (!inF) {
		cerr << "Error: file \"" << fileName << "\" could not be opened" << endl;
		exit(1);
	}

	while (inF.read((char*)&task, sizeof(task)))
		taskList.push_back(task);
	inF.close();
	return taskList;
}

bool compareTasks(Task t1, Task t2) {
	return (t1.startTime < t2.startTime);
}

void sortTaskList(vector<Task>& taskList) {
	sort(taskList.begin(), taskList.end(), compareTasks);
}

void findTheNearestTask(vector<Task> taskList) {
	//get current time in minutes after mindnight
	time_t curr_time = time(NULL);
	tm* tm_local = localtime(&curr_time);
	int currentTime = tm_local->tm_hour * 60 + tm_local->tm_min;

	//sorted vector
	Task task;
	for (size_t i = 0; i < taskList.size(); i++) {
		task = taskList.at(i);
		if (task.startTime > currentTime) {
			printf("\nCurrent time: %02d:%02d", tm_local->tm_hour, tm_local->tm_min);
			printf("\nThe next task is:\n");
			displayTask(task);
			return;
		}
	}
	printf("\nYou've got no task left\n");
}

void createSpareTimeList(vector<Task> taskList, const char* fileName) {
	Task currentTask, nextTask, spareTime;
	int a, b; //start & end of a task

	ofstream outF(fileName, ios::binary);
	if (!outF) {
		cerr << "Error: file \"" << fileName << "\" could not be opened" << endl;
		exit(1);
	}

	for (size_t i = 0; i < taskList.size() - 1; i++) {
		currentTask = taskList.at(i);
		nextTask = taskList.at(i + 1);

		a = currentTask.startTime;
		b = currentTask.endTime;
		if (b >= 13 * 60) { //if ends after 13:00

			if (a > 13 * 60) { //	check if there is spare time after 13:00, if so, add additional spare time interval
				spareTime = { "spare", 13 * 60, a - 13 * 60, a };
				outF.write((char*)&spareTime, sizeof(Task));
			}

			a = currentTask.endTime;
			b = nextTask.startTime;
			if (b - a > 0) {
				spareTime = { "spare", a, b - a, b };

				outF.write((char*)&spareTime, sizeof(Task));
			}
		}
	}

	b = taskList.at(taskList.size() - 1).endTime; //get the last task and check if there is spare time before 24:00
	if (b < 24 * 60) {
		spareTime = { "spare", b, 24 * 60 - b, 24 * 60 };

		outF.write((char*)&spareTime, sizeof(Task));
	}
	outF.close();
}