#pragma once
#include <iostream>
using namespace std;

// base class: Identity
class Identity
{
public:
    // operation menu
    virtual void operMenu() = 0;

    string name;
    string pwd; // password
};