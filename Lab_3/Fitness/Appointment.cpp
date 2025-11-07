#include "Appointment.h"

Appointment::Appointment(string d, string t, string doc, string loc, string r)
    : date(d), time(t), doctor(doc), location(loc), reason(r), attended(false) {}

string Appointment::getDate() const { return date; }
string Appointment::getTime() const { return time; }
string Appointment::getDoctor() const { return doctor; }
string Appointment::getLocation() const { return location; }
string Appointment::getReason() const { return reason; }
bool Appointment::isAttended() const { return attended; }

void Appointment::markAttended() { attended = true; }
