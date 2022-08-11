#include <iostream>
using namespace std;
#include "identity.h"
#include <fstream>
#include <string>
#include "globalFile.h"
#include "student.cpp"
#include "teacher.cpp"
#include "admin.cpp"

// redir to admin sub memu
void adminMenu(Identity *&admin)
{
    while (true)
    {
        // call operation memu
        admin->operMenu();

        // cast to call other funcs
        Admin *ad = (Admin *)admin;

        int select = 0;
        // cout << "Please choose:" << endl;
        cin >> select;

        switch (select)
        {
        case 1:
            ad->addPerson();
            break;

        case 2:
            ad->showPerson();
            break;

        case 3:
            ad->showComputer();
            break;

        case 4:
            ad->cleanFile();
            break;

        default:
            delete admin;
            cout << "Logged out." << endl;
            return;
        }
    }
}

// login
void login(string fileName, int identityType)
{
    Identity *person = NULL;

    // read file
    ifstream ifs;
    ifs.open(fileName, ios::in);

    if (!ifs.is_open())
    {
        cout << "File not exists." << endl;
        ifs.close();
        return;
    }

    // load user info
    int id = 0;
    string name;
    string pwd;

    // identity
    if (identityType == 1)
    {
        cout << "Please input student id:" << endl;
        cin >> id;
    }
    else if (identityType == 2)
    {
        cout << "Please input teacher id:" << endl;
        cin >> id;
    }

    cout << "Please input username:" << endl;
    cin >> name;

    cout << "Please input password:" << endl;
    cin >> pwd;

    // verify
    if (identityType == 1)
    {
        // file info
        int fId;
        string fName;
        string fPwd;

        while (ifs >> fId && ifs >> fName && ifs >> fPwd)
        {
            // compare with user info
            if (fId == id && fName == name && fPwd == pwd)
            {
                cout << "Student identity verified! You are logged in." << endl;
                person = new Student(id, name, pwd);
                // student sub menu
                // TBD
                return;
            }
        }
    }
    else if (identityType == 2)
    {
        // file info
        int fId;
        string fName;
        string fPwd;

        while (ifs >> fId && ifs >> fName && ifs >> fPwd)
        {
            // compare with user info
            if (fId == id && fName == name && fPwd == pwd)
            {
                cout << "Teacher identity verified! You are logged in." << endl;
                person = new Teacher(id, name, pwd);
                // teacher sub memu
                // TBD
                return;
            }
        }
    }
    else if (identityType == 3)
    {
        // file info
        string fName;
        string fPwd;

        while (ifs >> fName && ifs >> fPwd)
        {
            // compare with user info
            if (fName == name && fPwd == pwd)
            {
                cout << "Admin identity verified! You are logged in." << endl;
                person = new Admin(name, pwd);
                // admin sub memu
                adminMenu(person);
                return;
            }
        }
    }

    cout << "Sorry, wrong input." << endl;
    return;
}

int main()
{
    int select = 0; // save user's choice

    while (true)
    {
        cout << "==================  Computer Room Reservation  ================="
             << endl;
        cout << endl
             << "Who are you?" << endl;
        cout << "\t\t -------------------------------\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          1.Student            |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          2.Teacher            |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          3.Admin              |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          0.Exit               |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t -------------------------------\n";
        cout << "Pleas select:";

        cin >> select;

        switch (select)
        {

        // student
        case 1:
            login(STUDENT_FILE, 1);
            break;

        // teacher
        case 2:
            login(TEACHER_FILE, 2);
            break;

        // admin
        case 3:
            login(ADMIN_FILE, 3);
            break;

        // exit
        case 0:
            cout << "Goodbye! See you next time." << endl;
            exit(0);
            break;

        // illegal arg
        default:
            cout << "Illegal input, please select again." << endl;
            break;
        }
    }

    return 0;
}