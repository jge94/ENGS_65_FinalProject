//
//  main.cpp
//  Engs65_FinalProject
//
//  Created by Yuxiang Liu on 3/1/16.
//  Copyright (c) 2016 Yuxiang Liu. All rights reserved.
//

#include "People.h"
#include "Professor.h"
#include "Student.h"

int main(int argc, const char * argv[]) {
      
    
    Student Larry("Yuxiang Liu", 16, "Dartmouth College", "Physics", "Hanover", "Yuxiang.Liu.GR@dartmouth.edu");
    
    Student Harry("Harry Qi", 17, "Dartmouth College", "Mathematics", "Hanover", "Harry.Qi.17@dartmouth.edu");
    
    Student Jinnan("Jinnan Ge", 16, "Dartmouth College", "Engineering", "Hanover", "Jinnan.Ge.UG@dartmouth.edu");
    
    Student Ethan("Ethan Su", 15, "Dartmouth College", "Engineering", "Hanover", "Chengwei.Su.TH@dartmouth.edu");
    
    Student Tommy("Tommy Khoo", 18, "Dartmouth College", "Mathematics", "Hanover", "Tommy.Khoo.GR@dartmouth.edu");
    
    Student Liyuan("Liyuan Mei", 16, "Dartmouth College", "Physics", "Hanover", "Liyuan.mei.GR@dartmouth.edu");
    
    
    Professor Santos("Eugene Santos", true, "Dartmouth College", "Engineering", "Hanover", "Eugene.Santos@dartmouth.edu");
    
    
    Larry.addConnection(&Harry);
    Larry.addConnection(&Jinnan);
    Harry.addConnection(&Ethan);
    Ethan.addConnection(&Jinnan);
    Jinnan.addConnection(&Tommy);
    Tommy.addConnection(&Liyuan);
    
    vector<People*> listofStudents;
    listofStudents.push_back(&Larry);
    listofStudents.push_back(&Jinnan);
    
    Santos.teachCourse(listofStudents);
    Ethan.takeACourse(&Santos);

    People::updateWeights();  // updates the weights, so that the number of common friends are updated;
    
    Larry.printInfoDetails(); // print each node details, between [] are the number of common friends;
    Santos.printInfoDetails();
    
    cout << "1. The first recommedation for Larry is " << Larry.recommend()->getName() << endl;
    
    cout << "2.1. The distance between Larry and Liyuan is " << Larry.shortestPath(&Liyuan)<< endl;
    
    cout << "2.2. The distance between Harry and Liyuan is " << Harry.shortestPath(&Liyuan)<< endl;
    
    cout << "3. The shortest path from Larry to Liyuan is " ;
    Larry.getIntroduced(&Liyuan);
    
    cout << "4.1 Harry has " << Harry.getFriends().size() << " frineds." << endl;
    
    Harry.removeConnection(&Ethan);
    cout << "4.2 Harry has " << Harry.getFriends().size() << " frineds after deletion." << endl;
    
    Harry.addConnection(&Ethan);
    cout << "5. There are in total " << People::getAllNodes().size() << " nodes in this graph."<< endl;
    
    cout << "6. The diameter of this graph is "  << People::getDiameter() << endl;
    
    cout << "7. There are totally " << People::getNumbers() << " nodes" << endl;
    
    People::updateRecommendation();
    
    cout << "8. After adding all the recommendation, the diameter of the graph is now "<< People::getDiameter() << endl;
    cout << "9. The shortest path from Larry to Liyuan after update is " << Larry.shortestPath(&Liyuan) << endl;
    
    People::updateRecommendation();
    cout << "10. After second update, the diameter of the graph is now "<< People::getDiameter() << endl;
    
    People::updateWeights();
    Larry.printInfoDetails();
    Santos.printInfoDetails();
    
    return 0;
    
}
