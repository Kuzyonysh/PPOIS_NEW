#include "Medication.h"

Medication::Medication(string n, string d, string f, string start, string end, string nte)
    : name(n), dose(d), frequency(f), startDate(start), endDate(end), note(nte) {}

string Medication::getName() const { return name; }
string Medication::getDose() const { return dose; }
string Medication::getFrequency() const { return frequency; }
string Medication::getStartDate() const { return startDate; }
string Medication::getEndDate() const { return endDate; }
string Medication::getNote() const { return note; }

void Medication::setDose(const string& d) { dose = d; }
void Medication::setFrequency(const string& f) { frequency = f; }
void Medication::setStartDate(const string& s) { startDate = s; }
void Medication::setEndDate(const string& e) { endDate = e; }
void Medication::setNote(const string& n) { note = n; }
