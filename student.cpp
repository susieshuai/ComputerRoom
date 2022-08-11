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

    // computer room info
    ifstream ifs;
    ifs.open(COMPUTER_FILE, ios::in);

    ComputerRoom cr;
    while (ifs >> cr.compId && ifs >> cr.capacity)
    {
        vComp.push_back(cr);
    }

    ifs.close();
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
    cout << "Computer Room is open on Monday to Friday." << endl;
    cout << "Choose Date:" << endl;
    cout << "1. Monday" << endl;
    cout << "2. Tuesday" << endl;
    cout << "3. Wednesday" << endl;
    cout << "4. Thursday" << endl;
    cout << "5. Friday" << endl;

    int date = 0;
    int interval = 0;
    int room = 0;

    while (true)
    {
        cin >> date;
        if (date >= 1 && date <= 5)
        {
            break;
        }
        else
        {
            cout << "Illegal date, please input again." << endl;
        }
    }

    cout << "Choose interval:" << endl;
    cout << "1. AM" << endl;
    cout << "2. PM" << endl;

    while (true)
    {
        cin >> interval;
        if (interval >= 1 && interval <= 2)
        {
            break;
        }
        else
        {
            cout << "Illegal date, please input again." << endl;
        }
    }

    cout << "Choose computer room:" << endl;
    for (int i = 0; i < vComp.size(); i++)
    {
        cout << "#" << vComp[i].compId << " room : " << vComp[i].capacity << " seats" << endl;
    }

    while (true)
    {
        cin >> room;
        if (room >= 1 && room <= 3)
        {
            break;
        }
        else
        {
            cout << "Illegal date, please input again." << endl;
        }
    }

    cout << "Application submitted, waiting for approval." << endl;

    // write order file
    ofstream ofs;
    ofs.open(ORDER_FILE, ios::in);

    ofs << "date:" << date << " "
        << "interval:" << interval << " "
        << "stuId:" << this->stuId << " "
        << "stuName:" << this->name << " "
        << "roomId:" << room << " "
        << "status:" << 1 << endl;

    ofs.close();
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