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

void Teacher::teach(int N, int Lt) {
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

// void Student::attend(int N, int Lj, int Ls) {
//     if (this->get_senior()) {
//         this->tired += (N * Ls);
//     }
//     else {
//         this->tired += (N * Lj);
//     }
// }



// Junior Functions

Junior::~Junior() {
    cout << "A Junior to be destroyed!" << endl;
}

void Junior::attend(int N, int L) {
    this->tired += (N * L);
}



// Senior Functions

Senior::~Senior() {
    cout << "A Senior to be destroyed!" << endl;
}

void Senior::attend(int N, int L) {
    this->tired += (N * L);
}



// Room Functions

Room::~Room() {
    cout << "A Room to be destroyed!" << endl;
}



// School Functions

School::~School() {
    delete yard;
    delete stairs;
    for (int i=0 ; i<3 ; i++) delete floors[i];

    cout << "A School to be destroyed!" << endl;
}

void School::enter(Student* s) {
    cout << s->get_name() << " enters school!" << endl;

    yard->enter(s);
    s = yard->exit();

    stairs->enter(s);
    s = stairs->exit();

    floors[s->get_flo()]->enter(s);
}

void School::place(Teacher* t) {
    this->floors[t->get_flo()]->place(t);
}

void School::operate(int N) const {
    for (int i=0 ; i<3 ; i++) floors[i]->operate(N, Lj, Ls, Lt);
}

void School::print(void) const {
    cout << "School life consists of: " << endl;

    for (int i=0 ; i<3 ; i++) floors[i]->print();
}



// Yard Functions

Yard::~Yard() {
    cout << "A Schoolyard to be destroyed!" << endl;
}

void Yard::enter(Student* s) {
    this->student = s;
    cout << s->get_name() << " enters schoolyard!" << endl;
}

Student* Yard::exit(void) {
    cout << this->student->get_name() << " exits schoolyard!" << endl;
    return student;
}



// Stairs Functions

Stairs::~Stairs() {
    cout << "A Stairs to be destroyed!" << endl;
}

void Stairs::enter(Student* s) {
    this->student = s;
    cout << s->get_name() << " enters stairs!" << endl;
}

Student* Stairs::exit(void) {
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

    corridor->enter(s);
    s = corridor->exit();

    classes[s->get_cls()]->enter(s);
}

void Floor::place(Teacher* t) {
    this->classes[t->get_cls()]->place(t);    
}

void Floor::operate(int N, int Lj, int Ls, int Lt) const {
    for (int i=0 ; i<6 ; i++) {
        classes[i]->operate(N, Lj, Ls, Lt);
    }
}

void Floor::print(void) const {
    cout << "Floor number " << no << " contains: " << endl;

    for (int i=0; i<6 ; i++) classes[i]->print();
}



// Corridor Functions

Corridor::~Corridor() {
    cout << "A Corridor to be destroyed!" << endl;
}

void Corridor::enter(Student* s) {
    this->student = s;
    cout << s->get_name() << " enters corridor!" << endl;
}

Student* Corridor::exit(void) {
    cout << this->student->get_name() << " exits corridor!" << endl;
    return student;
}



// Class Functions

Class::~Class() {
    cout << "A Class to be destroyed!" << endl;

    delete[] this->students;
}

void Class::enter(Student* s) {
    if (size < Cclass) {
        s->set_cls();
        this->students[size] = s;
        this->size++;
    }

    cout << s->get_name() << " enters classroom!" << endl;
}

void Class::place(Teacher* t) {
    this->teacher = t;

    // Change teacher's inside bool
    t->get_in();

    cout << t->get_name() << " places in classroom!" << endl;
}

void Class::operate(int N, int Lj, int Ls, int Lt) const {
    if (teacher != NULL) this->teacher->teach(N, Lt);

    for (int i=0 ; i<size ; i++) {
        if (students[i]->get_cls() < 3) students[i]->attend(N, Lj);
        else students[i]->attend(N, Ls);
        // CHECK that this is fine
    }
}

void Class::print(void) const {
    cout << "People in class " << no << " are: " << endl;

    for (int i=0 ; i<size ; i++) students[i]->print();

    if (teacher != NULL) teacher->print();
}
