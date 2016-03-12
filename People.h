// People.h

#ifndef PEOPLE
#define PEOPLE
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue> 
#include <map>
#include <iterator>
#include <tuple>

using namespace std;

class People
{
protected:
    
    static const int MAXCLASS = 50;
    static const int MAXFRIENDS = 10000;
    static const int MAXNUMBER = 10000;
    static int numbers;
    static vector<People *> allNodes;
    string name;
    string school;
    string major;
    string place;					// where do they live now
    string email;
    vector<string> classTaken;				// array of classes
    vector<People *> listOfFriends;
    vector<pair<People*, int>> listOfFriendswithWeights;
    vector<string> organizations;
    People * backPointer;
    
public:
    
    People();
    People(string s, string sch, string ma, string pl, string em);
    People(const People &person);
    ~People();
    string getName();
    void setName(string s);
    string getSchool();
    string getMajor();
    string getPlace();
    string getEmail();
    vector<string> getClasses();
    vector<People*> getFriends();
    vector<string> getOrganization();
    void addConnection (People * person1);
    void removeConnection (People *person1);
    People * recommend ();
    map<People*, int> shortestPath();
    int shortestPath(People * other);
    void getIntroduced(People * other);
    int getCommonFriendsNum(People * other);
    static int getDiameter();
    static int getNumbers();
    static vector<People*> getAllNodes();
    static void updateRecommendation();
    static bool isComplete();
    static void updateWeights();
    vector<pair<People*, int>> getFriendsWithWeights();
    virtual void printInfo();
    virtual void printInfoDetails();
};

#endif