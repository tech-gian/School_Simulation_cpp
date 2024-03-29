///////////////////////////////
// Main function to test School
///////////////////////////////



// Include header file
#include "School.h"



int main(int argc, char* argv[]) {

    // Get parameters
    int Cclass = atoi(argv[1]);
    int Lj = atoi(argv[2]);
    int Ls = atoi(argv[3]);
    int Lt = atoi(argv[4]);
    int N = atoi(argv[5]);


    // Create School
    School school(Lj, Ls, Lt, Cclass);


    // Create Students and Teachers
    int size_stud = Cclass * 3 * 6;
    Student** students = new Student*[size_stud];
    int nf=0;

    for (int i=0 ; i<size_stud ; i++) {
        if (i % 6 == 0 && i != 0) nf++;

        // Converting int to string
        // Could use to_string, but not available in c++98
        ostringstream str1;
        str1 << i;
        string temp = str1.str();

        if (i%6 < 3) students[i] = new Junior("Junior_name" + temp, nf%3, i%6);
        else students[i] = new Senior("Senior_name" + temp, nf%3, i%6);
    }

    int size_teacher = 3 * 6;
    Teacher** teachers = new Teacher*[size_teacher];
    nf = 0;

    for (int i=0 ; i<size_teacher ; i++) {
        if (i % 6 == 0 && i != 0) nf++;

        // Converting int to string
        // Could use to_string, but not available in c++98
        ostringstream str1;
        str1 << i;
        string temp = str1.str();

        teachers[i] = new Teacher("Teacher_name" + temp, nf, i%6);
    }


    // Get students and teacher in the school
    // with random order

    srand(time(NULL));
    int i=0, j=0;
    bool stud;          // True if we stopped in student

    // While all students or all teachers enter school,
    // pick one random to get in
    while (true) {
        if (rand() % 2 == 0) {
            if (i >= size_stud) {
                stud = false;
                break;
            }

            school.enter(students[i]);
            i++;
        }
        else {
            if (j >= size_teacher) {
                stud = true;
                break;
            }

            school.place(teachers[j]);
            j++;
        }
    }

    // If there are students to enter school
    if (stud) {
        for (int k=i ; k<size_stud ; k++) {
            school.enter(students[k]);
        }
    }
    // If there are teachers to place in school
    else {
        for (int k=j ; k<size_teacher ; k++) {
            school.place(teachers[k]);
        }
    }


    // School should operate for N hours
    school.operate(N);


    // Print out school
    school.print();



    // Delete Students and Teachers
    for (int i=0 ; i<size_stud ; i++) {
        delete students[i];
    }
    delete[] students;

    for (int i=0 ; i<size_teacher ; i++) {
        delete teachers[i];
    }
    delete[] teachers;


    return 0;
}
