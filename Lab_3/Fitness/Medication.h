#pragma once
#include <string>
using namespace std;

class Medication {
private:
    string name;
    string dose;
    string frequency;
    string startDate;
    string endDate;
    string note;

public:
    Medication(string n, string d, string f, string start, string end, string note = "");

    string getName() const;
    string getDose() const;
    string getFrequency() const;
    string getStartDate() const;
    string getEndDate() const;
    string getNote() const;

    void setDose(const string& d);
    void setFrequency(const string& f);
    void setStartDate(const string& s);
    void setEndDate(const string& e);
    void setNote(const string& n);
};
