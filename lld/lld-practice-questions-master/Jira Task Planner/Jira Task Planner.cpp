#include <bits/stdc++.h>
using namespace std;

enum TaskType {STORY, FEATURE, BUG};
enum TaskStatus {OPEN, IN_PROGRESS, RESOLVED, DELAYED, COMPLETED};

class Task;

class Sprint {
	int begin, end;
	string name;
	vector<Task> tasks;

	public:
		Sprint(int begin, int end, string name);
		void addTask(Task&);
		void printDetails();
		const vector<Task>& getTasks() const;
		bool operator==(Sprint sprint);
		bool eraseTask(Task task);
};

class User {
	vector<Task> taskList;
	vector<Sprint> sprintList;

	public:
		Task createTask(TaskType);
		Task createTask(string);
		Sprint createSprint(int, int, string);
		bool addToSprint(Sprint&, Task&);
		bool removeFromSprint(Sprint&, Task&);
		void printAllTasks();
		bool changeStatus(Task&, TaskStatus);
};

class Task {
	int id;
	string subtract;
	User user;
	TaskType taskType;
	TaskStatus taskStatus;
	int getUniqueId();

	public:
		Task();
		int getId() const;
		void setSubtract(const string &subtract);
		void setTaskStatus(TaskStatus taskStatus);
		void setTaskType(TaskType taskType);
		void setUser(User user);
		bool operator==(Task task);
};


const vector<Task>& Sprint::getTasks() const {
	return tasks;
}

Sprint::Sprint(int begin, int end, string name) : begin(begin), end(end), name(name) { }

void Sprint::addTask(Task & task){
	tasks.push_back(task);
}

void Sprint::printDetails(){
	cout << "Sprint Name: " << this->name << endl;
	cout << "Sprint Begins: " << this->begin << endl;
	cout << "Sprint Ends: " << this->end << endl;
}

inline bool Sprint::operator==(Sprint sprint){
	return (sprint.begin == this->begin) && (sprint.end == this->end) && (sprint.name == this->name);
}

bool Sprint::eraseTask(Task task){
	vector<Task>::iterator it = find((this->tasks).begin(), (this->tasks).end(), task);
	if(it != (this->tasks).end()){
		//i.e the task exists in this sprint
		(this->tasks).erase(it);
		return true;
	}

	return false;
}

inline bool Task::operator==(Task task){
	return (this->id == task.id);
}

Task::Task(){
	this->id = getUniqueId();
	this->taskStatus = OPEN;
}

int Task::getId() const {
	return id;
}

void Task::setSubtract(const string &subtract){
	this->subtract = subtract;
}

void Task::setTaskStatus(TaskStatus taskStatus){
	this->taskStatus = taskStatus;
}

void Task::setTaskType(TaskType taskType){
	this->taskType = taskType;
}

void Task::setUser(User user){
	this->user = user;
}

int Task::getUniqueId(){
	static int taskId = 1;
	return taskId++;
}

Task User::createTask(TaskType taskType){
	if(taskType == STORY){
		cout << "Warning! Task of type STORY is being created with no subtract." << endl;
	}
	Task task;
	task.setTaskType(taskType);
	task.setUser(*this);
	taskList.push_back(task);

	return task;
}

Task User::createTask(string subtract){
	Task task;
	task.setTaskType(STORY);
	task.setSubtract(subtract);
	task.setUser(*this);
	taskList.push_back(task);

	return task;
}

Sprint User::createSprint(int begin, int end, string name){
	Sprint sprint(begin, end, name);
	sprintList.push_back(sprint);

	return sprint;
}

bool User::addToSprint(Sprint &sprint, Task &task){
	for(int i=0; i<sprintList.size(); i++){
		Sprint spr = sprintList[i];
		if(spr == sprint){
			sprint.addTask(task);
			return true;
		}
	}
	return false;
}

bool User::removeFromSprint(Sprint &sprint, Task &task){
	for(int i=0; i<sprintList.size(); i++){
		Sprint spr = sprintList[i];
		if(spr == sprint){
			//i.e the user is added to the provided sprint
			return sprint.eraseTask(task);
		}
	}

	return false;
}

void User::printAllTasks(){
	for(int i=0; i<taskList.size(); i++){
		Task task = taskList[i];
		cout << task.getId() << " ";
	}
	cout << endl;
}

bool User::changeStatus(Task &task, TaskStatus status){
	for(int i=0; i<taskList.size(); i++){
		Task &t = taskList[i];
		if(t == task){
			t.setTaskStatus(status);
			return true;
		}
	}
	return false;
}

int main(){
	cout << boolalpha;

	User user1, user2;
	Task task1 = user1.createTask(FEATURE);
	Task task11 = user1.createTask(BUG);
	Task task2 = user2.createTask(BUG);
	Task task22 = user2.createTask("This is a subtract");

	Sprint sprint1 = user1.createSprint(22,33,"Sprint1");
	Sprint sprint2 = user2.createSprint(44,55,"Sprint2");

	cout << user1.changeStatus(task11, IN_PROGRESS) <<endl ;//1

	cout << user1.addToSprint(sprint1, task1) << "\n"; //1
	cout << user1.addToSprint(sprint1, task11) << "\n"; //1
	cout << user1.addToSprint(sprint2, task1) << "\n"; //0
	cout << user1.removeFromSprint(sprint1, task11) << "\n"; //1
	cout << user2.addToSprint(sprint1, task1) << "\n"; //0
	cout << user2.removeFromSprint(sprint1, task2) << "\n"; //0
	cout << user2.addToSprint(sprint2, task1) << "\n"; //1
	cout << user2.addToSprint(sprint2, task2) << "\n"; //1

	sprint1.printDetails();
	cout << endl;
	user1.printAllTasks();
	user2.printAllTasks();
	return 0;
}