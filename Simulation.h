#include "PersonBST.h"
#include "Student.h"
#include "Faculty.h"
#include "Person.h"
using namespace std;

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
        void printStudentsAdivsor(int studID);
        void printAdvisorsStudents(int facID);
//   void addStudent();
//   void deleteStudent(int studID);
// //  void addFaculty();
// //  void deleteFaculty();
// //  void changeStudentsAdvisor(int studID, int facID);
// //  void removeAdvisee(int studID, int facID);
//   // Rollback();
//   void exitProgram();
  // Serialize();
    private:
        PersonBST<Student> *studentBST;
        PersonBST<Faculty> *facultyBST;

};
