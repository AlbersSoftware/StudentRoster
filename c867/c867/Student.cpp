# include "student.h"
#include "degree.h"
using namespace std;


Student::Student()// sets defualt values, parameterless constructor
{
    this->studentID = ""; // empty string is useful here because data comes from multiple sources. NULL is nothing and is conceptually a pointer though the inilizations are the same.
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    this->degreeType = EnumDegreeProgram::SOFTWARE;
   
    for (int i = 0; i < daysInCourse; i++) this->courseNumDays[i] = 0;

}




    Student::Student( string studentID,string firstName, string lastName, string emailAddress,
        int age, int courseNumDays[], EnumDegreeProgram degreeType)

    {
        // used to modify object and distinguish parameter and feild
        this->studentID = studentID;
        this->firstName = firstName;
        this->lastName = lastName;
        this -> emailAddress = emailAddress;
        this->age = age;
        this->degreeType = degreeType;
        for (int i = 0; i < daysInCourse; i++) this->courseNumDays[i] = courseNumDays[i];



    }

   



    //accessors

    string Student::getstuID() { return this->studentID; }
    string Student::getFirstName() { return this->firstName; }
    string Student::getLastName() { return this->lastName; }
    int Student::getAge() { return this->age; }
    string Student::getemail() { return this->emailAddress; }
    int* Student::getcourseNumDays() { return this->courseNumDays; } // is constant
    EnumDegreeProgram Student::getDegreeType() { return this->degreeType; }


    // setters
    void Student::setstuID(string studentID) { this->studentID = studentID; }
    void Student::setfirstName(string firstName) { this->firstName = firstName; }
    void Student::setlastName(string lastName) { this->lastName = lastName; }
    void Student::setAge(int age) { this->age = age; }
    void Student::setemail(string email) { this->emailAddress = email; }
    void Student::setcourseNumDays(int courseNumDays[]) 
    {
        for (int i = 0; i < 3; i++) this->courseNumDays[i] = courseNumDays[i]; 

    }
    void Student::setDegreeType(EnumDegreeProgram degreeType) { this->degreeType = degreeType; } 

    
   
    void Student::print()
    { //print out the objects, header and objects were aligned off so I used setw to help in addition to tabs '\t'.
        cout << "ID |  First  |   Last      | Age       | Days In Course |   Degree Type\n";
        cout << this->getstuID() << '\t';
        cout << setw(5) << left << this->getFirstName() << '\t';
        cout << setw(8) << right << this->getLastName() << '\t';
        cout << setw(2) << left << this->getAge() << '\t';
       // cout << setw(25) << right << this->getemail() << '\t';
        // getcourseNumDays returns a pointer not an integer so I did them indivdualy to get the 0 item.
        cout << this->getcourseNumDays()[0] << ',';
        cout << this->getcourseNumDays()[1] << ',';
        cout << this->getcourseNumDays()[2] << '\t';
        cout << setw(10) << right << degreeProgramStrings[this->getDegreeType()] <<"\n" ; // turned into a string representation in degree.h to avoid getting an integer here.


    }
    Student :: ~Student() {} //destructor, nothing dynamically inside student class but is in best practice to include anyway.