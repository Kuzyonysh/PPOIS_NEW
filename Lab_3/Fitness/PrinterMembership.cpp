#include "PrinterMembership.h"

void PrinterMembership::print(const Membership& m) const {
    cout << "Membership Info" << endl;
    cout << "Type: " << m.getType() << endl;
    cout << "Start: " << m.getStartDate() << endl;
    cout << "End: " << m.getEndDate() << endl;
    cout << "Status: " << (m.getActive() ? "Active" : "Inactive") << endl;
    cout << "Payment: " << (m.getPaid() ? "Paid" : "Unpaid") << endl;
}
