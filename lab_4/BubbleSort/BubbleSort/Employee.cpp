#include "Employee.h"

Employee::Employee(string n, double s) : name(n), salary(s) {}

string Employee::getName() const { return name; }
double Employee::getSalary() const { return salary; }

void Employee::setName(const string& newName) { name = newName; }
void Employee::setSalary(double newSalary) { salary = newSalary; }

void Employee::print() const {
    cout << name << " (" << salary << " BYN)" << endl;
}

bool compareBySalary(const Employee& a, const Employee& b) {
    return a.getSalary() < b.getSalary();
}

bool compareByName(const Employee& a, const Employee& b) {
    return a.getName() < b.getName();
}
