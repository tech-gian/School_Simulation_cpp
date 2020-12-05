///////////////////////////
// Implementation of School
///////////////////////////


// Include header file
#include "School.h"



// Person Functions

void Person::print(void) const {
    cout << this->name << " " << this->tired << endl;
}



// Teacher Functions

Teacher::~Teacher() {
    cout << "A Teacher to be destroyed!" << endl;
}

void Teacher::print(void) const {
    cout << "The teacher is: ";
    Person::print();
}



// Student Functions

Student::~Student() {
    cout << "A Student to be destroyed!" << endl;
}



