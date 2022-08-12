#include "teacher.h"

// constructor with no arg
Teacher::Teacher() {}

// constructor with arg
Teacher::Teacher(int empId, string name, string pwd)
{
    this->empId = empId;
    this->name = name;
    this->pwd = pwd;
}

// operMenu
void Teacher::operMenu()
{
    cout << "Hello, [Teacher] " << this->name << " !" << endl;
    cout << "\t\t ---------------------------------\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          1.Show All Order      |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          2.Verify Order        |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          0.Log Out             |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t ---------------------------------\n";
    cout << "Please select:" << endl;
}

// view all reservation
void Teacher::showAllOrder() {}

// confirm reservation
void Teacher::validOrder() {}