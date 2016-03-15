
#include "People.h"

// helper functions ====================================================

template<class T>
bool contains(vector<T> array, T element) {
    bool answer = false;
    for (int i = 0; i< array.size(); i++) {
        if (array.at(i) == element) {
            answer = true;
        }
    }
    return answer;
}


template<class T>
pair <T, int>  getMax(vector<T> array)
{
    T max = 0;
    int max_pos=0;

    for (int i=1; i<array.size(); i++)
    {
        if (max<array[i])
        {
            max=array[i];
            max_pos=i;
        }
    }
    
    return pair<T, int> (max, max_pos);
}


template <class T>
pair<T, int> getMax (map <T, int> myMap){

    int max = 0;
    T element;
    typename map <T, int> :: iterator myIterator;
    
    for (myIterator = myMap.begin(); myIterator != myMap.end(); myIterator ++) {
        if (max < myIterator->second)  {
            max = myIterator->second;
            element = myIterator->first;
        }
        
    }
    
    return pair<T, int> (element, max);
}

// ================================ END ===================================


int People::numbers = 0;
vector<People*> People::allNodes;


People::People(){
    name = "";
    school = "";
    major = "";
    place = "";
    email = "";
    classTaken.reserve(MAXCLASS);
    listOfFriends.reserve(MAXFRIENDS);
    organizations.reserve(MAXCLASS);
    listOfFriendswithWeights.reserve(MAXFRIENDS);
    backPointer = NULL;
    numbers ++;
    if (!contains (allNodes, this)) allNodes.push_back(this);
} // default constructor;

People::People(string s, string sch, string ma, string pl, string em ){
    name = s;
    school = sch;
    major = ma;
    place = place;
    email = em;
    classTaken.reserve(MAXCLASS);
    listOfFriends.reserve(MAXFRIENDS);
    organizations.reserve(MAXCLASS);
    listOfFriendswithWeights.reserve(MAXFRIENDS);
    backPointer = NULL;
    numbers ++;
    if (!contains(allNodes, this)) allNodes.push_back(this);
    
} // constructor with information;



People::People(const People &person){
    *this = person;
    numbers ++;
    if (!contains(allNodes, this)) allNodes.push_back(this);
    // cout << "copy constructor for People gets called" << endl;
} // copy constructor;

People::~People(){
    name = "";
    school = "";
    major = "";
    place = "";
    email = "";
    classTaken.clear();
    organizations.clear();
    backPointer = NULL;
    
} // destructor;

string People::getName() 
{
	return name;
}

void People::setName(string s){
    name = s; 
};
	

string People::getSchool()
{
	return school;
}

void People::setSchool(string newSchool)
{
	school = newSchool;
}

string People::getMajor()
{
	return major;
}

void People::setMajor(string newMajor)
{
	major = newMajor;
}


string People::getPlace()
{
    return place;
}

void People::setPlace(string newPlace)
{
	place = newPlace;
}

string People::getEmail()
{
    return email;
}

void People::setEmail(string newEmail)
{
	email = newEmail;
}

vector<string> People::getClasses()
{
	return classTaken;
}

void People::setClasses(vector<string> newClasses)
{
	classTaken = newClasses;
}

vector<People *> People::getFriends()
{
	return listOfFriends;
}
		

vector<string> People::getOrganization()
{
	return organizations;
}


void People::addConnection (People * person1){
    listOfFriends.push_back(person1);
    person1->listOfFriends.push_back(this);
    
} // add connection, since it is an undirected array, need to add the edge in both directions.

void People::removeConnection (People *person1){
    auto it = find(listOfFriends.begin(), listOfFriends.end(), person1);
    listOfFriends.erase(it);
    auto it2 = find(person1->listOfFriends.begin(), person1->listOfFriends.end(), this);
    person1->listOfFriends.erase(it2);
    
}

People * People::recommend () {
    vector<People*> potentials;
    for (int i = 0; i < listOfFriends.size(); i ++) {
        People * connection = listOfFriends.at(i);
        for (int j = 0; j < connection->listOfFriends.size(); j ++) {
            People * choice = connection->listOfFriends.at(j);
            if ((choice != this) && !contains(this->listOfFriends, choice)){
                potentials.push_back(choice);
                // cout << choice->getName() << endl;
            }
        }
    }
    
    int N = (int) potentials.size();
    
    if (N == 0) {
        return NULL;
    }
    else {
    vector <int> freq;
    for (int i = 0; i < N; i ++){
        int num = 0;
        for (int j = i+1; j < N; j ++) {
            if (potentials.at(i) == potentials.at(j)){
                num ++;
            }
         }
        freq.push_back(num);
    }
    pair<int, int> result = getMax<int> (freq);
    return potentials.at(result.second);
    }
}



map<People*, int> People::shortestPath() {
    queue<People*> myQueue;
    myQueue.push(this);
    vector<People*>visited;
    map< People*, int> myMap;
    myMap[this] = 0;
        while (!myQueue.empty()) {
            People *x = myQueue.front();
            myQueue.pop();
            visited.push_back(this);
            for (People* person : x->listOfFriends) {
                if (!contains(visited, person) ) {
                    myMap[person] = myMap[x] + 1;
                    myQueue.push(person);   // insert y into the queue
                    visited.push_back(person);
                }
            }
            
            
        }
    
    return myMap;
}


int People::shortestPath(People * other){
    map<People*, int> myMap = this->shortestPath();
    return myMap.at(other);
}




void People::getIntroduced(People * other) {
    queue<People*> myQueue;
    myQueue.push(this);
    vector<People*>visited;
    while (!myQueue.empty()) {
        People *x = myQueue.front();
        myQueue.pop();
        visited.push_back(this);
        for (People* person : x->listOfFriends) {
            if (!contains(visited, person) ) {
                myQueue.push(person);   // insert y into the queue
                visited.push_back(person);
                person->backPointer = x;
                
                if (person == other) {
                    while (person->backPointer != this) {
                        cout << person->getName() << " <- ";
                        person = person->backPointer;
                    }
                    cout << person->getName() << " <- ";
                    cout << this->getName() << endl;
                    break;
                }
            }
        }
        
        
    }
}


vector<People*> People::getAllNodes(){
    return allNodes;
}


int People::getDiameter(){
    vector<People*> nodes = People::getAllNodes();
    vector<int> maxs;
    for (People * x : nodes) {
        map<People *, int> myMap = x->shortestPath();
        pair<People*, int> result = getMax(myMap);
        maxs.push_back(result.second);
    
    }
   // cout << People::numbers << endl;
    pair<int, int> result2 = getMax(maxs);
    return result2.first;
}


int People::getNumbers(){
    return numbers;
}


void People::updateRecommendation(){
    vector<People*> nodes = People::getAllNodes();
    for (People * x : nodes) {
        People *y = x->recommend();
        if (y!=NULL) {
           x->addConnection(y);
            cout << "Update: we added connection " << y->getName() << " to " << x->getName() << endl;
        }
        
    }
}


bool People::isComplete() {
    int x = People::getDiameter();
    if (x == 1){
        return true;
    }
    else {
        return false;
    }
}


void People::updateWeights() {
    vector<People*> nodes = People::getAllNodes();
    for (People * x : nodes) {
        for(People *y:x->getFriends()) {
            
            int num = x->getCommonFriendsNum(y);
            pair<People*, int> myPair = make_pair(y, num);
            x->listOfFriendswithWeights.push_back(myPair);
        }
    }
}


int People::getCommonFriendsNum(People * other){
    int num = 0;
    for (People * x: this->getFriends()) {
        if (contains(other->getFriends(), x)){
            num++;
        }
    }
    return num;
}


vector<pair<People*, int> > People::getFriendsWithWeights(){
    return listOfFriendswithWeights;
}


void People::printInfo(){}

void People::printInfoDetails(){
    printInfo();
    cout << "His/Her connections details are:";
    for (auto item : this->listOfFriendswithWeights) {
        cout << " "<<item.first->getName() << "[" << item.second << "]";
    }
    cout << "."<<endl;
}

int People::getClassYear()
{
	;
}

void People::setClassYear(int year)
{
	;
}

void People::operator=(/*inout*/People* p)			// overwrite the equal method
{
	*this = *p;
    if (!contains(allNodes, this)) allNodes.push_back(this);
	// MAXCLASS = p->MAXCLASS;
 //    MAXFRIENDS = p->10000;
 //    MAXNUMBER = p->MAXNUMBER;
 //    numbers = p->numbers;
 //    static vector<People *> allNodes;
 //    for(People* eachPerson : allNodes)
 //    {
 //    	this.allNodes
 //    }
 //    string name;
 //    string school;
 //    string major;
 //    string place;					// where do they live now
 //    string email;
 //    vector<string> classTaken;				// array of classes
 //    vector<People *> listOfFriends;
 //    vector<pair<People*, int> > listOfFriendswithWeights;
 //    vector<string> organizations;
 //    People * backPointer;
}

// this uses dijkstra's algorithm:

/*
pair<map<People*, int>, map<People*, People*> >People::shortestPathWithWeights(){
    priority_queue<int, vector<int>, greater<int>> myQueue;
    map<People*, People*> pred;
    map<People*, int>distance;
    for (People* x : People::allNodes) {
        distance[x] = MAXNUMBER;
        pred[x] = NULL;
        myQueue.push(MAXNUMBER);
    }
    
    
    distance[this] = 0;
    myQueue.push(0);
    
    while (!myQueue.empty()) {
        
        int d = myQueue.top();
        myQueue.pop();
        People *u = new People;
        map<People*, int>::iterator it;
        for (it = distance.begin(); it!=distance.end(); it++) {
            if (it->second ==d){
                u = it->first;
            }
        }
        
        
        
        for (auto myPair : u->getFriendsWithWeights()){
            People * v = myPair.first;
            int duv = myPair.second;
            if (distance[u] + duv < distance[v]){
                distance[v] = distance[u] + duv;
                pred[v] = u;
                myQueue.push(distance[v]);
            }
        }
    }
    
    return make_pair(distance, pred);
    
}


// get introduced using dijstra's algoritm;
void People::getIntroducedWithWeights(People *other){
    pair<map<People*, int>, map<People*, People*> > myPair = this->shortestPathWithWeights();
    map<People*, People*>pred = myPair.second;
    People*x = pred[other];
    cout << other->name << " <- ";
    while (x!=this) {
        cout << x->name << " <- ";
        x = pred[x];
    }
    cout << this->name << endl;
    
}
*/

