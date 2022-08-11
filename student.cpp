#include "student.h"

// constructor with no arg
Student::Student()
{
}

// constructor with arg
Student::Student(int id, string name, string pwd)
{
    this->stuId = id;
    this->name = name;
    this->pwd = pwd;
}

// operMenu
void Student::operMenu()
{
    cout << "Hello, [Student] " << this->name << " !" << endl;
    cout << "\t\t ---------------------------------\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          1.Apply Order         |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          2.Show My Order       |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          3.Show All Order      |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          4.Cancel Order        |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          0.Log Out             |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t ---------------------------------\n";
    cout << "Please select:" << endl;
}

// make reservation
void Student::applyOrder()
{
}

// view my reservation
void Student::showMyOrder()
{
}

// view all reservation
void Student::showAllOrder()
{
}

// cancel reservation
void Student::cancelOrder()
{
}