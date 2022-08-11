#pragma once
#include <iostream>
using namespace std;
#include "globalFile.h"
#include <fstream>
#include <map>
#include <string>

class OrderFile
{
public:
    // constructor
    OrderFile();

    // update order
    void updateOrder();

    // order number
    int size;

    // order container
    // key: no.
    // value: order info
    map<int, map<string, string>> orderData;
};