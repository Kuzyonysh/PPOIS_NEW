#include "AppointmentManager.h"

void AppointmentManager::addAppointment(const Appointment& app) {
    for (const auto& a : appointments) {
        if (a.getDate() == app.getDate() && a.getTime() == app.getTime())
            throw AppointmentException("Appointment already exists at this date and time");
    }
    appointments.push_back(app);
}

vector<Appointment> AppointmentManager::getAppointmentsByDoctor(const string& doc) const {
    vector<Appointment> result;
    for (auto& a : appointments)
        if (a.getDoctor() == doc) result.push_back(a);
    return result;
}

void AppointmentManager::cancelAppointment(const string& date, const string& time) {
    auto it = remove_if(appointments.begin(), appointments.end(),
        [&](const Appointment& a) { return a.getDate() == date && a.getTime() == time; });
    if (it == appointments.end()) {
        throw AppointmentException("No appointment found to cancel on " + date + " at " + time);
    }
    appointments.erase(it, appointments.end());
}

Appointment AppointmentManager::getAppointment(const string& date, const string& time) const {
    for (const auto& a : appointments) {
        if (a.getDate() == date && a.getTime() == time)
            return a;
    }
    throw AppointmentException("No appointment found on " + date + " at " + time);
}

int AppointmentManager::getTotalAppointments() const {
    return appointments.size();
}

vector<Appointment> AppointmentManager::getAppointmentsByDate(const string& date) const {
    vector<Appointment> result;
    for (const auto& a : appointments) {
        if (a.getDate() == date)
            result.push_back(a);
    }
    return result;
}

void AppointmentManager::markAppointmentAttended(const string& date, const string& time) {
    for (auto& a : appointments) {
        if (a.getDate() == date && a.getTime() == time) {
            a.markAttended();
            return;
        }
    }
    throw AppointmentException("No appointment found on " + date + " at " + time);
}
