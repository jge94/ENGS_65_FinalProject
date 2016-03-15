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
	// cout << "Enter input file name: ";
	// cin >> inputFileName;

	inputFileName = "test1.txt";

	// ifstream fin("test1.txt");
	ifstream fin(inputFileName);

	while(!fin.is_open())
	{
		cout << "File opening error. File \""<< inputFileName << "\" doesn't exist." << endl;
		cout << "Enter a valid input file name: ";
		cin >> inputFileName;
		fin.open(inputFileName);
	}

	cout << "test1 \n";

	People* peopleArray = new People[ARRAY_SIZE];
	int numPeople = 0;
	string* tempArray = new string[TEMP_ARRAY_SIZE];
	string restOfStr = "";

	cout << "test2 \n";


	cout << "\nTesting on file input\n";

	while(getline(fin, oneLine))	// while not the end of the file
	{
		int i = 0;				// index for people in the peopleArray array

		// --------- testing -----------
		// cout << "New line: " << oneLine << endl;	// read in line by line

		while(oneLine.find("|") != string::npos)		// not the | exist
		{
			string usefulStr = oneLine.substr(0, oneLine.find("|"));
			// cout << "usefulStr: " << usefulStr << endl;

			tempArray[i] = usefulStr;

			restOfStr = oneLine.substr(oneLine.find("|") + 1);
			// cout << "restOfStr: " << restOfStr << endl << endl;
			oneLine = restOfStr;
			i++;
		}

		tempArray[i] = restOfStr;
		// People* peopleArray[0] = new Student();
		// People* newStudent = new Student();
		// People* newProf = new Professor();

		if(tempArray[0] == "Student")
		{
			cout << "in if " << endl;
			cout << numPeople << " people is STUDENT" << endl;
			peopleArray[numPeople] = new Student();
		}
		// else if(tempArray[0] == "Professor")
		// 	peopleArray[numPeople] = new Professor();
 
		peopleArray[numPeople].setName(tempArray[1]);

		int classYr = stoi(tempArray[2]);
		cout << "tempArray[2]: " << tempArray[2] << endl;
		cout << "classYr: " << classYr << endl;
		peopleArray[numPeople].setClassYear(classYr);
		peopleArray[numPeople].setSchool(tempArray[3]);
		peopleArray[numPeople].setMajor(tempArray[4]);
		peopleArray[numPeople].setPlace(tempArray[5]);
		peopleArray[numPeople].setEmail(tempArray[6]);

		numPeople++;

	}//end while

	fin.close();

	cout << "\t **test on people array**\n";
	for(int i = 0; i<7; i++)
	{
		// if(peopleArray[i] != NULL)
			cout << "peopleArray[" << i << "] name: " << peopleArray[i].getName() << endl;
			cout << "classYr: " << peopleArray[i].getClassYear() << endl;
			cout << "email: " << peopleArray[i].getEmail() << endl;
	}
    
    // Student Larry("Yuxiang Liu", 16, "Dartmouth College", "Physics", "Hanover", "Yuxiang.Liu.GR@dartmouth.edu");
    Student Larry = peopleArray[0];

    // Student Harry("Harry Qi", 17, "Dartmouth College", "Mathematics", "Hanover", "Harry.Qi.17@dartmouth.edu");
    Student Harry = peopleArray[1];

    // Student Jinnan("Jinnan Ge", 16, "Dartmouth College", "Engineering", "Hanover", "Jinnan.Ge.UG@dartmouth.edu");
    Student Jinnan = peopleArray[2];

    // Student Ethan("Ethan Su", 15, "Dartmouth College", "Engineering", "Hanover", "Chengwei.Su.TH@dartmouth.edu");
    Student Ethan = peopleArray[3];

    // Student Tommy("Tommy Khoo", 18, "Dartmouth College", "Mathematics", "Hanover", "Tommy.Khoo.GR@dartmouth.edu");
    Student Tommy = peopleArray[4];

    // Student Liyuan("Liyuan Mei", 16, "Dartmouth College", "Physics", "Hanover", "Liyuan.mei.GR@dartmouth.edu");
    Student Liyuan = peopleArray[5];
    
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
