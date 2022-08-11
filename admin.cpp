#include "admin.h"

// constructor with no arg
Admin::Admin() {}

// constructor with arg
Admin::Admin(string name, string pwd)
{
    this->name = name;
    this->pwd = pwd;

    this->initVector();

    // computer room info
    ifstream ifs;
    ifs.open(COMPUTER_FILE, ios::in);

    ComputerRoom cr;
    while (ifs >> cr.compId && ifs >> cr.capacity)
    {
        vComp.push_back(cr);
    }

    ifs.close();

    // cout << "Computer Room: " << vComp.size() << endl;
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
    string errorMsg;

    ofstream ofs;

    int select = 0;
    cin >> select;

    if (select == 1)
    {
        // add a student
        fileName = STUDENT_FILE;
        notice = "Student ID:";
        errorMsg = "Student ID cannot be the same, please input again.";
    }
    else
    {
        // add a teacher
        fileName = TEACHER_FILE;
        notice = "Teacher ID:";
        errorMsg = "Teacher ID cannot be the same, please input again.";
    }

    ofs.open(fileName, ios::out | ios::app);

    int id;
    string name;
    string pwd;

    while (true)
    {
        cout << notice << endl;
        cin >> id;
        bool dup = this->checkDuplicate(id, select);

        if (dup)
        {
            cout << errorMsg << endl;
        }
        else
        {
            break;
        }
    }

    cout << "Name:" << endl;
    cin >> name;

    cout << "Password:" << endl;
    cin >> pwd;

    // write file
    ofs << id << " " << name << " " << pwd << " " << endl;
    cout << "Added a new person!" << endl;

    ofs.close();

    // init containers after adding a new person
    // avoid adding person with duplicate id
    this->initVector();
}

void printStudent(Student &student)
{
    cout << "ID: " << student.stuId << "\tName: " << student.name << "\tPassword: " << student.pwd << endl;
}

void printTeacher(Teacher &teacher)
{
    cout << "ID: " << teacher.empId << "\tName: " << teacher.name << "\tPassword: " << teacher.pwd << endl;
}

// view users
void Admin::showPerson()
{
    cout << "Show information of:" << endl;
    cout << "1. Student" << endl;
    cout << "2. Teacher" << endl;

    int select = 0;
    cin >> select;

    if (select == 1)
    {
        for_each(vStu.begin(), vStu.end(), printStudent);
    }
    else
    {
        for_each(vTea.begin(), vTea.end(), printTeacher);
    }
}

// view computer room info
void Admin::showComputer()
{
    for (vector<ComputerRoom>::iterator it = this->vComp.begin(); it != this->vComp.end(); it++)
    {
        cout << "ID: " << it->compId << "\tCapacity: " << it->capacity << endl;
    }
}

// clear reservation record
void Admin::cleanFile() {}

// init containers
void Admin::initVector()
{
    // clear container
    vStu.clear();
    vTea.clear();

    // read student file
    ifstream ifs;
    ifs.open(STUDENT_FILE, ios::in);

    if (!ifs.is_open())
    {
        cout << "Fail to load file" << endl;
        return;
    }

    Student student;
    while (ifs >> student.stuId && ifs >> student.name && ifs >> student.pwd)
    {
        vStu.push_back(student);
    }

    // cout << "Students number: " << vStu.size() << endl;
    ifs.close();

    // read teacher file
    ifs.open(TEACHER_FILE, ios::in);

    if (!ifs.is_open())
    {
        cout << "Fail to load file" << endl;
        return;
    }

    Teacher teacher;
    while (ifs >> teacher.empId && ifs >> teacher.name && ifs >> teacher.pwd)
    {
        vTea.push_back(teacher);
    }

    // cout << "Teachers number: " << vTea.size() << endl;
    ifs.close();
}

// check duplicate
bool Admin::checkDuplicate(int id, int identityType)
{
    if (identityType == 1)
    {
        for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
        {
            if (id == it->stuId)
            {
                return true;
            }
        }
    }
    else
    {
        for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
        {
            if (id == it->empId)
            {
                return true;
            }
        }
    }

    return false;
}