#include "gtest/gtest.h"
#include "FitnessTracker.h"

TEST(FitnessTrackerTest, SetAndGetActivityType) {
    FitnessTracker tracker;
    tracker.setActivityType("Running");
    EXPECT_EQ(tracker.getActivityType(), "Running");
}

TEST(FitnessTrackerTest, SetAndGetActivityDate) {
    FitnessTracker tracker;
    tracker.setActivityDate("2025-11-07");
    EXPECT_EQ(tracker.getActivityDate(), "2025-11-07");
}

TEST(FitnessTrackerTest, SetAndGetActivityDuration) {
    FitnessTracker tracker;
    tracker.setActivityDuration(45.5);
    EXPECT_DOUBLE_EQ(tracker.getActivityDuration(), 45.5);
}

TEST(FitnessTrackerTest, SetAndGetActivityCalories) {
    FitnessTracker tracker;
    tracker.setActivityCalories(300.0);
    EXPECT_DOUBLE_EQ(tracker.getActivityCalories(), 300.0);
}

TEST(FitnessTrackerTest, AddSingleActivity) {
    FitnessTracker tracker;
    tracker.addActivity("Running", "2025-11-07", 30, 250);
    EXPECT_EQ(tracker.getActivityType(), "Running");
    EXPECT_EQ(tracker.getActivityDate(), "2025-11-07");
    EXPECT_DOUBLE_EQ(tracker.getActivityDuration(), 30);
    EXPECT_DOUBLE_EQ(tracker.getActivityCalories(), 250);
}

TEST(FitnessTrackerTest, TotalCaloriesBurnedIncreases) {
    FitnessTracker tracker;
    tracker.addActivity("Running", "2025-11-07", 30, 250);
    tracker.addActivity("Cycling", "2025-11-08", 60, 400);
    EXPECT_DOUBLE_EQ(tracker.getTotalCaloriesBurned(), 650);
}

TEST(FitnessTrackerTest, StoresAllActivityTypes) {
    FitnessTracker tracker;
    tracker.addActivity("Run", "2025-11-07", 30, 200);
    tracker.addActivity("Swim", "2025-11-08", 40, 300);
    auto types = tracker.getAllTypes();
    ASSERT_EQ(types.size(), 2);
    EXPECT_EQ(types[0], "Run");
    EXPECT_EQ(types[1], "Swim");
}

TEST(FitnessTrackerTest, StoresAllDates) {
    FitnessTracker tracker;
    tracker.addActivity("Run", "2025-11-07", 30, 200);
    tracker.addActivity("Bike", "2025-11-08", 45, 350);
    auto dates = tracker.getAllDates();
    EXPECT_EQ(dates[0], "2025-11-07");
    EXPECT_EQ(dates[1], "2025-11-08");
}

TEST(FitnessTrackerTest, StoresAllDurations) {
    FitnessTracker tracker;
    tracker.addActivity("Run", "2025-11-07", 30, 200);
    tracker.addActivity("Swim", "2025-11-08", 40, 300);
    auto durations = tracker.getAllDurations();
    EXPECT_EQ(durations.size(), 2);
    EXPECT_DOUBLE_EQ(durations[1], 40);
}

TEST(FitnessTrackerTest, StoresAllCalories) {
    FitnessTracker tracker;
    tracker.addActivity("Run", "2025-11-07", 30, 200);
    tracker.addActivity("Swim", "2025-11-08", 40, 300);
    auto calories = tracker.getAllCalories();
    EXPECT_EQ(calories.size(), 2);
    EXPECT_DOUBLE_EQ(calories[0], 200);
    EXPECT_DOUBLE_EQ(calories[1], 300);
}

TEST(FitnessTrackerTest, NoActivitiesReturnsZero) {
    FitnessTracker tracker;
    EXPECT_TRUE(tracker.getAllCalories().empty());
    EXPECT_DOUBLE_EQ(tracker.getTotalCaloriesBurned(), 0);
}

TEST(FitnessTrackerTest, ZeroDurationActivityHandled) {
    FitnessTracker tracker;
    tracker.addActivity("Yoga", "2025-11-07", 0, 100);
    EXPECT_DOUBLE_EQ(tracker.getActivityDuration(), 0);
    EXPECT_DOUBLE_EQ(tracker.getActivityCalories(), 100);
}

TEST(FitnessTrackerTest, ZeroCaloriesActivityHandled) {
    FitnessTracker tracker;
    tracker.addActivity("Stretching", "2025-11-07", 15, 0);
    EXPECT_DOUBLE_EQ(tracker.getActivityCalories(), 0);
}

TEST(FitnessTrackerTest, MultipleActivitiesAccumulateCorrectly) {
    FitnessTracker tracker;
    tracker.addActivity("Run", "2025-11-07", 30, 200);
    tracker.addActivity("Bike", "2025-11-08", 60, 400);
    tracker.addActivity("Swim", "2025-11-09", 45, 350);
    EXPECT_DOUBLE_EQ(tracker.getTotalCaloriesBurned(), 950);
    EXPECT_EQ(tracker.getAllTypes().size(), 3);
}

TEST(FitnessTrackerTest, SameActivityDifferentDates) {
    FitnessTracker tracker;
    tracker.addActivity("Run", "2025-11-07", 30, 200);
    tracker.addActivity("Run", "2025-11-08", 45, 300);
    auto dates = tracker.getAllDates();
    EXPECT_EQ(dates[0], "2025-11-07");
    EXPECT_EQ(dates[1], "2025-11-08");
}
