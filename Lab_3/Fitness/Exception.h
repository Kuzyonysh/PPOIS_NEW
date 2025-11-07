#pragma once
#include <string>
using namespace std;

class Exception {
protected:
    string message;
public:
    Exception(string msg);
    virtual const char* what() const noexcept;
    virtual ~Exception() = default;
};

// Специализированные исключения
class InvalidHeightWeightException : public Exception {
public:
    InvalidHeightWeightException(string msg);
};

class NoActivityDataException : public Exception {
public:
    NoActivityDataException();
};

class InvalidIngredientAmountException : public Exception {
public:
    InvalidIngredientAmountException();
    InvalidIngredientAmountException(const string& msg);
};

class InvalidWaterAmountException : public Exception {
public:
    InvalidWaterAmountException(string msg);
};

class EmptyDataAboutDream : public Exception {
public:
    EmptyDataAboutDream(string msg);
};

class InvalidBodyMetricsException : public Exception {
public:
    InvalidBodyMetricsException(string msg);
};

class MentalHealthException : public Exception {
public:
    MentalHealthException(string msg);
};

class MedicationException : public Exception {
public:
    MedicationException(string msg);
};

class GoalException : public Exception {
public:
    GoalException(string msg);
};

class AppointmentException : public Exception {
public:
    AppointmentException(string msg);
};

class WorkoutException : public Exception {
public:
    WorkoutException(string msg);
};

class MembershipException : public Exception {
public:
    MembershipException(const string& msg);
};
