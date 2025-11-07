#pragma once
#include <string>
using namespace std;

class Membership {
private:
    string memberName;
    string type;
    double price;
    string startDate;
    string endDate;
    bool isActive;
    bool isPaid;

public:
    Membership(string name, string t, double p, string start, string end, bool paid);

    void deactivate();
    void renew(string newEndDate);
    void markPaid();

    string getType() const;
    string getStartDate() const;
    string getEndDate() const;
    bool getActive() const;
    bool getPaid() const;
};

