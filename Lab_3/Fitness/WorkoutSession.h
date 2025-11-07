#pragma once
#include <string>
#include "Exception.h" 
using namespace std;

class WorkoutSession {
private:
    string type;
    string date;
    string intensity;
    double duration;
    double caloriesBurned;
    string location;
    string trainerName;
    string notes;
    int avgHeartRate;
    int steps;
    double distance;
    bool completed;

public:
    WorkoutSession(string t, double d, double c, string dt, string i,
        string loc = "Unknown", string trainer = "Self",
        string n = "", int hr = 0, int s = 0, double dist = 0.0, bool comp = true);

    string getType() const;
    string getDate() const;
    string getIntensity() const;
    double getDuration() const;
    double getCalories() const;
    string getLocation() const;
    string getTrainerName() const;
    string getNotes() const;
    int getHeartRate() const;
    int getSteps() const;
    double getDistance() const;
    bool isCompleted() const;

    void setNotes(const string& n);
    void setCompleted(bool c);
    void setHeartRate(int hr);
    void setSteps(int s);
    void setDistance(double d);
    void setTrainerName(const string& t);
};
