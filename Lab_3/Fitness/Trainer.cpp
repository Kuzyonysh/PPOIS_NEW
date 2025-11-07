#include "Trainer.h"

Trainer::Trainer(const string& n, const string& spec, int exp, double sal,
    bool available, const string& contact,
    int a, double r, int clients, const string& g)
    : name(n), specialization(spec), experienceYears(exp),
    salary(sal), isAvailable(available), contactInfo(contact),
    age(a), rating(r), clientsCount(clients), gender(g) {}

string Trainer::getName() const { return name; }
string Trainer::getSpecialization() const { return specialization; }
int Trainer::getExperience() const { return experienceYears; }
double Trainer::getSalary() const { return salary; }
bool Trainer::getAvailability() const { return isAvailable; }
string Trainer::getContact() const { return contactInfo; }

int Trainer::getAge() const { return age; }
double Trainer::getRating() const { return rating; }
int Trainer::getClientsCount() const { return clientsCount; }
string Trainer::getGender() const { return gender; }

void Trainer::setSalary(double s) { salary = s; }
void Trainer::setAvailability(bool val) { isAvailable = val; }
void Trainer::setContact(const string& c) { contactInfo = c; }
