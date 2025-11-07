#pragma once
#include "ITrainer.h"

class Trainer : public ITrainer {
private:
    string name;
    string specialization;
    int experienceYears;
    double salary;
    bool isAvailable;
    string contactInfo;

    int age;
    double rating;
    int clientsCount;
    string gender;

public:
    Trainer(const string& n, const string& spec, int exp, double sal,
        bool available = true, const string& contact = "not provided",
        int a = 30, double r = 4.5, int clients = 0, const string& g = "unspecified");

    string getName() const override;
    string getSpecialization() const override;
    int getExperience() const override;
    double getSalary() const override;
    bool getAvailability() const override;
    string getContact() const override;

    int getAge() const override;
    double getRating() const override;
    int getClientsCount() const override;
    string getGender() const override;

    void setSalary(double s) override;
    void setAvailability(bool val) override;
    void setContact(const string& c) override;
};
