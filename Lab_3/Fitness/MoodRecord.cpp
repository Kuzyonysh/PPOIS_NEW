#include "MoodRecord.h"

MoodRecord::MoodRecord(string d, int m, int s, string n)
    : date(d), mood(m), stressLevel(s), note(n) {
    if (m < 1 || m > 10 || s < 1 || s > 10)
        throw MentalHealthException("Mood or stress out of range (1-10)");
}

string MoodRecord::getDate() const { return date; }
int MoodRecord::getMood() const { return mood; }
int MoodRecord::getStressLevel() const { return stressLevel; }
string MoodRecord::getNote() const { return note; }

void MoodRecord::setMood(int m) {
    if (m < 1 || m > 10) throw MentalHealthException("Mood must be 1-10");
    mood = m;
}

void MoodRecord::setStress(int s) {
    if (s < 1 || s > 10) throw MentalHealthException("Stress must be 1-10");
    stressLevel = s;
}

void MoodRecord::setNote(const string& n) { note = n; }
