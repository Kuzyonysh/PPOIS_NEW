#include "gtest/gtest.h"
#include "Challenge.h"


TEST(ChallengeTests, ConstructorSetsValuesCorrectly) {
    Challenge ch("Run 5K", "Run a total of 5 kilometers", 5.0, "2025-11-01", "2025-11-30");

    EXPECT_EQ(ch.getName(), "Run 5K");
    EXPECT_EQ(ch.getDescription(), "Run a total of 5 kilometers");
    EXPECT_DOUBLE_EQ(ch.getTarget(), 5.0);
    EXPECT_DOUBLE_EQ(ch.getProgress(), 0.0);
    EXPECT_FALSE(ch.isCompleted());
}

TEST(ChallengeTests, ProgressStartsAtZero) {
    Challenge ch("Pushups", "Do 100 pushups", 100, "2025-11-01", "2025-11-15");
    EXPECT_DOUBLE_EQ(ch.getProgress(), 0.0);
}

TEST(ChallengeTests, NotCompletedInitially) {
    Challenge ch("Yoga", "Attend 10 yoga sessions", 10, "2025-11-01", "2025-11-30");
    EXPECT_FALSE(ch.isCompleted());
}

TEST(ChallengeTests, UpdateProgressIncreasesValue) {
    Challenge ch("Steps", "Walk 10,000 steps", 10000, "2025-11-01", "2025-11-07");
    ch.updateProgress(3000);
    EXPECT_DOUBLE_EQ(ch.getProgress(), 3000);
    EXPECT_FALSE(ch.isCompleted());
}

TEST(ChallengeTests, UpdateProgressMultipleTimesAccumulates) {
    Challenge ch("Squats", "Do 200 squats", 200, "2025-11-01", "2025-11-30");
    ch.updateProgress(50);
    ch.updateProgress(100);
    EXPECT_DOUBLE_EQ(ch.getProgress(), 150);
    EXPECT_FALSE(ch.isCompleted());
}

TEST(ChallengeTests, UpdateProgressCompletesWhenTargetReached) {
    Challenge ch("Run", "Run 5km", 5.0, "2025-11-01", "2025-11-30");
    ch.updateProgress(5.0);
    EXPECT_TRUE(ch.isCompleted());
}

TEST(ChallengeTests, UpdateProgressCompletesWhenTargetExceeded) {
    Challenge ch("Calories", "Burn 2000 calories", 2000, "2025-11-01", "2025-11-15");
    ch.updateProgress(2500);
    EXPECT_TRUE(ch.isCompleted());
}

TEST(ChallengeTests, UpdateProgressDoesNotResetAfterCompletion) {
    Challenge ch("Swim", "Swim 100 laps", 100, "2025-11-01", "2025-11-15");
    ch.updateProgress(120);
    EXPECT_TRUE(ch.isCompleted());
    EXPECT_DOUBLE_EQ(ch.getProgress(), 120);
}

TEST(ChallengeTests, PartialProgressDoesNotMarkCompleted) {
    Challenge ch("Plank", "Hold plank for 5 minutes total", 5, "2025-11-01", "2025-11-05");
    ch.updateProgress(3.5);
    EXPECT_FALSE(ch.isCompleted());
}

TEST(ChallengeTests, UpdateProgressZeroDoesNothing) {
    Challenge ch("Meditation", "Meditate 10 times", 10, "2025-11-01", "2025-11-30");
    ch.updateProgress(0);
    EXPECT_DOUBLE_EQ(ch.getProgress(), 0);
    EXPECT_FALSE(ch.isCompleted());
}

TEST(ChallengeTests, UpdateProgressWithHugeValueCompletes) {
    Challenge ch("Cycling", "Cycle 50km", 50, "2025-11-01", "2025-11-30");
    ch.updateProgress(100);
    EXPECT_TRUE(ch.isCompleted());
}

TEST(ChallengeTests, NegativeProgressReducesValue) {
    Challenge ch("Steps", "Walk 10k steps", 10000, "2025-11-01", "2025-11-30");
    ch.updateProgress(5000);
    ch.updateProgress(-2000);
    EXPECT_DOUBLE_EQ(ch.getProgress(), 3000);
    EXPECT_FALSE(ch.isCompleted());
}

TEST(ChallengeTests, MultipleUpdatesLeadToCompletionEventually) {
    Challenge ch("Jump Rope", "Do 1000 jumps", 1000, "2025-11-01", "2025-11-15");
    for (int i = 0; i < 5; ++i)
        ch.updateProgress(200);
    EXPECT_TRUE(ch.isCompleted());
}

TEST(ChallengeTests, CompletionRemainsTrueAfterFurtherUpdates) {
    Challenge ch("Run Marathon", "Run 42km", 42, "2025-11-01", "2025-12-01");
    ch.updateProgress(42);
    ch.updateProgress(10);
    EXPECT_TRUE(ch.isCompleted());
    EXPECT_DOUBLE_EQ(ch.getProgress(), 52);
}
