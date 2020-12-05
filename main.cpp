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


    Student s("john", 0, 0, false);

    School school(Lj, Ls, Lt, Cclass);

    school.enter(s);



    return 0;
}
