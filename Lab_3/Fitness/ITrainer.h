#pragma once
#include <string>
using namespace std;

class ITrainer {
public:
    virtual ~ITrainer() = default;

    virtual string getName() const = 0;
    virtual string getSpecialization() const = 0;
    virtual int getExperience() const = 0;
    virtual double getSalary() const = 0;
    virtual bool getAvailability() const = 0;
    virtual string getContact() const = 0;
    virtual int getAge() const = 0;
    virtual double getRating() const = 0;
    virtual int getClientsCount() const = 0;
    virtual string getGender() const = 0;

    virtual void setSalary(double s) = 0;
    virtual void setAvailability(bool val) = 0;
    virtual void setContact(const string& c) = 0;
};
