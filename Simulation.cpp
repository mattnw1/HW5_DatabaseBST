#include "Simulation.h"


Simulation::Simulation()
{

}
Simulation::Simulation(PersonBST<Student> *s, PersonBST<Faculty> *f)
{
    studentBST = s;
    facultyBST = f;

}
Simulation::~Simulation()
{

}


void Simulation::run(){
    Student *student1 = new Student("John Appleseed", 1738, "Senior", "Chemical Engineering", 3.455, 1111);
    cout << "-----------------------------------------------------------" << endl;
    student1->getInfo();
    cout << "Above is a test of Student Class Methods" << endl;
    cout << "-----------------------------------------------------------" << endl;


    studentBST = new PersonBST<Student>();
    studentBST->insert(student1->getID(), student1);

    cout << "-----------------------------------------------------------" << endl;
    Faculty *faculty1 = new Faculty("Steve Jobs", 2000, "President", "Fowler School of Engineering");
    facultyBST = new PersonBST<Faculty>();
    facultyBST->insert(faculty1->getID(), faculty1);
    faculty1->addStudent(1111);
    faculty1->addStudent(1212);

    cout << endl;
    cout << endl;
    cout << "Print all students-------------------\n";
    printAllStudents();
    cout << "Print all faculty-------------------\n";
    cout << endl;
    cout << endl;
    printAllFaculty();
    cout << "Find Student -----------\n";
    findStudent(1738)->getInfo();
    cout << "Find faculty -----------\n";
    findStudent(1738)->getInfo();
    cout << endl;
    cout << "print student advisors------\n";
    printStudentsAdivsor(1738);
    cout << "print advisors students----------\n";
    printAdvisorsStudents(2000);


}



void Simulation::printAllStudents()
{
  studentBST->printTree();
}


void Simulation::printAllFaculty()
{
    facultyBST->printTree();
}


Student* Simulation::findStudent(int idNum)
{
    return studentBST->search(idNum);
}
Faculty* Simulation::findFaculty(int idNum)
{
    return facultyBST->search(idNum);
}
void Simulation::printStudentsAdivsor(int studID)
{
    cout << studentBST->search(studID)->getAdvisorID() << endl;
}
void Simulation::printAdvisorsStudents(int facID)
{
    facultyBST->search(facID)->getStudentIDs();
}
void Simulation::addStudent() // HANDLE USER ERROR!!!!!!
{
    // string studname;
    // int idNum;
    // string levelF;
    // string maj;
    // double gradepoint;
    // int advisor
    //
    // cout << "Enter student name: ";
    // cin >> studName;
    // cout << "Enter student ID Number: ";
    // cin >> idNum;
    // cout << "Enter year: ";
    // cin >> levelF;
    // cout << "Enter your major: ";
    // cin >> maj;
    // cout << "Enter your GPA: ";
    // cin >> gradepoint;
    // cout << "Enter your advisor's id: ";
    // cin >> advisor;
    // if(advisor)
}
// void deleteStudent(int studID)
// {
//
// }
// // void addFaculty()
// {
//
// }
// // void deleteFaculty()
// {
//
// }
// // void changeStudentsAdvisor(int studID, int facID)
// {
//
// }
// // void removeAdvisee(int studID, int facID)
// {
//
// }
//
// // Rollback()
// {
//
// }
// void exitProgram()
// {
//
// }
//
// // Serialize()
// {
//
// }
