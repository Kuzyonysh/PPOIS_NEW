#include "Reservation.h"

Reservation::Reservation(const Customer& c, const string& d, int t, int guests, const string& request)
    : customer(c), date(d), tableNumber(t), confirmed(false), numberOfGuests(guests), specialRequest(request),
    occasion(""), notes(""), depositAmount(0), contactPhone(""), email(""), vip(false) {}

Customer Reservation::getCustomer() const { return customer; }
string Reservation::getDate() const { return date; }
int Reservation::getTableNumber() const { return tableNumber; }
bool Reservation::isConfirmed() const { return confirmed; }
void Reservation::setConfirmed(bool c) { confirmed = c; }

void Reservation::setSpecialRequest(const string& req) { specialRequest = req; }
void Reservation::setNumberOfGuests(int n) { numberOfGuests = n; }
string Reservation::getSpecialRequest() const { return specialRequest; }
int Reservation::getNumberOfGuests() const { return numberOfGuests; }

void Reservation::setOccasion(const string& o) { occasion = o; }
void Reservation::setNotes(const string& n) { notes = n; }
void Reservation::setDepositAmount(double d) { depositAmount = d; }
void Reservation::setContactPhone(const string& p) { contactPhone = p; }
void Reservation::setEmail(const string& e) { email = e; }
void Reservation::setVIP(bool v) { vip = v; }

string Reservation::getOccasion() const { return occasion; }
string Reservation::getNotes() const { return notes; }
double Reservation::getDepositAmount() const { return depositAmount; }
string Reservation::getContactPhone() const { return contactPhone; }
string Reservation::getEmail() const { return email; }
bool Reservation::isVIP() const { return vip; }
