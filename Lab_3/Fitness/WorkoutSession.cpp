#include "WorkoutSession.h"

WorkoutSession::WorkoutSession(string t, double d, double c, string dt, string i,
    string loc, string trainer,
    string n, int hr, int s, double dist, bool comp)
    : type(t), duration(d), caloriesBurned(c), date(dt), intensity(i),
    location(loc), trainerName(trainer), notes(n), avgHeartRate(hr),
    steps(s), distance(dist), completed(comp)
{
    if (d <= 0) throw WorkoutException("Duration must be positive");
    if (c < 0) throw WorkoutException("Calories burned cannot be negative");
    if (hr < 0) throw WorkoutException("Heart rate cannot be negative");
    if (dist < 0) throw WorkoutException("Distance cannot be negative");
}

string WorkoutSession::getType() const { return type; }
string WorkoutSession::getDate() const { return date; }
string WorkoutSession::getIntensity() const { return intensity; }
double WorkoutSession::getDuration() const { return duration; }
double WorkoutSession::getCalories() const { return caloriesBurned; }
string WorkoutSession::getLocation() const { return location; }
string WorkoutSession::getTrainerName() const { return trainerName; }
string WorkoutSession::getNotes() const { return notes; }
int WorkoutSession::getHeartRate() const { return avgHeartRate; }
int WorkoutSession::getSteps() const { return steps; }
double WorkoutSession::getDistance() const { return distance; }
bool WorkoutSession::isCompleted() const { return completed; }

void WorkoutSession::setNotes(const string& n) { notes = n; }
void WorkoutSession::setCompleted(bool c) { completed = c; }
void WorkoutSession::setHeartRate(int hr) {
    if (hr < 0) throw WorkoutException("Heart rate cannot be negative");
    avgHeartRate = hr;
}
void WorkoutSession::setSteps(int s) { steps = s; }
void WorkoutSession::setDistance(double d) { distance = d; }
void WorkoutSession::setTrainerName(const string& t) { trainerName = t; }
