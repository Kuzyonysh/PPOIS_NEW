#include "gtest/gtest.h"
#include "DailyPlan.h"
#include "DailyPlanManager.h"
#include "MealRecord.h"
#include "WaterIntake.h"
#include "SleepRecord.h"
#include "FitnessTracker.h"
#include <string>
#include <vector>

using namespace std;

TEST(DailyPlanTest, ConstructorAndGetters) {
    WaterIntake w("2025-11-07", 1500.0, 2000.0, "");
    SleepRecord s("2025-11-07", 7.5, 80);
    DailyPlan plan("2025-11-07", w, s);
    EXPECT_EQ(plan.getDate(), "2025-11-07");
    EXPECT_DOUBLE_EQ(plan.getWater().getAmount(), 1500.0);
    EXPECT_DOUBLE_EQ(plan.getSleep().getHours(), 7.5);
    EXPECT_EQ(plan.getWorkouts().size(), 0);
    EXPECT_EQ(plan.getMeals().size(), 0);
}

TEST(DailyPlanTest, Setters) {
    WaterIntake w("2025-11-07", 1500.0, 2000.0, "");
    SleepRecord s("2025-11-07", 7.5, 80);
    DailyPlan plan("2025-11-07", w, s);
    plan.setDate("2025-11-08");
    WaterIntake newWater("2025-11-08", 1800.0, 2000.0, "");
    SleepRecord newSleep("2025-11-08", 8.0, 90);
    plan.setWater(newWater);
    plan.setSleep(newSleep);
    EXPECT_EQ(plan.getDate(), "2025-11-08");
    EXPECT_DOUBLE_EQ(plan.getWater().getAmount(), 1800.0);
    EXPECT_DOUBLE_EQ(plan.getSleep().getHours(), 8.0);
}

TEST(DailyPlanTest, AddMealsAndWorkouts) {
    WaterIntake w("2025-11-07", 1500.0, 2000.0, "");
    SleepRecord s("2025-11-07", 7.5, 80);
    DailyPlan plan("2025-11-07", w, s);

    MealRecord m1("Breakfast", "2025-11-07", 500.0);
    MealRecord m2("Lunch", "2025-11-07", 700.0);
    plan.addMeal(m1);
    plan.addMeal(m2);
    EXPECT_EQ(plan.getMeals().size(), 2);

    FitnessTracker f1;
    FitnessTracker f2;
    plan.addWorkout(f1);
    plan.addWorkout(f2);
    EXPECT_EQ(plan.getWorkouts().size(), 2);
}

TEST(DailyPlanManagerTest, AddDailyPlan) {
    WaterIntake w("2025-11-07", 1500.0, 2000.0, "");
    SleepRecord s("2025-11-07", 7.5, 80);
    DailyPlan plan("2025-11-07", w, s);
    DailyPlanManager manager;
    testing::internal::CaptureStdout();
    manager.addDailyPlan(plan);
    string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("added"), string::npos);
}

TEST(DailyPlanManagerTest, GetTotalWater) {
    WaterIntake w("2025-11-07", 1500.0, 2000.0, "");
    SleepRecord s("2025-11-07", 7.5, 80);
    DailyPlan plan("2025-11-07", w, s);
    DailyPlanManager manager;
    manager.addDailyPlan(plan);
    EXPECT_DOUBLE_EQ(manager.getTotalWater("2025-11-07"), 1500.0);
}

TEST(DailyPlanManagerTest, CheckDailyProgressFoundAndNotFound) {
    WaterIntake w("2025-11-07", 1500.0, 2000.0, "");
    SleepRecord s("2025-11-07", 7.5, 80);
    DailyPlan plan("2025-11-07", w, s);
    DailyPlanManager manager;
    manager.addDailyPlan(plan);

    testing::internal::CaptureStdout();
    manager.checkDailyProgress("2025-11-07");
    string out1 = testing::internal::GetCapturedStdout();
    EXPECT_NE(out1.find("completed 80%"), string::npos);

    testing::internal::CaptureStdout();
    manager.checkDailyProgress("2025-11-08");
    string out2 = testing::internal::GetCapturedStdout();
    EXPECT_NE(out2.find("No plan found"), string::npos);
}

TEST(DailyPlanManagerTest, ResetDailyPlans) {
    WaterIntake w("2025-11-07", 1500.0, 2000.0, "");
    SleepRecord s("2025-11-07", 7.5, 80);
    DailyPlan plan("2025-11-07", w, s);
    DailyPlanManager manager;
    manager.addDailyPlan(plan);
    testing::internal::CaptureStdout();
    manager.resetDailyPlans();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(manager.getTotalCalories("2025-11-07"), 0.0);
    EXPECT_NE(output.find("reset"), string::npos);
}

TEST(DailyPlanManagerTest, ShowFunctionsOutput) {
    WaterIntake w("2025-11-07", 1500.0, 2000.0, "");
    SleepRecord s("2025-11-07", 7.5, 80);
    DailyPlan plan("2025-11-07", w, s);
    DailyPlanManager manager;
    manager.addDailyPlan(plan);

    testing::internal::CaptureStdout();
    manager.showMeals("2025-11-07");
    string mOut = testing::internal::GetCapturedStdout();
    EXPECT_NE(mOut.find("Displaying meals"), string::npos);

    testing::internal::CaptureStdout();
    manager.showWorkouts("2025-11-07");
    string wOut = testing::internal::GetCapturedStdout();
    EXPECT_NE(wOut.find("Displaying workouts"), string::npos);

    testing::internal::CaptureStdout();
    manager.showWaterIntake("2025-11-07");
    string waterOut = testing::internal::GetCapturedStdout();
    EXPECT_NE(waterOut.find("Displaying water intake"), string::npos);

    testing::internal::CaptureStdout();
    manager.showSleep("2025-11-07");
    string sleepOut = testing::internal::GetCapturedStdout();
    EXPECT_NE(sleepOut.find("Displaying sleep info"), string::npos);
}
