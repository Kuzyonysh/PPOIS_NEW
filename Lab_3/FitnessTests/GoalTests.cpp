#include "gtest/gtest.h"
#include "Goal.h"
#include "GoalManager.h"
#include "Exception.h"
#include <sstream>
#include <iostream>

TEST(GoalTest, ConstructorAndGetters) {
    Goal g("Run 10 km", 10, "km");
    EXPECT_EQ(g.getName(), "Run 10 km");
    EXPECT_DOUBLE_EQ(g.getTarget(), 10);
    EXPECT_DOUBLE_EQ(g.getCurrent(), 0);
    EXPECT_EQ(g.getUnit(), "km");
    EXPECT_FALSE(g.isAchieved());
}

TEST(GoalTest, UpdateProgressNormal) {
    Goal g("Run 10 km", 10, "km");
    g.updateProgress(3);
    EXPECT_DOUBLE_EQ(g.getCurrent(), 3);
    EXPECT_FALSE(g.isAchieved());
    g.updateProgress(7);
    EXPECT_DOUBLE_EQ(g.getCurrent(), 10);
    EXPECT_TRUE(g.isAchieved());
}

TEST(GoalTest, UpdateProgressExceedsTarget) {
    Goal g("Run 10 km", 10, "km");
    g.updateProgress(15);
    EXPECT_DOUBLE_EQ(g.getCurrent(), 15);
    EXPECT_TRUE(g.isAchieved());
}

TEST(GoalTest, UpdateProgressNegativeThrows) {
    Goal g("Run 10 km", 10, "km");
    EXPECT_THROW(g.updateProgress(-5), GoalException);
}

TEST(GoalTest, SetAchieved) {
    Goal g("Run 10 km", 10, "km");
    g.setAchieved(true);
    EXPECT_TRUE(g.isAchieved());
}

TEST(GoalManagerTest, AddGoalAndTotalCount) {
    GoalManager manager;
    Goal g1("Run 10 km", 10, "km");
    Goal g2("Drink 2 L water", 2, "L");
    manager.addGoal(g1);
    manager.addGoal(g2);
    EXPECT_EQ(manager.totalGoals(), 2);
}

TEST(GoalManagerTest, GetAchievedAndPendingGoals) {
    GoalManager manager;
    Goal g1("Run 10 km", 10, "km");
    Goal g2("Drink 2 L water", 2, "L");
    g1.setAchieved(true);
    manager.addGoal(g1);
    manager.addGoal(g2);
    auto achieved = manager.getAchievedGoals();
    auto pending = manager.getPendingGoals();
    EXPECT_EQ(achieved.size(), 1);
    EXPECT_EQ(pending.size(), 1);
    EXPECT_EQ(achieved[0].getName(), "Run 10 km");
    EXPECT_EQ(pending[0].getName(), "Drink 2 L water");
}

TEST(GoalManagerTest, MarkGoalAchievedTrue) {
    GoalManager manager;
    Goal g("Run 10 km", 10, "km");
    manager.addGoal(g);
    bool result = manager.markGoalAchieved("Run 10 km");
    EXPECT_TRUE(result);
    EXPECT_TRUE(manager.getAchievedGoals()[0].isAchieved());
}

TEST(GoalManagerTest, MarkGoalAchievedFalse) {
    GoalManager manager;
    Goal g("Run 10 km", 10, "km");
    manager.addGoal(g);
    bool result = manager.markGoalAchieved("Swim 5 km");
    EXPECT_FALSE(result);
}

TEST(GoalManagerTest, RemoveGoalTrue) {
    GoalManager manager;
    Goal g("Run 10 km", 10, "km");
    manager.addGoal(g);
    bool removed = manager.removeGoal("Run 10 km");
    EXPECT_TRUE(removed);
    EXPECT_EQ(manager.totalGoals(), 0);
}

TEST(GoalManagerTest, RemoveGoalFalse) {
    GoalManager manager;
    Goal g("Run 10 km", 10, "km");
    manager.addGoal(g);
    bool removed = manager.removeGoal("Swim 5 km");
    EXPECT_FALSE(removed);
    EXPECT_EQ(manager.totalGoals(), 1);
}

TEST(GoalManagerTest, AchievedAndPendingCount) {
    GoalManager manager;
    Goal g1("Run 10 km", 10, "km");
    Goal g2("Drink 2 L water", 2, "L");
    g1.setAchieved(true);
    manager.addGoal(g1);
    manager.addGoal(g2);
    EXPECT_EQ(manager.achievedCount(), 1);
    EXPECT_EQ(manager.pendingCount(), 1);
}

TEST(GoalManagerTest, PrintAllGoalsOutput) {
    GoalManager manager;
    Goal g1("Run 10 km", 10, "km");
    g1.setAchieved(true);
    Goal g2("Drink 2 L water", 2, "L");
    manager.addGoal(g1);
    manager.addGoal(g2);
    testing::internal::CaptureStdout();
    manager.printAllGoals();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Run 10 km: 0/10 km (achieved)"), std::string::npos);
    EXPECT_NE(output.find("Drink 2 L water: 0/2 L (pending)"), std::string::npos);
}

TEST(GoalManagerTest, MultipleGoalUpdates) {
    GoalManager manager;
    Goal g1("Run 10 km", 10, "km");
    Goal g2("Drink 2 L water", 2, "L");
    manager.addGoal(g1);
    manager.addGoal(g2);
    manager.getPendingGoals()[0].updateProgress(5); 
    EXPECT_EQ(manager.getPendingGoals()[0].getCurrent(), 0); 
}
