#include "roster.h"
#include "degree.h"
#include"student.h"

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void Roster::parse(string studentData) //parse each row
{
    int rhs = studentData.find(','); // find first comma in the data, return index of that comma
    string StudentID = studentData.substr(0, rhs);// starts at index 0 not one, going out right hand side -1 just short of the comma because I dont want to assign comma to studentID

    int lhs = rhs + 1; // moves past comma with +1 because rhs remembers previous comma, then we assign it to lhs.
    rhs = studentData.find(",", lhs); // stops on the next comma and store back to rhs
    string firstName = studentData.substr(lhs, rhs - lhs); // gets exact number of chars to pull out between commas
    // same logic repeats for lastName, emailAddress, age, day1-3 and degree. day1-3 and age must parse as an integer but the logic is the same.
    lhs = rhs + 1;
    rhs = studentData.find(',', lhs);
    string lastName = studentData.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string emailAddress = studentData.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int age = stoi(studentData.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int day1 = stoi(studentData.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int day2 = stoi(studentData.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int day3 = stoi(studentData.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string degree = studentData.substr(lhs, rhs - lhs);


    EnumDegreeProgram degchoice = SOFTWARE; //defualt value software and if statements to denote other degree choices
    if (degree == "NETWORK") {
        degchoice = NETWORK;
    }
    else if (degree == "SECURITY") {
        degchoice = SECURITY;
    }

    add(StudentID, firstName, lastName, emailAddress, age, day1, day2, day3, degchoice); // call add method to pass in temp varaibles to make an object
}
    void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int  age, int day1,
        int day2, int day3, EnumDegreeProgram degreeType)
    {

        int days[3] = { day1, day2, day3 }; // put days back into an array for the constructor, (prefix is used) ++lastIndex, lastIndex starts at -1

        classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, days,degreeType);
    }
    // ^^Now that days are in an array we can call the full constructor to make a student^^



    void Roster::removeStudent(string studentID) // student to be removed

    {
        bool success = false; // assume its not present
        for (int i = 0; i <= Roster::lastIndex; i++) // use lastIndex to rearrange later

        {
            if (classRosterArray[i]->getstuID() == studentID) // if we match from parameter we change our boolean to true
            {
                success = true; // found student to remove
                if (i < numofstudents - 1) //index -1 is the last student
                {
                    Student* temp = classRosterArray[i]; // swaps with last student
                    classRosterArray[i] = classRosterArray[numofstudents - 1];
                    classRosterArray[numofstudents - 1] = temp;  
                }
                Roster::lastIndex--; // student no longer visible not actually deleted
            }
        }
        if (success) // if moved to lastIndex print student removed and reprint all, else print not found.
        {
            cout << studentID << "Student Removed!" << endl << endl;
            this->printAll(); // removed student is not displayed now.
        }
        else cout << studentID << " not found." << endl << endl;
    }






    void Roster::printAll() // display all students with required feilds
    {
      
        for (int i = 0; i < Roster::lastIndex+1 ; i++) // needed +1 after lastIndex because it also deleted student A4, with the +1 they come back to the table.
            if (classRosterArray[i] != nullptr)
            {
                classRosterArray[i]->Student::print();
            }
    }


   


    void Roster::printInvalidEmails() // First we assume no invalid emails and loop through each. Then grab email and run a check to see if there is a "  ", @, or a "."
        // if any condition is met then we change our boolean to true and print that email with the student ID to identify who's email it was.
        // if no invalid emails are there we print out NONE.
    {
        bool any = false;
        for (int i = 0; i <= Roster::lastIndex; i++)
        {
            string email = (classRosterArray[i]->getemail());
            if ((email.find(" ") != string::npos) || ((email.find("@") == string::npos)) || (email.find(".") == string::npos))

            {
                any = true;
                cout << email << ":" << classRosterArray[i]->getstuID() << endl;
            }
        }
        if (!any) cout << "NONE" << endl;
    }

    void Roster::printDegreeProgram(EnumDegreeProgram degreeType) // display only students who match the given degree type
    {
    // goes through roster and looks at each student gets parameter for given degree type and calls print method for that student
        for (int i = 0; i < numofstudents; ++i) {
            if (classRosterArray[i] != nullptr) {
                if (degreeType == classRosterArray[i]->Student::getDegreeType()) {
                    classRosterArray[i]->Student::print();

                }
                cout << endl;

            }
        }
            }
        
    
    void Roster::printAverageDays(string studentID)
    {
        for (int i = 0; i <= Roster::lastIndex; i++)
        {
           


            if (classRosterArray[i]->getstuID() == studentID) // get student ID and display for indeftifaction
            {
                cout <<"Student ID:"<< studentID << "-"<<endl;
                cout << (classRosterArray[i]->getcourseNumDays()[0] // get the days for the class roster array, index the getter subscript to a number
                   + classRosterArray[i]->getcourseNumDays()[1] // index of 1 to get the next day
                   + classRosterArray[i]->getcourseNumDays()[2]) / 3.0 << endl; // add them to index 2 and divide by 3.0 to get the average. We use 3.0 so we can still get floating point awnsers.
            }
        }
    }



  

    Roster::~Roster() //Destructor
    {
        cout << "Destructor call!" << ::endl << ::endl;
        for (int i = 0; i < numofstudents; i++) // numofstudents is all students, we use this instead of index
        {
            cout << "Removed student ID" << i + 1 << ::endl << ::endl; // announces that it is deleted
            delete classRosterArray[i]; // deletes
            classRosterArray[i] = nullptr; // nullptr stops it from crashing


        }
    }

