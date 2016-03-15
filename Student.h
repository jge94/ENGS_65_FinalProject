//
//  Student.h
//  Engs65_FinalProject
//
//  Created by Yuxiang Liu on 3/4/16.
//  Copyright (c) 2016 Yuxiang Liu. All rights reserved.
//

#ifndef __Engs65_FinalProject__Student__
#define __Engs65_FinalProject__Student__

#include <stdio.h>
#include "People.h"
#include "Professor.h"

class Student : public People {
    
private:
    int classYear;    // instance variable only for student
    static int studentNum;  // total number of students
    static vector<Student *> allStudents; // the set of all the students;
public:
    
    Student();  // default constructor
    
    Student(string s, int year, string sch, string ma, string pl, string em); // constructor with info
    
    Student(const People &other); // copy constructor;

    ~Student();  // destructor
    
    int getClassYear();  // getter function for classYear;
    
    void setClassYear(int year);  // setter function for classYear;
    
    void takeACourse(People * prof); // student can take a course from a professor
    
    static int getStudentNum();     // get the total number of students;
    
    void printInfo();   // print the basic info about the student;
    
};



#endif /* defined(__Engs65_FinalProject__Student__) */
