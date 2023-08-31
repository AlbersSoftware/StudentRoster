#pragma once
# include "student.h"
#include<iostream>
#include <iomanip>
#include "degree.h"
//#include "main.cpp"
#include <string>

using namespace std;

class Roster
{
public:
	int lastIndex = -1; // lastIndex will go through an array of students, when adding students to roster it will increment to 0 which is why I use -1.
	const static int numofstudents = 5;
	Student* classRosterArray[numofstudents]; 
	
	//no inhertence here so no need for private:

	void parse(string row); // extracts data from Student from delimted strings and looks at comma to produce
	// a student object with add method
	void add(string studentID, string firstName, string lastName, string emailAddress,
		int age, int day1, int day2, int day3, EnumDegreeProgram degreeType); 
	
	void printAll();// calls print method laid out in student class
	void printInvalidEmails(); // prints emails who didn't pass the boolean checks made in roster.cpp with .find { . @ " "}
	void printAverageDays(string studentID); // print all students averages 
	void printDegreeProgram(EnumDegreeProgram degreeType); // print desired degree type
	void removeStudent(string studentID);  // finds student with given ID and remove if found.
	
	~Roster();
};



