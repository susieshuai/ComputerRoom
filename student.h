#pragma once
#include <iostream>
using namespace std;
#include "identity.h"

class Student : public Identity
{
public:
    // constructor with no arg
    Student();

    // constructor with arg
    Student(int stuId, string name, string pwd);

    // operMenu
    virtual void operMenu();

    // make reservation
    void applyOrder();

    // view my reservation
    void showMyOrder();

    // view all reservation
    void showAllOrder();

    // cancel reservation
    void cancelOrder();

    // student id
    int stuId;
};