#pragma once
#include <iostream>
#include "ITimer.h"
using namespace std;

class TimerController {
private:
    ITimer& timer;

public:
    TimerController(ITimer& t);

    void start();
    void pause();
    void stop();
    void addMinutes(int minutes);
    void reset();
    void fastForward(int minutes);
    void checkStatus() const;
};
