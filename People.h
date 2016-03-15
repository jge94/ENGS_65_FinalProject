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
    vector<pair<People*, int> > listOfFriendswithWeights;
    vector<string> organizations;
    People * backPointer;
    
public:
    
    People();  // default constructor
    People(string s, string sch, string ma, string pl, string em); // constructor with info;
    People(const People &person); // copy constructor
    ~People(); // destructor
    string getName(); // getter function for name
    void setName(string s); // setter function
    void setSchool(string n); // setter function
    void setMajor(string m); // setter function
    void setPlace(string p); // setter function
    void setEmail(string e); // setter function
    void setClasses(vector<string> c); // setter function
    string getSchool(); // getter function
    string getMajor(); // getter function
    string getPlace(); // getter function
    string getEmail(); // getter function
    vector<string> getClasses();  // what classes have the student/profesor taken/taught?
    vector<People*> getFriends(); // get the connections
    vector<string> getOrganization(); // get the name of the organizaitons
    void addConnection (People * person1); // add connection between 2 people;
    void removeConnection (People *person1); // remove connection between 2 people;
    People * recommend ();  // recommend a friend to the object;
    map<People*, int> shortestPath(); // get the shortest path from *this* object to any other objects;
    int shortestPath(People * other); // get the shortest path from *this* object to *other* object
    void getIntroduced(People * other); // give a path to introduce from *this* to *other*
    int getCommonFriendsNum(People * other); // get the number of common friends from *this* and *other*
    static int getDiameter(); // get the diameter of the graph
    static int getNumbers();  // get the total number in this graph, students + professors
    static vector<People*> getAllNodes(); // get the set of all the people, including the students and the professors;
    static void updateRecommendation(); // add the recommended friends for each node automatically;
    static bool isComplete(); // to see if the graph is complete or not.
    static void updateWeights(); // add the weights to each edge, weights is calcuated by quoting the number of common frineds;
    vector<pair<People*, int> > getFriendsWithWeights(); // get a list of the adjacent nodes with the weights;
    virtual void printInfo();  // print the info for the specific node;
    virtual void printInfoDetails(); // print the detailed info for the specific node;
};

#endif