#include "gtest/gtest.h"
#include "MoodRecord.h"
#include "MentalHealthManager.h"
#include "Exception.h"
#include <string>
#include <vector>

using namespace std;

TEST(MoodRecordTest, ConstructorAndGetters) {
    MoodRecord record("2025-11-07", 7, 5, "Feeling good");
    EXPECT_EQ(record.getDate(), "2025-11-07");
    EXPECT_EQ(record.getMood(), 7);
    EXPECT_EQ(record.getStressLevel(), 5);
    EXPECT_EQ(record.getNote(), "Feeling good");
}

TEST(MoodRecordTest, ConstructorThrowsOutOfRange) {
    EXPECT_THROW(MoodRecord("2025-11-07", 0, 5, ""), MentalHealthException);
    EXPECT_THROW(MoodRecord("2025-11-07", 11, 5, ""), MentalHealthException);
    EXPECT_THROW(MoodRecord("2025-11-07", 5, 0, ""), MentalHealthException);
    EXPECT_THROW(MoodRecord("2025-11-07", 5, 11, ""), MentalHealthException);
}

TEST(MoodRecordTest, SetMoodAndStress) {
    MoodRecord record("2025-11-07", 5, 5, "");
    record.setMood(8);
    record.setStress(3);
    EXPECT_EQ(record.getMood(), 8);
    EXPECT_EQ(record.getStressLevel(), 3);
}

TEST(MoodRecordTest, SetMoodOutOfRangeThrows) {
    MoodRecord record("2025-11-07", 5, 5, "");
    EXPECT_THROW(record.setMood(0), MentalHealthException);
    EXPECT_THROW(record.setMood(11), MentalHealthException);
}

TEST(MoodRecordTest, SetStressOutOfRangeThrows) {
    MoodRecord record("2025-11-07", 5, 5, "");
    EXPECT_THROW(record.setStress(0), MentalHealthException);
    EXPECT_THROW(record.setStress(11), MentalHealthException);
}

TEST(MoodRecordTest, SetNote) {
    MoodRecord record("2025-11-07", 5, 5, "");
    record.setNote("Tired");
    EXPECT_EQ(record.getNote(), "Tired");
}

TEST(MentalHealthManagerTest, AddMoodRecordAndAverageMood) {
    MentalHealthManager manager;
    MoodRecord r1("2025-11-07", 6, 4, "");
    MoodRecord r2("2025-11-08", 8, 6, "");
    manager.addMoodRecord(r1);
    manager.addMoodRecord(r2);
    EXPECT_DOUBLE_EQ(manager.getAverageMood(), 7.0);
    EXPECT_DOUBLE_EQ(manager.getAverageStress(), 5.0);
}

TEST(MentalHealthManagerTest, AverageMoodAndStressEmpty) {
    MentalHealthManager manager;
    EXPECT_DOUBLE_EQ(manager.getAverageMood(), 0);
    EXPECT_DOUBLE_EQ(manager.getAverageStress(), 0);
}

TEST(MentalHealthManagerTest, GetMoodByDateExisting) {
    MentalHealthManager manager;
    MoodRecord r("2025-11-07", 7, 5, "Good day");
    manager.addMoodRecord(r);
    MoodRecord found = manager.getMoodByDate("2025-11-07");
    EXPECT_EQ(found.getMood(), 7);
    EXPECT_EQ(found.getStressLevel(), 5);
    EXPECT_EQ(found.getNote(), "Good day");
}

TEST(MentalHealthManagerTest, GetMoodByDateNonExistingThrows) {
    MentalHealthManager manager;
    EXPECT_THROW(manager.getMoodByDate("2025-11-07"), MentalHealthException);
}

TEST(MentalHealthManagerTest, MultipleMoodRecordsAverage) {
    MentalHealthManager manager;
    manager.addMoodRecord(MoodRecord("2025-11-07", 6, 3, ""));
    manager.addMoodRecord(MoodRecord("2025-11-08", 8, 7, ""));
    manager.addMoodRecord(MoodRecord("2025-11-09", 5, 5, ""));
    EXPECT_DOUBLE_EQ(manager.getAverageMood(), (6 + 8 + 5) / 3.0);
    EXPECT_DOUBLE_EQ(manager.getAverageStress(), (3 + 7 + 5) / 3.0);
}

TEST(MentalHealthManagerTest, AverageAfterSingleRecord) {
    MentalHealthManager manager;
    manager.addMoodRecord(MoodRecord("2025-11-07", 9, 2, ""));
    EXPECT_DOUBLE_EQ(manager.getAverageMood(), 9.0);
    EXPECT_DOUBLE_EQ(manager.getAverageStress(), 2.0);
}

TEST(MentalHealthManagerTest, MoodByDateAfterMultipleRecords) {
    MentalHealthManager manager;
    manager.addMoodRecord(MoodRecord("2025-11-07", 6, 3, ""));
    manager.addMoodRecord(MoodRecord("2025-11-08", 8, 7, ""));
    MoodRecord r = manager.getMoodByDate("2025-11-08");
    EXPECT_EQ(r.getMood(), 8);
    EXPECT_EQ(r.getStressLevel(), 7);
}

TEST(MentalHealthManagerTest, AddRecordsDoesNotAffectPrevious) {
    MentalHealthManager manager;
    MoodRecord r1("2025-11-07", 6, 3, "");
    manager.addMoodRecord(r1);
    MoodRecord r2("2025-11-08", 8, 7, "");
    manager.addMoodRecord(r2);
    MoodRecord found = manager.getMoodByDate("2025-11-07");
    EXPECT_EQ(found.getMood(), 6);
    EXPECT_EQ(found.getStressLevel(), 3);
}
