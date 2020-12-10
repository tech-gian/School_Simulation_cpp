/////////////////////////
// Header file for School
/////////////////////////



// Include libraries
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

// Include only for convert int to string
#include <sstream>


using namespace std;

//////////
// Classes



// Person
class Person {
    string name;    // Person's name
    int no_flo;     // Floor's number
    int no_cls;     // Class's number

    protected:
    bool in_cls;    // True if in class
    int tired;      // Counter for tiredness

    public:
    // Constructor
    Person(string name, int nf, int nc): name(name), no_flo(nf), no_cls(nc), in_cls(false), tired(0) {}

    // Destructor
    virtual ~Person() {}

    // Print function
    virtual void print(void) const = 0;

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

    // Set in_cls
    void set_cls(void) { this->in_cls = true; }
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
    Teacher(const Teacher& t): Person(t.get_name(), t.get_flo(), t.get_cls()) {
        cout << "A New Teacher copied!" << endl;
    }

    // Teach teacher
    void teach(int N, int Lt);

    // Print Teacher
    void print(void) const;
};



// Student
class Student: public Person {

    public:
    // Constructor
    Student(string name, int nf, int nc): Person(name, nf, nc) {
        cout << "A New Student has been created!" << endl;
    }

    // Destructor
    virtual ~Student();

    // Attend student
    virtual void attend(int N, int L) = 0;

    // Print Student
    virtual void print(void) const = 0;
};



// Junior
class Junior: public Student {

    public:
    // Constructor
    Junior(string name, int nf, int nc): Student(name, nf, nc) {
        cout << "A New Junior has been created!" << endl;
    }

    // Destructor
    ~Junior();

    // Copy Constructor
    Junior(const Junior& j): Student(j.get_name(), j.get_flo(), j.get_cls()) {
        cout << "A Junior has been copied!" << endl;
    }

    // Attend Junior
    void attend(int N, int L);

    // Print Junior
    void print(void) const { Person::print(); }
};



// Senior
class Senior: public Student {

    public:
    // Constructor
    Senior(string name, int nf, int nc): Student(name, nf, nc) {
        cout << "A New Senior has been created!" << endl;
    }

    // Destructor
    ~Senior();

    // Copy Constructor
    Senior(const Senior& s): Student(s.get_name(), s.get_flo(), s.get_cls()) {
        cout << "A New Senior has been copied!" << endl;
    }

    // Attend Senior
    void attend(int N, int L);

    // Print Senior
    void print(void) const { Person::print(); }
};



// Room
class Room {

    protected:
    Student* student;       // Keep student when enters Room

    public:
    // Constructor
    Room() {
        cout << "A New Room has been created!" << endl;
    }

    // Destructor
    virtual ~Room();

    // Enter student in room
    virtual void enter(Student* s) = 0;

    // Exit student from room
    virtual Student* exit(void) = 0;
};



// Yard
class Yard: public Room {

    public:
    // Constructor
    Yard(): Room() {
        cout << "A New Yard has been created!" << endl;
    }

    // Destructor
    ~Yard();

    // Enter student in yard
    void enter(Student* s);
    // Exit student from yard
    Student* exit(void);
};



// Stairs
class Stairs: public Room {

    public:
    // Constructor
    Stairs(): Room() {
        cout << "A New Stairs has been created!" << endl;
    }

    // Destructor
    ~Stairs();

    // Enter student in stairs
    void enter(Student* s);
    // Exit student from stairs
    Student* exit(void);
};



// Corridor
class Corridor: public Room {

    public:
    // Constructor
    Corridor(): Room() {
        cout << "A New Corridor has been created!" << endl;
    }

    // Destructor
    ~Corridor();

    // Enter student in corridor
    void enter(Student* s);
    // Exit student from corridor
    Student* exit(void);
};



// Class
class Class {
    int no;                 // Number of Class

    Teacher* teacher;       // Teacher of Class
    Student** students;     // Students of Class
    int size;               // How many students there are

    int Cclass;             // Capacity of Class

    public:
    // Constructor
    Class(int no, int Cclass): no(no), size(0), Cclass(Cclass) {
        cout << "A New Class has been created!" << endl;
        students = new Student*[Cclass];
        teacher = NULL;
    }

    // Destructor
    ~Class();

    // Enter student in class
    void enter(Student* s);

    // Place teacher in class
    void place(Teacher* t);

    // Operate class
    void operate(int N, int Lj, int Ls, int Lt) const;

    // Get Cclass
    int get_ccls(void) const { return this->Cclass; }

    // Print
    void print(void) const;
};



// Floor
class Floor {
    int no;                 // Number of Floor

    Class* classes[6];      // Classes
    Corridor* corridor;     // Corridor

    public:
    // Constructor
    Floor(int no, int Cclass): no(no) {
        cout << "A New Floor has been created!" << endl;
        for (int i=0 ; i<6 ; i++) classes[i] = new Class(i, Cclass);
        corridor = new Corridor();
    }

    // Destructor
    ~Floor();

    // Enter student in floor
    void enter(Student* s);

    // Place teacher in floor
    void place(Teacher* t);

    // Operate floor
    void operate(int N, int Lj, int Ls, int Lt) const;

    // Get Cclass
    int get_ccls(void) const { return this->classes[0]->get_ccls(); }

    // Print
    void print(void) const;
};



// School
class School {
    Floor* floors[3];       // Floors
    Yard* yard;             // Yard
    Stairs* stairs;         // Stairs

    int Lj;                 // Units for Junior
    int Ls;                 // Units for Senior
    int Lt;                 // Units for Teacher

    public:
    // Constructor
    School(int Lj, int Ls, int Lt, int Cclass): Lj(Lj), Ls(Ls), Lt(Lt) {
        cout << "A New School has been created!" << endl;
        yard = new Yard();
        stairs = new Stairs();
        for (int i=0 ; i<3 ; i++) floors[i] = new Floor(i, Cclass);
    }

    // Destructor
    ~School();

    // Copy constructor
    School(School& s): Lj(s.Lj), Ls(s.Ls), Lt(s.Lt) {
        yard = new Yard();
        stairs = new Stairs();
        for (int i=0 ; i<3 ; i++) floors[i] = new Floor(i, s.floors[0]->get_ccls());
    }

    // Enter student in school
    void enter(Student* s);

    // Place teacher in school
    void place(Teacher* t);

    // Operate school
    void operate(int N) const;

    // Print
    void print(void) const;
};
