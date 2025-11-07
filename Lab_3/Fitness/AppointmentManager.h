#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include "Appointment.h"
#include "Exception.h" 
using namespace std;

class AppointmentManager {
private:
    vector<Appointment> appointments;

public:
    void addAppointment(const Appointment& app);
    vector<Appointment> getAppointmentsByDoctor(const string& doc) const;
    void cancelAppointment(const string& date, const string& time);
    Appointment getAppointment(const string& date, const string& time) const;
    int getTotalAppointments() const;
    vector<Appointment> getAppointmentsByDate(const string& date) const;
    void markAppointmentAttended(const string& date, const string& time);
};
