#include "Timer.h"

Timer::Timer(string n, bool running, int time, int lim)
    : name(n), isRunning(running), elapsedTime(time), limit(lim) {}

void Timer::setRunning(bool state) { isRunning = state; }
bool Timer::running() const { return isRunning; }
void Timer::setElapsedTime(int time) { elapsedTime = time; }
int Timer::getElapsedTime() const { return elapsedTime; }

void Timer::setLimit(int lim) { limit = lim; }
int Timer::getLimit() const { return limit; }

void Timer::setName(const string& n) { name = n; }
string Timer::getName() const { return name; }

bool Timer::isOverLimit() const { return elapsedTime >= limit; }
