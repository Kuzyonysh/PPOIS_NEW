#pragma once
#include "IUser.h"

class User : public IUser {
private:
    string name;
    int age;
    double weight;
    double height;
    string gender;
    int activity;
public:
    User(string n, int a, double w, double h, string g, int act);

    string getName() const override;
    int getAge() const override;
    double getWeight() const override;
    double getHeight() const override;
    string getGender() const override;
    int getActivity() const override;

    void setName(string n);
    void setAge(int a);
    void setWeight(double w);
    void setHeight(double h);
    void setGender(string g);
    void setActivity(int act);
};
