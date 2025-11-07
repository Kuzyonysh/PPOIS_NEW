#pragma once
#include <iostream>
#include "Printer.h"
#include "Appointment.h"
#include "AppointmentManager.h"
using namespace std;

class PrinterAppointment : public Printer<Appointment> {
private:
    const AppointmentManager& manager;

public:
    PrinterAppointment(const AppointmentManager& m);
    void print(const Appointment& a) const override;
};

