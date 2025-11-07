#pragma once
#include <string>
using namespace std;

class Equipment {
private:
    string name;
    string type;
    bool isAvailable;

public:
    Equipment(const string& n, const string& t, bool avail = true);

    void setAvailability(bool avail);

    string getName() const;
    string getType() const;
    bool getAvailability() const;
};
