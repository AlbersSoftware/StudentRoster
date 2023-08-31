#include <iostream>
#include "roster.h"
//#include "student.h"
//#include "degree.h"
#include <iomanip>
#include <sstream>

#pragma once


using namespace std;

Roster classRoster; 

//class Roster;



int main()
{
    cout << "C867-Scripting and programming applications in C++\n Student ID# 009877757\n Chris Albers" << endl;

    const string studentData[] = {
            "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY","A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
            "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
            "A5,Chris,Albers,calbe@wgu.edu,29,14,30,19,SOFTWARE" };



    const int numofstudents = 5;//sets array size
    Roster roster; // creates roster using defualt parameterless constructor 

    for (int i = 0; i < numofstudents; i++) // parsing each row of student data
        roster.parse(studentData[i]);
    cout << "Display all students-" << endl;
    roster.printAll(); // prints all students and required data in roster
    cout << endl;

    cout << "Displaying invalid email addess: " << endl;
    roster.printInvalidEmails(); // prints invalid emails
    cout << endl;


    cout << "Displaying average days per class:" << endl;
    for (int i = 0; i < numofstudents; i++)
    {

        roster.printAverageDays(roster.classRosterArray[i]->getstuID()); // displays student ID and averages associated to each

    }
    cout << endl;



    cout << "Display all software students-" << endl;
    roster.printDegreeProgram(SOFTWARE); // displays all software students only
    cout << endl;


   // cout << "Display all network students-" << endl;
   // roster.printDegreeProgram(NETWORK);
   // cout << endl;

   // cout << "Display all security students-" << endl;
   // roster.printDegreeProgram(SECURITY);
  //  cout << endl;



        cout << "Remove student A3." << endl;
        roster.removeStudent("A3"); // removes student from the roster
        cout << endl;
       
        cout << "Remove student A3." << endl;
        roster.removeStudent("A3"); // we do this twice because we now want to draw the error not found to be removed.
        cout << endl << endl;

        system("pause"); // holds window open for destructor.
        return 0;
    }


























