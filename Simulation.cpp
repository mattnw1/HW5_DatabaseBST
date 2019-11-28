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

    int choice;
    int facId;
    int studId;
    while(true){

    cout << "What would you like to do (Pick a number)" << endl;
    cout << "1. Print all students and their information (sorted by ascending id #)" << endl;
    cout << "2. Print all faculty and their information (sorted by ascending id #)" << endl;
    cout << "3. Find and display student information given the students id" << endl;
    cout << "4. Find and display faculty information given the faculty id" << endl;
    cout << "5. Given a student’s id, print the name and info of their faculty advisor" << endl;
    cout << "6. Given a faculty id, print info of his/her advisees" << endl;
    cout << "7. Add a new student" << endl;
    cout << "8. Delete a student given the id" << endl;
    cout << "9. Add a new faculty member" << endl;
    cout << "10. Delete a faculty member given the id" << endl;
    cout << "11. Change a student’s advisor given the student id and the new faculty id" << endl;
    cout << "12. Remove an advisee from a faculty member given the ids" << endl;
    cout << "13. Rollback" << endl;
    cout << "14. Exit" << endl;

    cin >> choice;
    switch(choice){
        case 1:
            printAllStudents();
            break;
        case 2:
            printAllFaculty();
            break;
        case 3:
            cout << "What student are you looking for?" << endl;
            cout << "Type the student ID" << endl;
            cin >> studId;
            if(studentBST->search(studId)==NULL){
                cout << "No student has the ID number in system" << endl;
            }
            else{
                findStudent(studId)->getInfo();
            }
            cout << endl;
            break;
        case 4:
            cout << "What Faculty are you looking for?" << endl;
            cout << "Type the faculty ID" << endl;
            cin >> facId;
            if(facultyBST->search(facId)==NULL){
                cout << "No faculty has the ID number in system" << endl;
            }
            else{
                findFaculty(facId)->getInfo();
            }
            cout << endl;
            break;
        case 5:
            cout << "Whos student advisors are you looking for?" << endl;
            cout << "Type the student ID" << endl;
            cin >> studId;
            if(studentBST->search(studId)==NULL){
                cout << "No student has the ID number in system" << endl;
            }
            else{
                printStudentsAdvisor(studId);
            }
            cout << endl;
            break;
        case 6:
            cout << "Whos faculty advisees are you looking for?" << endl;
            cout << "Type the faculty ID" << endl;
            cin >> facId;
            if(facultyBST->search(facId)==NULL){
                cout << "No faculty has the ID number in system" << endl;
            }
            else{
                printAdvisorsStudents(facId);
            }
            cout << endl;
            break;
        case 7:
            addStudent();
            break;
        case 8:
            cout << "What student are you looking for to delete?" << endl;
            cout << "Type the student ID" << endl;
            cin >> studId;
            if(studentBST->search(studId)==NULL){
                cout << "No student has the ID number in system" << endl;
            }
            else{
                deleteStudent(studId);
            }
            cout << endl;
            break;
        case 9:
            addFaculty();
            break;
        case 10:
            cout << "What Faculty are you looking for to delete?" << endl;
            cout << "Type the faculty ID" << endl;
            cin >> facId;
            if(facultyBST->search(facId)==NULL){
                cout << "No faculty has the ID number in system" << endl;
            }
            else{
                deleteFaculty(facId);
            }
            cout << endl;
            break;
        case 11:
            cout << "What student are you looking for?" << endl;
            cout << "Type the student ID" << endl;
            cin >> studId;
            cout << "What Faculty are you looking for?" << endl;
            cout << "Type the faculty ID" << endl;
            cin >> facId;

            changeStudentsAdvisor(studId, facId);
            break;
        case 12:
            cout << "What student are you looking for?" << endl;
            cout << "Type the student ID" << endl;
            cin >> studId;
            cout << "What Faculty are you looking for?" << endl;
            cout << "Type the faculty ID" << endl;
            cin >> facId;
            removeAdvisee(studId, facId);
            break;
        case 13:
        case 14:
            cout << "Nice" << endl;
            break;
    }
    cin.clear();
    cin.ignore();
    cout << "Press Enter to Continue...\n" << endl;
    getchar();
}









    //
    // cout << "-----------------------------------------------------------" << endl;
    // cout << student1->getName() << endl;
    // cout << "Above is a test of Student Class Methods" << endl;
    // cout << "-----------------------------------------------------------" << endl;
    // Student *student2 = new Student("John Appleseed", 1738, "Senior", "Chemical Engineering", 3.455, 2000);


//TEST FOR ROLL BACK





    //
    // DBHistory<Student> *added = new DBHistory<Student>(student1, false);
    // stack<DBHistory<Student>*> *s = new stack<DBHistory<Student>*>;
    // s->push(added);
    // cout << s->top()->getPerson()->getName() << endl;;





//test for ROLL BACK





    // cout << "-----------------------------------------------------------" << endl;
    // Faculty *faculty1 = new Faculty("Steve Jobs", 2000, "President", "Fowler School of Engineering");
    // Faculty *faculty2 = new Faculty("Steve", 69, "Pres", "Fowler");
    // Faculty *faculty3 = new Faculty("Mark twain", 9, "Pres", "Fowler");
    //
    // faculty1->addStudent(1738);
    // faculty1->addStudent(10);
    //     faculty1->addStudent(17);
    // facultyBST = new PersonBST<Faculty>();
    // facultyBST->insert(faculty2->getID(), faculty2);
    // facultyBST->insert(faculty1->getID(), faculty1);
    // facultyBST->insert(faculty3->getID(), faculty3);




    // cout << endl;
    // cout << endl;
    cout << "Print all students-------------------\n";
    printAllStudents();
    cout << "Print all faculty-------------------\n";
    // cout << endl;
    // cout << endl;
    printAllFaculty();
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
    if(!studentBST->isEmpty()){
        studentBST->printTree();
    }
    else{
        cout << "There are no students" << endl;
    }
}


void Simulation::printAllFaculty()
{
    if(!facultyBST->isEmpty()){
        facultyBST->printTree();
    }
    else{
        cout << "There are no faculty" << endl;
    }
}


Student* Simulation::findStudent(int idNum)
{
    return studentBST->search(idNum);
}
Faculty* Simulation::findFaculty(int idNum)
{
    return facultyBST->search(idNum);
}
void Simulation::printStudentsAdvisor(int studID)
{
    facultyBST->search(studentBST->search(studID)->getAdvisorID())->getInfo();
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
    cin.clear();
    cin.ignore();
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
        Student *s = new Student(studName, idNum, levelF, maj, gradepoint, advisor);
        studentBST->insert(s->getID(), s);
        facultyBST->search(advisor)->addStudent(idNum);
    }
}
void Simulation::deleteStudent(int studID)
{
    if(findStudent(studID) == NULL)
        cout << "That student ID does not exist\n";
    else
        removeAdvisee(studID, studentBST->search(studID)->getAdvisorID());
        studentBST->deleteNode(studID);
}
void Simulation::addFaculty()
{
    string facName;
    int idNum;
    string levelF;
    string depart;
    cin.clear();
    cin.ignore();
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
        //need to change all the students advisor away from this faculty
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
void exitProgram()
{

}

// // Serialize()
// {
//
// }
