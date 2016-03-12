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
    
    bool isTenured;
    static int professorNum;
    static vector<Professor *> allProfessors;
public:
    
    
    Professor();
    
    Professor(string s, bool tenured, string sch, string ma, string pl, string em);
    
    Professor(const People &other);
    
    ~Professor();
    
    bool getTenured();
    
    void teachCourse (vector<People *> listofStudents);
    
    static int getProfessorNum();
    
    void printInfo();
};

#endif /* defined(__Engs65_FinalProject__Professor__) */
