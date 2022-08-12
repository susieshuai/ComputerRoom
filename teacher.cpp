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
void Teacher::showAllOrder()
{
    OrderFile of;

    if (of.size == 0)
    {
        cout << "No data" << endl;
        return;
    }

    string dates[] = {"placeholer", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

    for (int i = 0; i < of.size; i++)
    {

        string status;
        if (of.orderData[i]["status"] == "-1")
        {
            status = "Rejected";
        }
        else if (of.orderData[i]["status"] == "0")
        {
            status = "Canceled";
        }
        else if (of.orderData[i]["status"] == "1")
        {
            status = "Submitted";
        }
        else
        {
            status = "Approved";
        }

        cout << i + 1 << ". "
             << "\tDate: " << dates[atoi(of.orderData[i]["date"].c_str())]
             << "\tInterval: " << (of.orderData[i]["interval"] == "1" ? "AM" : "PM")
             << "\tID: " << of.orderData[i]["stuId"]
             << "\tName: " << of.orderData[i]["stuName"]
             << "\tRoom: " << of.orderData[i]["roomId"]
             << "\tStatus: " << status << endl;
    }
}

// confirm reservation
void Teacher::validOrder() {}