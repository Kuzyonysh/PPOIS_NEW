#include "PrinterAppointment.h"

PrinterAppointment::PrinterAppointment(const AppointmentManager& m) : manager(m) {}

void PrinterAppointment::print(const Appointment& a) const {
    cout << a.getDate() << " " << a.getTime() << " with Dr. " << a.getDoctor()
        << " at " << a.getLocation() << ", Reason: " << a.getReason();
    if (a.isAttended()) cout << " (attended)";
    cout << endl;
}
