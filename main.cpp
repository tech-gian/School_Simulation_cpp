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

        students[i] = new Student("Student_name" + to_string(i), nf%3, i%6);
    }

    int size_teacher = 3 * 6;
    Teacher** teachers = new Teacher*[size_teacher];
    nf = 0;

    for (int i=0 ; i<size_teacher ; i++) {
        if (i % 6 == 0 && i != 0) nf++;

        teachers[i] = new Teacher("Teacher_name" + to_string(i), nf, i%6);
    }


    // Get students and teacher in the school
    // with random order

    srand(time(NULL));
    int i=0, j=0;
    bool stud;   // True if we stopped in student


    while (true) {
        if (rand() % 2 == 0) {
            if (i >= size_stud) {
                stud = false;
                break;
            }

            school.enter(*students[i]);
            i++;
        }
        else {
            if (j >= size_teacher) {
                stud = true;
                break;
            }

            school.place(*teachers[j]);
            j++;
        }
    }

    if (stud) {
        for (int k=i ; k<size_stud ; k++) {
            school.enter(*students[k]);
        }
    }
    else {
        for (int k=j ; j<size_teacher ; k++) {
            school.place(*teachers[k]);
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
