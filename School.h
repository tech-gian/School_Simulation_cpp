/////////////////////////
// Header file for School
/////////////////////////



// Include libraries
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>


using namespace std;

//////////
// Classes



// Person
class Person {
    string name;    // Person's name
    int no_flo;     // Floor's number
    int no_cls;     // Class's number
    bool in_cls;    // True if in class
    int tired;      // Counter for tiredness


    public:
    // Constructor
    Person(string name, int nf, int nc): name(name), no_flo(nf), no_cls(nc), in_cls(false), tired(0) {}

    // Destructor
    // ~Person();

    // Print function
    virtual void print(void) const = 0;
    //////////////////////////
    // MAKE sure it's ABSTRACT
    // CHECK logically copy constructors

    // Get name
    string get_name(void) const { return this->name; }
    // Get  no_flo
    int get_flo(void) const { return this->no_flo; }
    // Get no_cls
    int get_cls(void) const { return this->no_cls; }
    // Get in_cls
    bool get_in(void) const { return this->in_cls; }
    // Get tired
    int get_tired(void) const { return this->tired; }

};



// Teacher
class Teacher: public Person {


    public:
    // Constructor
    Teacher(string name, int nf, int nc): Person(name, nf, nc) {
        cout << "A New Teacher has been created!" << endl;
    }

    // Destructor
    ~Teacher();

    // Copy Constructor
    Teacher(const Teacher& t): Person(t) {}

    // Print Teacher
    void print(void) const;


};



// Student
class Student: public Person {
    bool senior;    // True if student is senior

    public:
    // Constructor
    Student(string name, int nf, int nc, bool senior): Person(name, nf, nc), senior(senior) {
        cout << "A New Student has been created!" << endl;
    }

    // Destructor
    ~Student();

    // Copy Constructor
    Student(const Student& s): Person(s), senior(s.senior) {}

    // Print Student
    void print(void) const { Person::print(); };

    // Get senior / junior
    bool get_senior(void) const { return this->senior; }

};



