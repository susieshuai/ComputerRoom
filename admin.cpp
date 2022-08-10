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
void Admin::addPerson() {}

// view users
void Admin::showPerson() {}

// view computer room info
void Admin::showComputer() {}

// clear reservation record
void Admin::cleanFile() {}