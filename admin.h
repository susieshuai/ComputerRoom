#pragma once
#include <iostream>
using namespace std;
#include "identity.h"

class Admin : public Identity
{
public:
    // constructor with no arg
    Admin();

    // constructor with arg
    Admin(string name, string pwd);

    // operMenu
    virtual void operMenu();

    // add user
    void addPerson();

    // view users
    void showPerson();

    // view computer room info
    void showComputer();

    // clear reservation record
    void cleanFile();
};