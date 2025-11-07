#include "Exception.h"

// Base Exception
Exception::Exception(string msg) : message(msg) {}
const char* Exception::what() const noexcept { return message.c_str(); }

// Специализированные исключения
InvalidHeightWeightException::InvalidHeightWeightException(string msg)
    : Exception("Invalid height or weight: " + msg) {}

NoActivityDataException::NoActivityDataException()
    : Exception("No activity data available for analysis") {}

InvalidIngredientAmountException::InvalidIngredientAmountException()
    : Exception("Wrong value") {}

InvalidIngredientAmountException::InvalidIngredientAmountException(const string& msg)
    : Exception(msg) {}

InvalidWaterAmountException::InvalidWaterAmountException(string msg)
    : Exception("Invalid amount" + msg) {}

EmptyDataAboutDream::EmptyDataAboutDream(string msg)
    : Exception("Error" + msg) {}

InvalidBodyMetricsException::InvalidBodyMetricsException(string msg)
    : Exception("Error" + msg) {}

MentalHealthException::MentalHealthException(string msg)
    : Exception("Mental health error: " + msg) {}

MedicationException::MedicationException(string msg)
    : Exception("Medication error: " + msg) {}

GoalException::GoalException(string msg)
    : Exception("Goal error: " + msg) {}

AppointmentException::AppointmentException(string msg)
    : Exception("Appointment error: " + msg) {}

WorkoutException::WorkoutException(string msg)
    : Exception("Workout error: " + msg) {}

MembershipException::MembershipException(const string& msg)
    : Exception("Membership error: " + msg) {}
