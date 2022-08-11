#include "admin.h"

// constructor with no arg
Admin::Admin() {}

// constructor with arg
Admin::Admin(string name, string pwd)
{
    this->name = name;
    this->pwd = pwd;
}

// operMenu
void Admin::operMenu()
{
    cout << "Hello, [Admin] " << this->name << " !" << endl;
    cout << "\t\t ---------------------------------\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          1.Add User            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          2.Show Users          |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          3.Show Computers      |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          4.Clean Orders        |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          0.Log Out             |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t ---------------------------------\n";
    cout << "Please select:" << endl;
}

// add user
void Admin::addPerson()
{
    cout << "Please select a person you want to add:" << endl;
    cout << "1. Student" << endl;
    cout << "2. Teacher" << endl;

    string fileName;
    string notice;

    ofstream ofs;

    int select = 0;
    cin >> select;

    if (select == 1)
    {
        // add a student
        fileName = STUDENT_FILE;
        notice = "Student ID:";
    }
    else
    {
        // add a teacher
        fileName = TEACHER_FILE;
        notice = "Teacher ID:";
    }

    ofs.open(fileName, ios::out | ios::app);

    int id;
    string name;
    string pwd;

    cout << notice << endl;
    cin >> id;

    cout << "Name:" << endl;
    cin >> name;

    cout << "Password:" << endl;
    cin >> pwd;

    // write file
    ofs << id << " " << name << " " << pwd << " " << endl;
    cout << "Added a new person!" << endl;

    ofs.close();
}

// view users
void Admin::showPerson() {}

// view computer room info
void Admin::showComputer() {}

// clear reservation record
void Admin::cleanFile() {}