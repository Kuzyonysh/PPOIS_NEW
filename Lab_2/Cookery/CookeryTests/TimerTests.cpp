#include "gtest/gtest.h"
#include "D:\Projects\Cookery\Cookery\Timer.h"
#include "D:\Projects\Cookery\Cookery\TimerController.h"
#include "D:\Projects\Cookery\Cookery\ConsoleTimerPrinter.h"
#include <sstream>
#include <iostream>

using namespace std;


TEST(TimerTest, ConstructorSetsValues) {
    Timer timer("My Timer", true, 10, 60);

    EXPECT_EQ(timer.getName(), "My Timer");
    EXPECT_TRUE(timer.running());
    EXPECT_EQ(timer.getElapsedTime(), 10);
    EXPECT_EQ(timer.getLimit(), 60);
    EXPECT_FALSE(timer.isOverLimit());
}

TEST(TimerTest, SetAndGetName) {
    Timer timer;
    timer.setName("Test Timer");
    EXPECT_EQ(timer.getName(), "Test Timer");
}

TEST(TimerTest, SetAndGetElapsedTime) {
    Timer timer;
    timer.setElapsedTime(15);
    EXPECT_EQ(timer.getElapsedTime(), 15);
}

TEST(TimerTest, SetAndGetLimit) {
    Timer timer;
    timer.setLimit(120);
    EXPECT_EQ(timer.getLimit(), 120);
}

TEST(TimerTest, RunningState) {
    Timer timer;
    timer.setRunning(true);
    EXPECT_TRUE(timer.running());
    timer.setRunning(false);
    EXPECT_FALSE(timer.running());
}

TEST(TimerTest, IsOverLimitTrue) {
    Timer timer("T", true, 70, 60);
    EXPECT_TRUE(timer.isOverLimit());
}

TEST(TimerTest, IsOverLimitFalse) {
    Timer timer("T", true, 50, 60);
    EXPECT_FALSE(timer.isOverLimit());
}

TEST(TimerControllerTest, StartTimerWhenPaused) {
    Timer timer("T", false, 10, 60);
    TimerController controller(timer);

    stringstream buffer;
    streambuf* oldCout = cout.rdbuf(buffer.rdbuf());

    controller.start();

    cout.rdbuf(oldCout);
    string output = buffer.str();
    EXPECT_TRUE(timer.running());
    EXPECT_NE(output.find("Timer started"), string::npos);
}

TEST(TimerControllerTest, StartTimerWhenRunning) {
    Timer timer("T", true);
    TimerController controller(timer);

    stringstream buffer;
    streambuf* oldCout = cout.rdbuf(buffer.rdbuf());

    controller.start();

    cout.rdbuf(oldCout);
    string output = buffer.str();
    EXPECT_TRUE(timer.running());
    EXPECT_NE(output.find("Timer is already running"), string::npos);
}

TEST(TimerControllerTest, PauseTimerWhenRunning) {
    Timer timer("T", true, 15);
    TimerController controller(timer);

    stringstream buffer;
    streambuf* oldCout = cout.rdbuf(buffer.rdbuf());

    controller.pause();

    cout.rdbuf(oldCout);
    string output = buffer.str();
    EXPECT_FALSE(timer.running());
    EXPECT_NE(output.find("Timer paused at 15 min"), string::npos);
}

TEST(TimerControllerTest, PauseTimerWhenPaused) {
    Timer timer("T", false);
    TimerController controller(timer);

    stringstream buffer;
    streambuf* oldCout = cout.rdbuf(buffer.rdbuf());

    controller.pause();

    cout.rdbuf(oldCout);
    string output = buffer.str();
    EXPECT_FALSE(timer.running());
    EXPECT_NE(output.find("Timer isn't running"), string::npos);
}

TEST(TimerControllerTest, StopTimerResetsElapsedTime) {
    Timer timer("T", true, 25);
    TimerController controller(timer);

    stringstream buffer;
    streambuf* oldCout = cout.rdbuf(buffer.rdbuf());

    controller.stop();

    cout.rdbuf(oldCout);
    string output = buffer.str();
    EXPECT_FALSE(timer.running());
    EXPECT_EQ(timer.getElapsedTime(), 0);
    EXPECT_NE(output.find("Timer stopped. Total time: 25 min"), string::npos);
}

TEST(TimerControllerTest, AddMinutesIncreasesElapsedTime) {
    Timer timer("T", false, 10);
    TimerController controller(timer);

    controller.addMinutes(5);
    EXPECT_EQ(timer.getElapsedTime(), 15);
}

TEST(TimerControllerTest, ResetTimer) {
    Timer timer("T", true, 20);
    TimerController controller(timer);

    stringstream buffer;
    streambuf* oldCout = cout.rdbuf(buffer.rdbuf());
    controller.reset();
    cout.rdbuf(oldCout);

    EXPECT_FALSE(timer.running());
    EXPECT_EQ(timer.getElapsedTime(), 0);
}

TEST(TimerControllerTest, FastForwardTimer) {
    Timer timer("T", false, 10);
    TimerController controller(timer);

    stringstream buffer;
    streambuf* oldCout = cout.rdbuf(buffer.rdbuf());
    controller.fastForward(5);
    cout.rdbuf(oldCout);

    EXPECT_EQ(timer.getElapsedTime(), 15);
}

TEST(TimerControllerTest, CheckStatusOutputsCorrectly) {
    Timer timer("T", true, 12, 60);
    TimerController controller(timer);

    stringstream buffer;
    streambuf* oldCout = cout.rdbuf(buffer.rdbuf());
    controller.checkStatus();
    cout.rdbuf(oldCout);

    string output = buffer.str();
    EXPECT_NE(output.find("Status: Running, elapsed 12 min"), string::npos);
}

TEST(ConsoleTimerPrinterTest, PrintOutputsCorrectText) {
    Timer timer("Timer1", true, 30, 60);
    ConsoleTimerPrinter printer;

    stringstream buffer;
    streambuf* oldCout = cout.rdbuf(buffer.rdbuf());

    printer.print(timer);

    cout.rdbuf(oldCout);
    string output = buffer.str();
    EXPECT_NE(output.find("Timer Name: Timer1"), string::npos);
    EXPECT_NE(output.find("Status: Running"), string::npos);
    EXPECT_NE(output.find("Elapsed Time: 30 min"), string::npos);
    EXPECT_NE(output.find("Limit: 60 min"), string::npos);
    EXPECT_NE(output.find("Over Limit: No"), string::npos);
}

TEST(TimerTest, ZeroElapsedTimeNotOverLimit) {
    Timer timer("T", false, 0, 60);
    EXPECT_FALSE(timer.isOverLimit());
}

TEST(TimerTest, ElapsedTimeEqualLimitIsOverLimit) {
    Timer timer("T", false, 60, 60);
    EXPECT_TRUE(timer.isOverLimit());
}
