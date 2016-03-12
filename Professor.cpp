//
//  Professor.cpp
//  Engs65_FinalProject
//
//  Created by Yuxiang Liu on 3/4/16.
//  Copyright (c) 2016 Yuxiang Liu. All rights reserved.
//

#include "Professor.h"

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


int Professor::professorNum = 0;
vector<Professor *> Professor::allProfessors;


Professor::Professor():People(){
    if (!contains(allProfessors, this)) allProfessors.push_back(this);
    isTenured = false;   //default;
    professorNum++;
}

Professor::Professor(string s, bool tenured, string sch, string ma, string pl, string em):People(s, sch, ma, pl, em) {
    isTenured = tenured;
    professorNum++;
    if (!contains(allProfessors, this)) allProfessors.push_back(this);
}

Professor::Professor(const People &other) : People(other){
    isTenured = false; // default; 
    professorNum++;
    if (!contains(allProfessors, this)) allProfessors.push_back(this);
    
} // copy constructor with automatic type conversion


Professor::~Professor(){
    
}

bool Professor::getTenured(){
    return isTenured;
}


void Professor::teachCourse (vector<People *> listofStudents){
    for (People * item : listofStudents) {
        this->addConnection(item);
    }
}


int Professor::getProfessorNum() {
    return professorNum;
}


void Professor::printInfo(){
    string s;
    if (isTenured) {
        s = "a tenured";
    }
    else
    {
        s = "an assistant";
    }
    cout << "Professor " << name << "is " << s << " professor in " << major <<" department. ";
    cout <<"He/she has " << getFriends().size() << " connections." << endl;
}


