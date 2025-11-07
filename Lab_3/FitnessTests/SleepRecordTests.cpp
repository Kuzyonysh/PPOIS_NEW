#include "gtest/gtest.h"
#include "SleepRecord.h"
#include "SleepManager.h"
#include "Exception.h"
#include <string>
#include <vector>

using namespace std;

TEST(SleepRecordTest, ConstructorAndGetters) {
    SleepRecord record("2025-11-07", 7.5, 85);
    EXPECT_EQ(record.getDate(), "2025-11-07");
    EXPECT_DOUBLE_EQ(record.getHours(), 7.5);
    EXPECT_EQ(record.getQuality(), 85);
}

TEST(SleepRecordTest, Setters) {
    SleepRecord record("2025-11-07", 7.5, 85);
    record.setDate("2025-11-08");
    record.setHours(8.0);
    record.setQuality(90);
    EXPECT_EQ(record.getDate(), "2025-11-08");
    EXPECT_DOUBLE_EQ(record.getHours(), 8.0);
    EXPECT_EQ(record.getQuality(), 90);
}

TEST(SleepManagerTest, AddSleepRecordAndAverageQuality) {
    SleepManager manager;
    SleepRecord r1("2025-11-07", 6.5, 80);
    SleepRecord r2("2025-11-08", 8.0, 90);
    manager.addSleepRecord(r1);
    manager.addSleepRecord(r2);
    EXPECT_DOUBLE_EQ(manager.getAverageQuality(), (80 + 90) / 2.0);
}

TEST(SleepManagerTest, AverageQualityEmpty) {
    SleepManager manager;
    EXPECT_DOUBLE_EQ(manager.getAverageQuality(), 0.0);
}

TEST(SleepManagerTest, GetSleepHoursByDateExisting) {
    SleepManager manager;
    SleepRecord r("2025-11-07", 7.5, 85);
    manager.addSleepRecord(r);
    EXPECT_DOUBLE_EQ(manager.getSleepHoursByDate("2025-11-07"), 7.5);
}

TEST(SleepManagerTest, GetSleepHoursByDateThrows) {
    SleepManager manager;
    EXPECT_THROW(manager.getSleepHoursByDate("2025-11-07"), EmptyDataAboutDream);
}

TEST(SleepManagerTest, CheckSleepQualityLessThan7) {
    SleepManager manager;
    SleepRecord r("2025-11-07", 6.5, 80);
    manager.addSleepRecord(r);
    testing::internal::CaptureStdout();
    manager.checkSleepQuality("2025-11-07");
    string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("less than 7 hours"), string::npos);
}

TEST(SleepManagerTest, CheckSleepQuality7OrMore) {
    SleepManager manager;
    SleepRecord r("2025-11-07", 7.5, 85);
    manager.addSleepRecord(r);
    testing::internal::CaptureStdout();
    manager.checkSleepQuality("2025-11-07");
    string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("slept well"), string::npos);
}

TEST(SleepManagerTest, CheckSleepQualityThrowsForNoData) {
    SleepManager manager;
    EXPECT_THROW(manager.checkSleepQuality("2025-11-07"), EmptyDataAboutDream);
}

TEST(SleepManagerTest, ExportSleepReportMessage) {
    SleepManager manager;
    testing::internal::CaptureStdout();
    manager.exportSleepReport();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("sleep_report.txt"), string::npos);
}

TEST(SleepManagerTest, SendSleepReminderMessage) {
    SleepManager manager;
    testing::internal::CaptureStdout();
    manager.sendSleepReminder();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Reminder"), string::npos);
}

TEST(SleepManagerTest, ShowSleepTrendsMessage) {
    SleepManager manager;
    testing::internal::CaptureStdout();
    manager.showSleepTrends();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("sleep trends chart"), string::npos);
}

TEST(SleepManagerTest, MultipleSleepRecordsAverage) {
    SleepManager manager;
    manager.addSleepRecord(SleepRecord("2025-11-07", 6.0, 70));
    manager.addSleepRecord(SleepRecord("2025-11-08", 7.0, 80));
    manager.addSleepRecord(SleepRecord("2025-11-09", 8.0, 90));
    EXPECT_DOUBLE_EQ(manager.getAverageQuality(), (70 + 80 + 90) / 3.0);
}

TEST(SleepManagerTest, GetSleepHoursMultipleRecords) {
    SleepManager manager;
    manager.addSleepRecord(SleepRecord("2025-11-07", 6.0, 70));
    manager.addSleepRecord(SleepRecord("2025-11-08", 7.5, 80));
    EXPECT_DOUBLE_EQ(manager.getSleepHoursByDate("2025-11-08"), 7.5);
}
