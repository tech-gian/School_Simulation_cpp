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



// School Functions

School::~School() {
    delete yard;
    delete stairs;
    for (int i=0 ; i<3 ; i++) delete floors[i];

    cout << "A School to be destroyed!" << endl;
}

void School::enter(Student& s) {
    cout << s.get_name() << " enters school!" << endl;

    yard->enter(s);
    s = yard->exit();

    stairs->enter(s);
    s = stairs->exit();

    floors[s.get_flo()]->enter(s);
}

void School::print(void) const {
    cout << "School life consists of: " << endl;

    for (int i=0 ; i<3 ; i++) floors[i]->print();
}



// Yard Functions

Yard::~Yard() {
    cout << "A Schoolyard to be destroyed!" << endl;
}

void Yard::enter(Student& s) {
    this->student = &s;
    cout << s.get_name() << " enters schoolyard!" << endl;
}

Student& Yard::exit(void) {
    cout << this->student->get_name() << " exits schoolyard!" << endl;
    return *student;
}



// Stairs Functions

Stairs::~Stairs() {
    cout << "A Stairs to be destroyed!" << endl;
}

void Stairs::enter(Student& s) {
    this->student = &s;
    cout << s.get_name() << " enters stairs!" << endl;
}

Student& Stairs::exit(void) {
    cout << this->student->get_name() << " exits stairs!" << endl;
    return *student;
}



// Floor Functions

Floor::~Floor() {
    for (int i=0 ; i<6 ; i++) delete classes[i];
    delete corridor;
    
    cout << "A Floor to be destroyed!" << endl;
}

void Floor::enter(Student& s) {
    cout << s.get_name() << " enters floor!" << endl;

    corridor->enter(s);
    s = corridor->exit();

    classes[s.get_cls()]->enter(s);
}

void Floor::print(void) const {
    cout << "Floor number " << no << "contains: " << endl;

    for (int i=0; i<6 ; i++) classes[i]->print();
}



// Corridor Functions

Corridor::~Corridor() {
    cout << "A Corridor to be destroyed!" << endl;
}

void Corridor::enter(Student& s) {
    this->student = &s;
    cout << s.get_name() << " enters corridor!" << endl;
}

Student& Corridor::exit(void) {
    cout << this->student->get_name() << " exits corridor!" << endl;
    return *student;
}



// Class Functions

Class::~Class() {
    cout << "A Class to be destroyed!" << endl;
}

void Class::enter(Student& s) {
    if (size < Cclass) {
        s.set_cls();
        this->students[size] = &s;
        this->size++;
    }

    cout << s.get_name() << " enters classroom!" << endl;
}

void Class::print(void) const {
    cout << "People in class " << no << "are: " << endl;

    for (int i=0 ; i<size ; i++) students[i]->print();
    teacher->print();
}



