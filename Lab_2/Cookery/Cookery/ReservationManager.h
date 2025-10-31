#pragma once
#include "IReservation.h"
#include <iostream>
using namespace std;

class ReservationManager {
public:
    void confirm(IReservation& r) const;
    void cancel(IReservation& r) const;
};

