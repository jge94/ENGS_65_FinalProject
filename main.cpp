//
//  main.cpp
//  Engs65_FinalProject
//
//  Created by Yuxiang Liu on 3/1/16.
//

#include "People.h"
#include "Professor.h"
#include "Student.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

long ARRAY_SIZE = 1000;
int TEMP_ARRAY_SIZE = 10;

int main(int argc, const char * argv[]) {
    
	string oneLine;
	string eachWord;
	string inputFileName;

	cout << "			+++ Dartmouth Connect +++\n";

	inputFileName = "/Users/Yuxiang/documents/C++/Engs65/Engs65_FinalProject/ENGS_65_FinalProject/test1.txt";
    // IMPORTANT: you will have to enter the whole path here.

	ifstream fin(inputFileName);

	while(!fin.is_open())
	{
		cout << "File opening error. File \""<< inputFileName << "\" doesn't exist. " << endl;
		cout << "Enter a valid input file name: ";
		cin >> inputFileName;
		fin.open(inputFileName);
	}

    vector<Student*> peopleArray;
    peopleArray.reserve(ARRAY_SIZE);
    vector<string>tempArray;
	string restOfStr = "";

    tempArray.reserve(TEMP_ARRAY_SIZE);



	cout << "\nTesting on file input\n";

	while(getline(fin, oneLine))	// while not the end of the file
	{
					// index for people in the peopleArray array

		// --------- testing -----------
		// cout << "New line: " << oneLine << endl;	// read in line by line
        tempArray.clear();

		while(oneLine.find("|") != string::npos)		// not the | exist
		{
			string usefulStr = oneLine.substr(0, oneLine.find("|"));
			// cout << "usefulStr: " << usefulStr << endl;

			tempArray.push_back(usefulStr);

			restOfStr = oneLine.substr(oneLine.find("|") + 1);
			// cout << "restOfStr: " << restOfStr << endl << endl;
			oneLine = restOfStr;
        
		}

		tempArray.push_back(restOfStr);
		// People* peopleArray[0] = new Student();
		// People* newStudent = new Student();
		// People* newProf = new Professor();

		
		Student *stu = new Student();
		
	
 
		stu->setName(tempArray.at(1));

		int classYr = stoi(tempArray.at(2));
		stu->setClassYear(classYr);
		stu->setSchool(tempArray.at(3));
		stu->setMajor(tempArray.at(4));
		stu->setPlace(tempArray.at(5));
		stu->setEmail(tempArray.at(6));

        peopleArray.push_back(stu);

	}//end while

	fin.close();

    
    Student Larry = *peopleArray.at(0);
    
    Student Harry = *peopleArray.at(1);
    
    Student Jinnan =*peopleArray.at(2);
    
    Student Ethan = *peopleArray.at(3);
    
    Student Tommy = *peopleArray.at(4);
    
    Student Liyuan = *peopleArray.at(5);
    
    
	cout << "\t **test on people array**\n";
    for(Student * stu: peopleArray)
	{
		// if(peopleArray[i] != NULL)
			cout << "\nname: " << stu->getName() << endl;
			cout << "classYr: " << stu->getClassYear() << endl;
			cout << "email: " << stu->getEmail() << endl;
	}
    

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
    
    cout << endl; 
    Larry.printInfoDetails(); // print each node details, between [] are the number of common friends;
    cout << endl;
    Santos.printInfoDetails();
    
    cout << "\n1. The first recommedation for Larry is " << Larry.recommend()->getName() << endl;
    
    cout << "\n2.1. The distance between Larry and Liyuan is " << Larry.shortestPath(&Liyuan)<< endl;
    
    cout << "\n2.2. The distance between Harry and Liyuan is " << Harry.shortestPath(&Liyuan)<< endl;
    
    cout << "\n3. The shortest path from Larry to Liyuan is " ;
    Larry.getIntroduced(&Liyuan);
    
    cout << "\n4.1 Harry has " << Harry.getFriends().size() << " frineds." << endl;
    
    Harry.removeConnection(&Ethan);
    cout << "\n4.2 Harry has " << Harry.getFriends().size() << " frineds after deletion." << endl;
    
    Harry.addConnection(&Ethan);
    cout << "\n5. There are in total " << People::getAllNodes().size() << " nodes in this graph."<< endl;
    
    cout << "\n6. The diameter of this graph is "  << People::getDiameter() << endl;
    
    cout << "\n7. There are totally " << People::getNumbers() << " nodes" << endl;
    
    People::updateRecommendation();
    
    cout << "\n8. After adding all the recommendation, the diameter of the graph is now "<< People::getDiameter() << endl;
    cout << "\n9. The shortest path from Larry to Liyuan after update is " << Larry.shortestPath(&Liyuan) << endl;
    
    People::updateRecommendation();
    cout << "\n10. After second update, the diameter of the graph is now "<< People::getDiameter() << endl;
    
    People::updateWeights();
    Larry.printInfoDetails();
    Santos.printInfoDetails();
    
    return 0;
    
}
