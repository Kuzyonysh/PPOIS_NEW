#pragma once
#include "ITimer.h"

class Timer : public ITimer {
private:
    int elapsedTime;
    bool isRunning;
    int limit;
    string name;

public:
    Timer(string n = "Default Timer", bool running = false, int time = 0, int lim = 60);

    void setRunning(bool state) override;
    bool running() const override;
    void setElapsedTime(int time) override;
    int getElapsedTime() const override;

    void setLimit(int lim);
    int getLimit() const;

    void setName(const string& n);
    string getName() const;

    bool isOverLimit() const;
};
