//
//  Professor.h
//  Engs65_FinalProject
//
//  Created by Yuxiang Liu on 3/4/16.
//  Copyright (c) 2016 Yuxiang Liu. All rights reserved.
//

#ifndef __Engs65_FinalProject__Professor__
#define __Engs65_FinalProject__Professor__

#include <stdio.h>
#include "People.h"
#include "Student.h"
#include <string>
#include <vector>

class Professor : public People{
    
private:
    
    bool isTenured;   // instance variable just for professor;
    static int professorNum; // total number of professors
    static vector<Professor *> allProfessors; // the set of all the professors
public:
    
    
    Professor(); // copy constructor
    
    Professor(string s, bool tenured, string sch, string ma, string pl, string em); // constructor with info;
    
    Professor(const People &other); // copy constructor
    
    ~Professor(); // destructor
    
    bool getTenured();  // see if a professor is tenured;
    
    void teachCourse (vector<People *> listofStudents);  // professor can teach a course to a list of students
    
    static int getProfessorNum();   // get the total number of professors
    
    void printInfo();  // print the basic info about the professor;
};

#endif /* defined(__Engs65_FinalProject__Professor__) */
