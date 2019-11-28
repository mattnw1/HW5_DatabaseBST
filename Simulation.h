#include "PersonBST.h"
#include "Student.h"
#include "Faculty.h"
#include "Person.h"
#include "GenStack.h"
#include "DBHistory.h"
#include <stack>
using namespace std;

// /*Michael Kulinich
// 2328386
// kulinich@chapman.edu
// Matthew Nwerem
// 2277158
// nwere100@mail.chapman.edu

class Simulation
{
    public:

        Simulation();
        Simulation(PersonBST<Student> *s, PersonBST<Faculty> *f);
        ~Simulation();

        void run();



        void printAllStudents();
        void printAllFaculty();
        Student* findStudent(int idNum);
        Faculty* findFaculty(int idNum);
        void printStudentsAdvisor(int studID);
        void printAdvisorsStudents(int facID);
        void addStudent();
        void deleteStudent(int studID);
        void addFaculty();
        void deleteFaculty(int facID);
        void changeStudentsAdvisor(int studID, int facID);
        void removeAdvisee(int studID, int facID);
//   // Rollback();
        void exitProgram();
  // Serialize();
    private:
        PersonBST<Student> *studentBST;
        PersonBST<Faculty> *facultyBST;
        GenStack<DBHistory<Student> > *historyStack;


};
