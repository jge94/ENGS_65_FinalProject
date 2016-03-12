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
    int classYear;
    static int studentNum;
    static vector<Student *> allStudents;
public:
    
    Student();
    
    Student(string s, int year, string sch, string ma, string pl, string em);
    
    Student(const People &other);

    ~Student();
    
    int getClassYear();
    
    void setClassYear(int year);
    
    void takeACourse(People * prof);
    
    static int getStudentNum();
    
    void printInfo();
    
};



#endif /* defined(__Engs65_FinalProject__Student__) */