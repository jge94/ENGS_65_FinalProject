//
//  main.cpp
//  Engs65_FinalProject
//
//  Created by Yuxiang Liu on 3/1/16.
//  Copyright (c) 2016 Yuxiang Liu. All rights reserved.
//

#include "People.h"


int main(int argc, const char * argv[]) {
      
    
    People Larry("Yuxiang Liu", 16, "Dartmouth College", "Physics", "Hanover", "Yuxiang.Liu.GR@dartmouth.edu");
    
    People Harry("Harry Qi", 17, "Dartmouth College", "Mathematics", "Hanover", "Harry.Qi.17@dartmouth.edu");
    
    People Jinnan("Jinnan Ge", 16, "Dartmouth College", "Engineering", "Hanover", "Jinnan.Ge.UG@dartmouth.edu");
    
    People Ethan("Ethan Su", 15, "Dartmouth College", "Engineering", "Hanover", "Chengwei.Su.TH@dartmouth.edu");
    
    People Tommy("Tommy Khoo", 18, "Dartmouth College", "Mathematics", "Hanover", "Tommy.Khoo.GR@dartmouth.edu");
    
    People Liyuan("Liyuan Mei", 16, "Dartmouth College", "Physics", "Hanover", "Liyuan.mei.GR@dartmouth.edu");
    
    Larry.addConnection(&Harry);
    Larry.addConnection(&Jinnan);
    Harry.addConnection(&Ethan);
    Ethan.addConnection(&Jinnan);
    Jinnan.addConnection(&Tommy);
    Tommy.addConnection(&Liyuan);
     
    
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
    cout << "9. The shortest path from Larry to Liyuan after update is " <<Larry.shortestPath(&Liyuan) << endl;
    
    People::updateRecommendation();
    cout << "10. After second update, the diameter of the graph is now "<< People::getDiameter() << endl;
    
    
    // try to test how many space a vector of pointers take, turns out that very small;
    cout << sizeof(Larry.getFriends()) << endl;
    cout << Larry.getFriends().size() << endl;
    cout << sizeof(People *) << endl;
    
    
    
    
    //bool x = contains(Larry.getFriends(), &Ethan);
    return 0;
    
}
