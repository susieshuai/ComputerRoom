#include "orderFile.h"

void splitOrderInfo(string &data, map<string, string> &map)
{
    int pos = data.find(":");
    if (pos != -1)
    {
        string key = data.substr(0, pos);
        string value = data.substr(pos + 1, data.size() - pos - 1);

        map.insert(make_pair(key, value));
    }
}

// constructor
OrderFile::OrderFile()
{
    ifstream ifs;
    ifs.open(ORDER_FILE, ios::in);

    string date;
    string interval;
    string stuId;
    string stuName;
    string roomId;
    string status;

    this->size = 0; // init order number

    while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status)
    {
        // a temp map for each line
        map<string, string> map;

        splitOrderInfo(date, map);
        splitOrderInfo(interval, map);
        splitOrderInfo(stuId, map);
        splitOrderInfo(stuName, map);
        splitOrderInfo(roomId, map);
        splitOrderInfo(status, map);

        // cout << "date:" << map["date"] << endl;
        // cout << "interval:" << map["interval"] << endl;
        // cout << "stuId:" << map["stuId"] << endl;
        // cout << "stuName:" << map["stuName"] << endl;
        // cout << "roomId:" << map["roomId"] << endl;
        // cout << "status:" << map["status"] << endl;

        // cout << map.size() << endl;

        // insert temp map to orderData map
        this->orderData.insert(make_pair(this->size, map));
        this->size++;
    }

    ifs.close();

    // cout << this->orderData.size() << endl;
}

// update order
void OrderFile::updateOrder()
{
    if (this->size == 0)
    {
        return;
    }

    ofstream ofs;
    ofs.open(ORDER_FILE, ios::trunc);

    // overwrite
    for (int i = 0; i < this->size; i++)
    {
        ofs << "date:" << this->orderData[i]["date"] << " "
            << "interval:" << this->orderData[i]["interval"] << " "
            << "stuId:" << this->orderData[i]["stuId"] << " "
            << "stuName:" << this->orderData[i]["stuName"] << " "
            << "roomId:" << this->orderData[i]["roomId"] << " "
            << "status:" << this->orderData[i]["status"] << " "
            << endl;
    }

    ofs.close();
}