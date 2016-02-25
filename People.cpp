#include <iostream>
#include "People.h"
using namespace std;

string People::getName() 
{
	return name;
}
		
int getClassYear() 
{
	return classYear;
}		

string getSchool()
{
	return school;
}

string getMajor()
{
	return major;
}
		
string* classTaken()
{
	return classTaken;
}
		
People* getFriends()
{
	return listOfFriends;
}
		
string* getClasses()
{
	return classTaken;
}

string* getOrganization()
{
	return organization;
}

string getPlace()
{
	return place;
}

string getEmail()
{
	return email;
}