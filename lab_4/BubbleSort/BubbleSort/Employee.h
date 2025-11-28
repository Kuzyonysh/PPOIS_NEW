#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    double salary;
public:
    Employee(string n, double s);

    string getName() const;
    double getSalary() const;

    void setName(const string& newName);
    void setSalary(double newSalary);

    void print() const;
};

bool compareBySalary(const Employee& a, const Employee& b);
bool compareByName(const Employee& a, const Employee& b);

#endif 
