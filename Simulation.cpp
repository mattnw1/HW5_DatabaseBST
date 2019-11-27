#include "Simulation.h"
#include <stack>


Simulation::Simulation()
{

}
Simulation::Simulation(PersonBST<Student> *s, PersonBST<Faculty> *f)
{
    studentBST = s;
    facultyBST = f;
    historyStack = new GenStack<DBHistory<Student>>(10);

}
Simulation::~Simulation()
{

}


void Simulation::run(){


    Student *student1 = new Student("John Appleseed", 1738, "Senior", "Chemical Engineering", 3.455, 2000);
    cout << "-----------------------------------------------------------" << endl;
    cout << student1->getName() << endl;
    cout << "Above is a test of Student Class Methods" << endl;
    cout << "-----------------------------------------------------------" << endl;
    Student *student2 = new Student("John Appleseed", 1738, "Senior", "Chemical Engineering", 3.455, 2000);


//TEST FOR ROLL BACK






    // DBHistory<Student> *added = new DBHistory<Student>(student1, false);
    // stack<DBHistory<Student>*> *s = new stack<DBHistory<Student>*>;
    // s->push(added);
    // s->top()->getPerson()->getInfo();





//test for ROLL BACK



    // studentBST = new PersonBST<Student>();
    // studentBST->insert(student1->getID(), student1);

    cout << "-----------------------------------------------------------" << endl;
    Faculty *faculty1 = new Faculty("Steve Jobs", 2000, "President", "Fowler School of Engineering");
    Faculty *faculty2 = new Faculty("Steve", 69, "Pres", "Fowler");
    Faculty *faculty3 = new Faculty("Mark twain", 9, "Pres", "Fowler");

    faculty1->addStudent(1738);
    faculty1->addStudent(10);
        faculty1->addStudent(17);
    facultyBST = new PersonBST<Faculty>();
    facultyBST->insert(faculty2->getID(), faculty2);
    facultyBST->insert(faculty1->getID(), faculty1);
    facultyBST->insert(faculty3->getID(), faculty3);




    // cout << endl;
    // cout << endl;
    // cout << "Print all students-------------------\n";
    // printAllStudents();
    // cout << "Print all faculty-------------------\n";
    // cout << endl;
    // cout << endl;
    // printAllFaculty();
    // cout << "Find Student -----------\n";
    // findStudent(1738)->getInfo();
    // cout << "Find faculty -----------\n";
    // findFaculty(69)->getInfo();
    // cout << endl;
    // cout << "print student advisors------\n";
    // printStudentsAdivsor(1738);
    // cout << "print advisors students----------\n";
    // printAdvisorsStudents(2000);

    //  addStudent();
    // cout << endl;
    // cout << "NEW STUDENT ADDED" << endl;
    // printAllStudents();
    //
    // historyStack->peek()->getPerson()->getName();
    //
    // cout << "delete student\n";
    // deleteStudent(1738);
    // printAllStudents();
    // addFaculty();
    // cout << endl;
    // cout << "NEW Faculty ADDED" << endl;
    // printAllFaculty();
    // cout << "delete faculty\n";
    // deleteFaculty(2000);
    // printAllFaculty();

    // cout << "Change student advisor\n";
    // changeStudentsAdvisor(1738, 9);
    //
    // removeAdvisee(1738,9);
    // printAllStudents();
    //
    // printAllFaculty();



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
    string studName;
    int idNum;
    string levelF;
    string maj;
    double gradepoint;
    int advisor;

    cout << "Enter student name: ";
    getline(cin, studName);
    cout << "Enter student ID Number: ";
    cin >> idNum;
    cout << "Enter year: ";
    cin >> levelF;
    cin.ignore(1024, '\n');
    cout << "Enter your major: ";
    getline(cin, maj);
    cout << "Enter your GPA: ";
    cin >> gradepoint;
    cout << "Enter your advisor's id: ";
    cin >> advisor;
    if(findFaculty(advisor) == NULL){
        cout << "This advisor does not exist, make sure you enter the proper advisor ID\n";
    }
    else{
        // Student *s = new Student(studName, idNum, levelF, maj, gradepoint, advisor);
        // studentBST->insert(s->getID(), s);
        // DBHistory<Person> *added = new DBHistory<Person>(s, false);
        // cout << "Check 1\n";
        // historyStack->push(added);
        // cout << "Check 2\n";
    }
}
void Simulation::deleteStudent(int studID)
{
    if(findStudent(studID) == NULL)
        cout << "That student ID does not exist\n";
    else
        studentBST->deleteNode(studID);
}
void Simulation::addFaculty()
{
    string facName;
    int idNum;
    string levelF;
    string depart;
    cout << "Enter Faculty name: ";
    getline(cin, facName);
    cout << "Enter faculty ID Number: ";
    cin >> idNum;
    cin.ignore(1024, '\n');
    cout << "Enter level of faculty: ";
    cin >> levelF;
    cin.ignore(1024, '\n');
    cout << "Enter their department: ";
    getline(cin, depart);
    Faculty *f = new Faculty(facName, idNum, levelF, depart);
    facultyBST->insert(f->getID(), f);

}
void Simulation::deleteFaculty(int facID) // see if it will delete faculty you just added
{
    if(findFaculty(facID) == NULL)
        cout << "That faculty ID does not exist\n";
    else
        facultyBST->deleteNode(facID);
}
void Simulation::changeStudentsAdvisor(int studID, int facID)
{
    if(studentBST->search(studID) == NULL){//if that stuent doesn't exist
        cout << "student ID does not exist\n";
    }
    else if(facultyBST->search(facID) == NULL){//if the faculty memeber doesnt exist
        cout << "advisor id does not exist\n";
    }
    else{//both people exist
        if(studentBST->search(studID)->getAdvisorID() != facID){//check to see they are already connected
            removeAdvisee(studID, studentBST->search(studID)->getAdvisorID());
            studentBST->search(studID)->setAdvisor(facID);
            facultyBST->search(facID)->addStudent(studID);
        }
    }
}
void Simulation::removeAdvisee(int studID, int facID)
{
    if(studentBST->search(studID) == NULL)
        cout << "student ID does not exist\n";

    else if(facultyBST->search(facID) == NULL)
        cout << "advisor id does not exist\n";

    else
        facultyBST->search(facID)->removeFacultyAdvisee(studID);
        studentBST->search(studID)->setAdvisor(0);
}

// void Simulation::Rollback()
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
