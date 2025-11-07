#include "gtest/gtest.h"
#include "HealthReportManager.h"
#include "HealthReport.h"
#include <string>
#include <vector>

using namespace std;

TEST(HealthReportTest, SetCommentAndImprovement) {
    HealthReport report("2025-11-07", 7, 80, 2000, 500, 2, 2, 70, "happy", 70, 22, 90, 100);
    report.setComment("Good day");
    report.setImprovement(true);
    EXPECT_EQ(report.getComment(), "Good day");
    EXPECT_TRUE(report.isImproved());
}

TEST(HealthReportTest, UpdateCalorieBalance) {
    HealthReport report("2025-11-07", 7, 80, 2000, 500, 2, 2, 70, "happy", 70, 22, 90, 100);
    report.updateCalorieBalance();
    EXPECT_DOUBLE_EQ(report.getCalorieBalance(), 1500.0);
}

TEST(HealthReportTest, SetMood) {
    HealthReport report("2025-11-07", 7, 80, 2000, 500, 2, 2, 70, "happy", 70, 22, 90, 100);
    report.setMood("excited", 90);
    EXPECT_EQ(report.getEmotion(), "excited");
    EXPECT_DOUBLE_EQ(report.getMoodLevel(), 90);
}

TEST(HealthReportTest, InitialCalorieBalance) {
    HealthReport report("2025-11-07", 7, 80, 1800, 600, 2, 2, 70, "happy", 70, 22, 90, 100);
    EXPECT_DOUBLE_EQ(report.getCalorieBalance(), 1200.0);
}

TEST(HealthReportTest, InitialMoodAndEmotion) {
    HealthReport report("2025-11-07", 7, 80, 1800, 600, 2, 2, 65, "neutral", 70, 22, 90, 100);
    EXPECT_DOUBLE_EQ(report.getMoodLevel(), 65);
    EXPECT_EQ(report.getEmotion(), "neutral");
}

TEST(HealthReportTest, InitialWaterAndGoal) {
    HealthReport report("2025-11-07", 7, 80, 1800, 600, 1.5, 2.0, 65, "neutral", 70, 22, 90, 100);
    EXPECT_DOUBLE_EQ(report.getWaterIntake(), 1.5);
    EXPECT_DOUBLE_EQ(report.getWaterGoal(), 2.0);
}

TEST(HealthReportTest, WeightAndBMI) {
    HealthReport report("2025-11-07", 7, 80, 1800, 600, 1.5, 2.0, 65, "neutral", 68, 21.5, 88, 98);
    EXPECT_DOUBLE_EQ(report.getWeight(), 68);
    EXPECT_DOUBLE_EQ(report.getBMI(), 21.5);
}

TEST(HealthReportTest, WaistAndHips) {
    HealthReport report("2025-11-07", 7, 80, 1800, 600, 1.5, 2.0, 65, "neutral", 68, 21.5, 88, 98);
    EXPECT_DOUBLE_EQ(report.getWaist(), 88);
    EXPECT_DOUBLE_EQ(report.getHips(), 98);
}

TEST(HealthReportTest, CommentAndImprovedDefault) {
    HealthReport report("2025-11-07", 7, 80, 1800, 600, 1.5, 2.0, 65, "neutral", 68, 21.5, 88, 98);
    EXPECT_EQ(report.getComment(), "");
    EXPECT_FALSE(report.isImproved());
}

TEST(HealthReportTest, CalorieBalanceAfterChangingCalories) {
    HealthReport report("2025-11-07", 7, 80, 2000, 400, 2, 2, 70, "happy", 70, 22, 90, 100);
    report.updateCalorieBalance();
    EXPECT_DOUBLE_EQ(report.getCalorieBalance(), 1600.0);
}

TEST(HealthReportTest, MoodUpdate) {
    HealthReport report("2025-11-07", 7, 80, 2000, 400, 2, 2, 70, "happy", 70, 22, 90, 100);
    report.setMood("sad", 40);
    EXPECT_EQ(report.getEmotion(), "sad");
    EXPECT_DOUBLE_EQ(report.getMoodLevel(), 40);
}


TEST(HealthReportManagerTest, GenerateReportConsistency) {
    HealthReport report1("2025-11-07", 7, 80, 2000, 500, 2, 2, 70, "happy", 70, 22, 90, 100);
    HealthReport report2("2025-11-07", 7, 80, 2000, 500, 2, 2, 70, "happy", 70, 22, 90, 100);
    EXPECT_DOUBLE_EQ(report1.getCaloriesIn(), report2.getCaloriesIn());
    EXPECT_DOUBLE_EQ(report1.getCaloriesOut(), report2.getCaloriesOut());
}

TEST(HealthReportTest, MultipleReportsVector) {
    vector<HealthReport> reports;
    reports.push_back(HealthReport("2025-11-07", 7, 80, 2000, 500, 2, 2, 70, "happy", 70, 22, 90, 100));
    reports.push_back(HealthReport("2025-11-08", 6, 75, 1800, 400, 1.5, 2, 65, "neutral", 68, 21.5, 88, 98));
    reports.push_back(HealthReport("2025-11-09", 8, 85, 2100, 600, 2.2, 2, 80, "excited", 72, 22.5, 92, 102));
    EXPECT_EQ(reports.size(), 3);
}
