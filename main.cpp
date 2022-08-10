#include <iostream>
using namespace std;

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
            /* code */
            break;

        // teacher
        case 2:
            /* code */
            break;

        // admin
        case 3:
            /* code */
            break;

        // exit
        case 0:
            /* code */
            break;

        // illegal arg
        default:
            cout << "Illegal input, please select again." << endl;
            break;
        }
    }

    return 0;
}