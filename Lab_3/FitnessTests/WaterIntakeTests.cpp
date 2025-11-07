#include "gtest/gtest.h"
#include "WaterIntake.h"
#include "WaterIntakeManager.h"
#include "Exception.h"
#include <string>

using namespace std;

TEST(WaterIntakeTest, ConstructorAndGetters) {
    WaterIntake w("2025-11-07", 1500.0, 2000.0, "Morning intake");
    EXPECT_EQ(w.getDate(), "2025-11-07");
    EXPECT_DOUBLE_EQ(w.getAmount(), 1500.0);
    EXPECT_DOUBLE_EQ(w.getDailyGoal(), 2000.0);
    EXPECT_EQ(w.getNote(), "Morning intake");
}

TEST(WaterIntakeTest, Setters) {
    WaterIntake w("2025-11-07", 1500.0, 2000.0, "Morning intake");
    w.setDate("2025-11-08");
    w.setAmount(1800.0);
    w.setDailyGoal(2500.0);
    w.setNote("Afternoon intake");
    EXPECT_EQ(w.getDate(), "2025-11-08");
    EXPECT_DOUBLE_EQ(w.getAmount(), 1800.0);
    EXPECT_DOUBLE_EQ(w.getDailyGoal(), 2500.0);
    EXPECT_EQ(w.getNote(), "Afternoon intake");
}

TEST(WaterIntakeManagerTest, AddWaterPositive) {
    WaterIntake w("2025-11-07", 1000.0, 2000.0, "");
    WaterIntakeManager manager(w);
    testing::internal::CaptureStdout();
    manager.addWater(500.0);
    string output = testing::internal::GetCapturedStdout();
    EXPECT_DOUBLE_EQ(w.getAmount(), 1500.0);
    EXPECT_NE(output.find("500"), string::npos);
}

TEST(WaterIntakeManagerTest, AddWaterZeroThrows) {
    WaterIntake w("2025-11-07", 1000.0, 2000.0, "");
    WaterIntakeManager manager(w);
    EXPECT_THROW(manager.addWater(0.0), InvalidWaterAmountException);
}

TEST(WaterIntakeManagerTest, AddWaterNegativeThrows) {
    WaterIntake w("2025-11-07", 1000.0, 2000.0, "");
    WaterIntakeManager manager(w);
    EXPECT_THROW(manager.addWater(-100.0), InvalidWaterAmountException);
}

TEST(WaterIntakeManagerTest, CheckNormFalse) {
    WaterIntake w("2025-11-07", 1500.0, 2000.0, "");
    WaterIntakeManager manager(w);
    EXPECT_FALSE(manager.checkNorm());
}

TEST(WaterIntakeManagerTest, CheckNormTrue) {
    WaterIntake w("2025-11-07", 2000.0, 2000.0, "");
    WaterIntakeManager manager(w);
    EXPECT_TRUE(manager.checkNorm());
}

TEST(WaterIntakeManagerTest, PrintProgress) {
    WaterIntake w("2025-11-07", 1000.0, 2000.0, "");
    WaterIntakeManager manager(w);
    testing::internal::CaptureStdout();
    manager.printProgress();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("50"), string::npos);
}

TEST(WaterIntakeManagerTest, RemindToDrinkNotReached) {
    WaterIntake w("2025-11-07", 1500.0, 2000.0, "");
    WaterIntakeManager manager(w);
    testing::internal::CaptureStdout();
    manager.remindToDrink();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Drink 500"), string::npos);
}

TEST(WaterIntakeManagerTest, RemindToDrinkReached) {
    WaterIntake w("2025-11-07", 2000.0, 2000.0, "");
    WaterIntakeManager manager(w);
    testing::internal::CaptureStdout();
    manager.remindToDrink();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Congratulations"), string::npos);
}

TEST(WaterIntakeManagerTest, ResetAmount) {
    WaterIntake w("2025-11-07", 1500.0, 2000.0, "");
    WaterIntakeManager manager(w);
    testing::internal::CaptureStdout();
    manager.resetAmount();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_DOUBLE_EQ(w.getAmount(), 0.0);
    EXPECT_NE(output.find("reset"), string::npos);
}

TEST(WaterIntakeManagerTest, AddMultiplePortions) {
    WaterIntake w("2025-11-07", 500.0, 2000.0, "");
    WaterIntakeManager manager(w);
    manager.addWater(300.0);
    manager.addWater(400.0);
    EXPECT_DOUBLE_EQ(w.getAmount(), 1200.0);
}

TEST(WaterIntakeManagerTest, CheckNormEdge) {
    WaterIntake w("2025-11-07", 2000.0, 2000.0, "");
    WaterIntakeManager manager(w);
    EXPECT_TRUE(manager.checkNorm());
}

TEST(WaterIntakeManagerTest, RemindToDrinkZeroIntake) {
    WaterIntake w("2025-11-07", 0.0, 2000.0, "");
    WaterIntakeManager manager(w);
    testing::internal::CaptureStdout();
    manager.remindToDrink();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Drink 2000"), string::npos);
}
