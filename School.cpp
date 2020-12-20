///////////////////////////
// Implementation of School
///////////////////////////


// Include header file
#include "School.h"



// Person Functions

Person::~Person() {
    cout << "A Person to be destroyed!" << endl;
}

void Person::print(void) const {
    cout << this->name << " " << this->tired << endl;
}



// Teacher Functions

Teacher::~Teacher() {
    cout << "A Teacher to be destroyed!" << endl;
}

void Teacher::teach(int N, int Lt) {
    // Add hours * Lt
    this->tired += (N * Lt);
}

void Teacher::print(void) const {
    cout << "The teacher is: ";
    Person::print();
}



// Student Functions

Student::~Student() {
    cout << "A Student to be destroyed!" << endl;
}



// Junior Functions

Junior::~Junior() {
    cout << "A Junior to be destroyed!" << endl;
}

void Junior::attend(int N, int L) {
    // Add hours * Lj
    this->tired += (N * L);
}



// Senior Functions

Senior::~Senior() {
    cout << "A Senior to be destroyed!" << endl;
}

void Senior::attend(int N, int L) {
    // Add hours * Ls
    this->tired += (N * L);
}



// Room Functions

Room::~Room() {
    cout << "A Room to be destroyed!" << endl;
}



// School Functions

School::~School() {
    // Delete memore allocated
    delete yard;
    delete stairs;
    for (int i=0 ; i<3 ; i++) delete floors[i];

    cout << "A School to be destroyed!" << endl;
}

void School::enter(Student* s) {
    cout << s->get_name() << " enters school!" << endl;

    // When Student enters school,
    // he goes all the way to his Class
    yard->enter(s);
    s = yard->exit();

    stairs->enter(s);
    s = stairs->exit();

    floors[s->get_flo()]->enter(s);
}

void School::place(Teacher* t) {
    // Teacher is just placed in his Class
    this->floors[t->get_flo()]->place(t);
}

void School::operate(int N) const {
    // Calling operate for each floor
    for (int i=0 ; i<3 ; i++) floors[i]->operate(N, Lj, Ls, Lt);
}

void School::print(void) const {
    cout << "School life consists of:" << endl;

    for (int i=0 ; i<3 ; i++) floors[i]->print();
}



// Yard Functions

Yard::~Yard() {
    cout << "A Schoolyard to be destroyed!" << endl;
}

void Yard::enter(Student* s) {
    // Temporary save Student
    this->student = s;
    cout << s->get_name() << " enters schoolyard!" << endl;
}

Student* Yard::exit(void) {
    // Return Student
    cout << this->student->get_name() << " exits schoolyard!" << endl;
    return student;
}



// Stairs Functions

Stairs::~Stairs() {
    cout << "A Stairs to be destroyed!" << endl;
}

void Stairs::enter(Student* s) {
    // Temporary save Student
    this->student = s;
    cout << s->get_name() << " enters stairs!" << endl;
}

Student* Stairs::exit(void) {
    // Return Student
    cout << this->student->get_name() << " exits stairs!" << endl;
    return student;
}



// Floor Functions

Floor::~Floor() {
    for (int i=0 ; i<6 ; i++) delete classes[i];
    delete corridor;
    
    cout << "A Floor to be destroyed!" << endl;
}

void Floor::enter(Student* s) {
    cout << s->get_name() << " enters floor!" << endl;

    // Continue the way of Student to Class
    corridor->enter(s);
    s = corridor->exit();

    classes[s->get_cls()]->enter(s);
}

void Floor::place(Teacher* t) {
    // Teacher is placed
    this->classes[t->get_cls()]->place(t);    
}

void Floor::operate(int N, int Lj, int Ls, int Lt) const {
    // Calling operate for each Class
    for (int i=0 ; i<6 ; i++) {
        classes[i]->operate(N, Lj, Ls, Lt);
    }
}

void Floor::print(void) const {
    cout << "Floor number " << no << " contains:" << endl;

    for (int i=0; i<6 ; i++) classes[i]->print();
}



// Corridor Functions

Corridor::~Corridor() {
    cout << "A Corridor to be destroyed!" << endl;
}

void Corridor::enter(Student* s) {
    // Temporary save Student
    this->student = s;
    cout << s->get_name() << " enters corridor!" << endl;
}

Student* Corridor::exit(void) {
    // Return Student
    cout << this->student->get_name() << " exits corridor!" << endl;
    return student;
}



// Classroom Functions

Classroom::~Classroom() {
    cout << "A Class to be destroyed!" << endl;

    delete[] this->students;
}

void Classroom::enter(Student* s) {
    if (size < Cclass) {
        // Add Student to students
        // and set him in Classroom
        s->set_cls();
        this->students[size] = s;
        this->size++;
    }

    cout << s->get_name() << " enters classroom!" << endl;
}

void Classroom::place(Teacher* t) {
    this->teacher = t;

    // Change teacher's inside bool
    t->get_in();

    cout << t->get_name() << " places in classroom!" << endl;
}

void Classroom::operate(int N, int Lj, int Ls, int Lt) const {
    if (teacher != NULL) this->teacher->teach(N, Lt);

    for (int i=0 ; i<size ; i++) {
        // If Student is Junior
        if (students[i]->get_cls() < 3) students[i]->attend(N, Lj);
        // If Student is Senior
        else students[i]->attend(N, Ls);
    }
}

void Classroom::print(void) const {
    cout << "People in class " << no << " are:" << endl;

    // For all students in Classroom
    for (int i=0 ; i<size ; i++) students[i]->print();

    // If teacher is in Classroom
    if (teacher != NULL) teacher->print();
}
