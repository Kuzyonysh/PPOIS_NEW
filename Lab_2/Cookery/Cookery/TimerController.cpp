#include "TimerController.h"

TimerController::TimerController(ITimer& t) : timer(t) {}

void TimerController::start() {
    if (!timer.running()) {
        timer.setRunning(true);
        cout << "Timer started" << endl;
    }
    else {
        cout << "Timer is already running" << endl;
    }
}

void TimerController::pause() {
    if (timer.running()) {
        timer.setRunning(false);
        cout << "Timer paused at " << timer.getElapsedTime() << " min" << endl;
    }
    else {
        cout << "Timer isn't running" << endl;
    }
}

void TimerController::stop() {
    timer.setRunning(false);
    cout << "Timer stopped. Total time: " << timer.getElapsedTime() << " min" << endl;
    timer.setElapsedTime(0);
}

void TimerController::addMinutes(int minutes) {
    if (minutes > 0)
        timer.setElapsedTime(timer.getElapsedTime() + minutes);
}

void TimerController::reset() {
    timer.setElapsedTime(0);
    timer.setRunning(false);
    cout << "Timer reset" << endl;
}

void TimerController::fastForward(int minutes) {
    timer.setElapsedTime(timer.getElapsedTime() + minutes);
    cout << "Fast-forwarded by " << minutes << " min" << endl;
}

void TimerController::checkStatus() const {
    cout << "Status: " << (timer.running() ? "Running" : "Paused")
        << ", elapsed " << timer.getElapsedTime() << " min" << endl;
}
