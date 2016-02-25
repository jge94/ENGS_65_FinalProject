// People.h

#ifndef PEOPLE
#define PEOPLE
#include <iostream>

using namespace std;

class People
{
	private:
		string name;
		int classYear;
		string school;
		string major;
		string* classTaken;				// array of classes
		People* listOfFriends;		
		string* organzations;
		string place;					// where do they live now
		string email;

	public:
		string getName();
		int getClassYear();
		string getSchool();
		string getMajor();
		string* getClasses();
		People* getFriends();
		string* getOrganization();
		string getPlace();
		string getEmail();
};

#endif