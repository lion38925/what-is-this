#include <bits/stdc++.h>
using namespace std;

class Meeting;
typedef vector<Meeting> Calendar;

class Room {
	string name;
	Calendar calendar;

	public:
		Room(string);
		bool book(int, int, int);
		const string& getName() const;
};

class Meeting {
	int day, start, end;
	Room room;

	public:
		Meeting(int, int, int, Room);
		int getStart();
		int getEnd();
		int getDay();
};

class Scheduler {
	vector<Room> rooms;
	public:
		Scheduler(vector<Room> rooms);
		string book(int, int, int);
};

Meeting::Meeting(int day, int start, int end, Room room) : day(day), start(start), end(end), room(room){

}

int Meeting::getStart(){
	return start;
}

int Meeting::getEnd(){
	return end;
}

int Meeting::getDay(){
	return day;
}

Scheduler::Scheduler(vector<Room> rooms){
	this->rooms = rooms;
}

string Scheduler::book(int day, int start, int end){
	for(int i=0; i<rooms.size(); i++){
		bool flag = rooms[i].book(day, start, end);
		if(flag == true){
			return rooms[i].getName();
		}
	}

	return "No rooms available.";
}

Room::Room(string name){
	this->name = name;
}

bool Room::book(int day, int start, int end){
	for(int i=0; i<calendar.size(); i++){
		if(calendar[i].getDay() == day && calendar[i].getStart() < end && calendar[i].getEnd() > start){
			return false;
		}
	}

	Meeting meeting(day, start, end, *this);
	calendar.push_back(meeting);

	return true;
}

const string &Room::getName() const {
	return name;
}

int main(){
	Room room1("Atlas");
	Room room2("Nexus");
	Room room3("HolyCow");

	vector<Room> roomVec;
	roomVec.push_back(room1);
	roomVec.push_back(room2);
	roomVec.push_back(room3);

	Scheduler scheduler(roomVec);

	cout << scheduler.book(1, 2, 5) << endl;
	cout << scheduler.book(1, 5, 8) << endl;
	cout << scheduler.book(1, 4, 8) << endl;
	cout << scheduler.book(1, 3, 6) << endl;
	cout << scheduler.book(1, 7, 8) << endl;
	cout << scheduler.book(2, 6, 9) << endl;

	return 0;
}