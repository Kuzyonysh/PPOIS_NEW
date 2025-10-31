#pragma once
#include <string>
using namespace std;

class ITimer {
public:
    virtual ~ITimer() = default;
    virtual void setRunning(bool state) = 0;
    virtual bool running() const = 0;
    virtual void setElapsedTime(int time) = 0;
    virtual int getElapsedTime() const = 0;
};
