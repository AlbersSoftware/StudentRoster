#pragma once
#include <iostream>
#include <iomanip>
# include "degree.h"
using namespace std;

class Student {

public:

	const static int daysInCourse = 3; // array of days in course, 3 seprate courses, constant is defined first due to no forward declarations in c++

	// only student object itself can use in private.
private:
	string firstName, lastName, studentID, emailAddress;
	int courseNumDays[daysInCourse];
	int age;
	EnumDegreeProgram degreeType;

public:
	Student(); // parameterless constructor to set values
	Student(string studentID, string firstName, string lastName, string emailAddress, // full constructor
		int age, int daysInCourse[], EnumDegreeProgram degreeType); 

	~Student();// destructor

	//accessors
	string getstuID();
	string getFirstName();
	string getLastName();
	string getemail();
	int getAge();
	int* getcourseNumDays();
	
	EnumDegreeProgram getDegreeType();

	// mutators
	void setstuID(string stuID);
	void setfirstName(string firstName);
	void setlastName( string lastName);
	void setemail( string email);
	void setAge ( int age);
	void setcourseNumDays (int courseNumDays[]);
	void setDegreeType (EnumDegreeProgram degreeType); 

	
	void print(); // displays student data

};
