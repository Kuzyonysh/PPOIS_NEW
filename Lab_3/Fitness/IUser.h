#pragma once
#include <string>
using namespace std;

class IUser {
public:
    virtual ~IUser() = default;
    virtual string getName() const = 0;
    virtual int getAge() const = 0;
    virtual double getWeight() const = 0;
    virtual double getHeight() const = 0;
    virtual string getGender() const = 0;
    virtual int getActivity() const = 0;
};
