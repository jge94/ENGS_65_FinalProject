//
//  Student.cpp
//  Engs65_FinalProject
//
//  Created by Yuxiang Liu on 3/4/16.
//  Copyright (c) 2016 Yuxiang Liu. All rights reserved.
//

#include "Student.h"

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


int Student::studentNum = 0;
vector<Student *> Student::allStudents;

Student::Student():People(){
    //studentNum++;
    classYear = 0; 
    //if (!contains(allStudents, this)) allStudents.push_back(this);
}

Student::Student(string s, int year, string sch, string ma, string pl, string em):People(s, sch, ma, pl, em) {
    classYear = year;
    studentNum++;
    if (!contains(allStudents, this)) allStudents.push_back(this);
}

Student::Student(const People &other) : People(other){
    classYear = 0;
    studentNum++;
    if (!contains(allStudents, this)) allStudents.push_back(this);
    
} // copy constructor with automatic type conversion


Student::~Student(){
    
}

int Student::getClassYear(){
    return classYear;
}

void Student::setClassYear(int year) {
    classYear = year;
}


void Student::takeACourse(People * prof){
    this->addConnection(prof);
}

int Student::getStudentNum(){
    return studentNum;
}

void Student::printInfo(){
    cout << name << " is " << "a student in the class of " << classYear << " and studies " << major <<". ";
    cout <<"He/she has " << getFriends().size() << " connections." << endl;
}



