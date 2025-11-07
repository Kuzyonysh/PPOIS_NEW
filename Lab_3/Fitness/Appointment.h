#pragma once
#include <string>
using namespace std;

class Appointment {
private:
    string date;
    string time;
    string doctor;
    string location;
    string reason;
    bool attended;

public:
    Appointment(string d, string t, string doc, string loc, string r);

    string getDate() const;
    string getTime() const;
    string getDoctor() const;
    string getLocation() const;
    string getReason() const;
    bool isAttended() const;

    void markAttended();
};

