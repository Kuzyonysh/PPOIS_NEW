#include "ReservationManager.h"
#include "Customer.h"

void ReservationManager::confirm(IReservation& r) const {
    r.setConfirmed(true);
    cout << "Reservation for " << r.getCustomer().getName()
        << " on " << r.getDate()
        << " at table " << r.getTableNumber()
        << " has been confirmed." << endl;
}

void ReservationManager::cancel(IReservation& r) const {
    r.setConfirmed(false);
    cout << "Reservation for " << r.getCustomer().getName()
        << " on " << r.getDate()
        << " has been canceled." << endl;
}
