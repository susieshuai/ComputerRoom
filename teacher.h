#pragma once
#include <iostream>
using namespace std;
#include "identity.h"

class Teacher : public Identity
{
public:
    // constructor with no arg
    Teacher();

    // constructor with arg
    Teacher(int empId, string name, string pwd);

    // operMenu
    virtual void operMenu();

    // view all reservation
    void showAllOrder();

    // confirm reservation
    void validOrder();

    // employee id
    int empId;
};