#pragma once
#include <string>
#include "Exception.h"
using namespace std;

class MoodRecord {
private:
    string date;
    int mood;
    int stressLevel;
    string note;

public:
    MoodRecord(string d, int m, int s, string n = "");

    string getDate() const;
    int getMood() const;
    int getStressLevel() const;
    string getNote() const;

    void setMood(int m);
    void setStress(int s);
    void setNote(const string& n);
};

