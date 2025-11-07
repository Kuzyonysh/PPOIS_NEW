#include "gtest/gtest.h"
#include "MealRecord.h"
#include "MealRecordManager.h"
#include <string>
#include <vector>

using namespace std;

TEST(MealRecordTest, ConstructorAndGetters) {
    MealRecord meal("Breakfast", "2025-11-07", 500);
    EXPECT_EQ(meal.getMealType(), "Breakfast");
    EXPECT_EQ(meal.getData(), "2025-11-07");
    EXPECT_DOUBLE_EQ(meal.getCalories(), 500);
}

TEST(MealRecordTest, Setters) {
    MealRecord meal("Lunch", "2025-11-07", 600);
    meal.setMealType("Dinner");
    meal.setDate("2025-11-08");
    meal.setCalories(700);
    EXPECT_EQ(meal.getMealType(), "Dinner");
    EXPECT_EQ(meal.getData(), "2025-11-08");
    EXPECT_DOUBLE_EQ(meal.getCalories(), 700);
}


TEST(MealRecordManagerTest, AddMealRecord) {
    MealRecordManager manager;
    MealRecord meal("Breakfast", "2025-11-07", 500);
    manager.addMealRecord(meal);
    vector<MealRecord> records = manager.getAllRecords();
    EXPECT_EQ(records.size(), 1);
    EXPECT_EQ(records[0].getMealType(), "Breakfast");
}

TEST(MealRecordManagerTest, RemoveMealRecordExisting) {
    MealRecordManager manager;
    MealRecord meal1("Breakfast", "2025-11-07", 500);
    MealRecord meal2("Lunch", "2025-11-07", 600);
    manager.addMealRecord(meal1);
    manager.addMealRecord(meal2);
    bool removed = manager.removeMealRecord("Breakfast");
    EXPECT_TRUE(removed);
    vector<MealRecord> records = manager.getAllRecords();
    EXPECT_EQ(records.size(), 1);
    EXPECT_EQ(records[0].getMealType(), "Lunch");
}

TEST(MealRecordManagerTest, RemoveMealRecordNonExisting) {
    MealRecordManager manager;
    MealRecord meal("Lunch", "2025-11-07", 600);
    manager.addMealRecord(meal);
    bool removed = manager.removeMealRecord("Dinner");
    EXPECT_FALSE(removed);
    EXPECT_EQ(manager.getAllRecords().size(), 1);
}

TEST(MealRecordManagerTest, FindByDate) {
    MealRecordManager manager;
    MealRecord meal1("Breakfast", "2025-11-07", 500);
    MealRecord meal2("Lunch", "2025-11-08", 600);
    manager.addMealRecord(meal1);
    manager.addMealRecord(meal2);
    vector<MealRecord> results = manager.findByDate("2025-11-07");
    EXPECT_EQ(results.size(), 1);
    EXPECT_EQ(results[0].getMealType(), "Breakfast");
}

TEST(MealRecordManagerTest, GetTotalCaloriesByDate) {
    MealRecordManager manager;
    MealRecord meal1("Breakfast", "2025-11-07", 500);
    MealRecord meal2("Lunch", "2025-11-07", 600);
    manager.addMealRecord(meal1);
    manager.addMealRecord(meal2);
    double total = manager.getTotalCaloriesByDate("2025-11-07");
    EXPECT_DOUBLE_EQ(total, 1100);
}

TEST(MealRecordManagerTest, GetAllRecords) {
    MealRecordManager manager;
    MealRecord meal1("Breakfast", "2025-11-07", 500);
    MealRecord meal2("Lunch", "2025-11-07", 600);
    manager.addMealRecord(meal1);
    manager.addMealRecord(meal2);
    vector<MealRecord> records = manager.getAllRecords();
    EXPECT_EQ(records.size(), 2);
}

TEST(MealRecordManagerTest, MultipleAddAndRemove) {
    MealRecordManager manager;
    MealRecord meal1("Breakfast", "2025-11-07", 500);
    MealRecord meal2("Lunch", "2025-11-07", 600);
    MealRecord meal3("Dinner", "2025-11-07", 700);
    manager.addMealRecord(meal1);
    manager.addMealRecord(meal2);
    manager.addMealRecord(meal3);
    bool removed = manager.removeMealRecord("Lunch");
    EXPECT_TRUE(removed);
    vector<MealRecord> records = manager.getAllRecords();
    EXPECT_EQ(records.size(), 2);
}

TEST(MealRecordManagerTest, CaloriesGoalReachedMessage) {
    MealRecordManager manager;
    testing::internal::CaptureStdout();
    manager.CaloriesGoalReached(2000);
    string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("2000 kcal"), string::npos);
}

TEST(MealRecordManagerTest, MealSkippedMessage) {
    MealRecordManager manager;
    testing::internal::CaptureStdout();
    manager.MealSkipped("Lunch");
    string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("skipped Lunch"), string::npos);
}

TEST(MealRecordManagerTest, MealPlannedMessage) {
    MealRecordManager manager;
    testing::internal::CaptureStdout();
    manager.MealPlanned("Dinner");
    string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("planned for today"), string::npos);
}

TEST(MealRecordManagerTest, MealConsumedMessage) {
    MealRecordManager manager;
    testing::internal::CaptureStdout();
    manager.MealConsumed("Breakfast");
    string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("consumed your Breakfast"), string::npos);
}
