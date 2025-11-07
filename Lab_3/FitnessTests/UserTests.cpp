#include "gtest/gtest.h"
#include "User.h"
#include "UserManager.h"
#include "BodyMetricsManager.h"
#include "Exception.h"
#include <string>
#include <cmath>
#include <utility>

using namespace std;

TEST(UserTest, ConstructorAndGetters) {
    User u("Darya", 18, 60.0, 170.0, "woman", 3);
    EXPECT_EQ(u.getName(), "Darya");
    EXPECT_EQ(u.getAge(), 18);
    EXPECT_DOUBLE_EQ(u.getWeight(), 60.0);
    EXPECT_DOUBLE_EQ(u.getHeight(), 170.0);
    EXPECT_EQ(u.getGender(), "woman");
    EXPECT_EQ(u.getActivity(), 3);
}

TEST(UserTest, Setters) {
    User u("Darya", 18, 60.0, 170.0, "woman", 3);
    u.setName("Anna");
    u.setAge(20);
    u.setWeight(65.0);
    u.setHeight(175.0);
    u.setGender("man");
    u.setActivity(5);
    EXPECT_EQ(u.getName(), "Anna");
    EXPECT_EQ(u.getAge(), 20);
    EXPECT_DOUBLE_EQ(u.getWeight(), 65.0);
    EXPECT_DOUBLE_EQ(u.getHeight(), 175.0);
    EXPECT_EQ(u.getGender(), "man");
    EXPECT_EQ(u.getActivity(), 5);
}

TEST(UserManagerTest, ConstructorThrowsInvalidHeightWeight) {
    User u("Darya", 18, 0.0, 170.0, "woman", 3);
    BodyMetricsManager bm;
    bm.addMetrics(BodyMetrics("2025-11-07", 60.0, 170.0, 90.0, 100.0));
    EXPECT_THROW(UserManager manager(u, bm), InvalidHeightWeightException);
}

TEST(UserManagerTest, GetCurrentBMI) {
    User u("Darya", 18, 60.0, 170.0, "woman", 3);
    BodyMetricsManager bm;
    bm.addMetrics(BodyMetrics("2025-11-07", 60.0, 170.0, 90.0, 100.0));
    UserManager manager(u, bm);
    EXPECT_DOUBLE_EQ(manager.getCurrentBMI(), 60.0 / pow(170.0 / 100.0, 2));
}

TEST(UserManagerTest, GetBMRWomanAndMan) {
    User u1("Darya", 18, 60.0, 170.0, "woman", 3);
    User u2("Alex", 20, 70.0, 180.0, "man", 4);
    BodyMetricsManager bm1;
    BodyMetricsManager bm2;
    bm1.addMetrics(BodyMetrics("2025-11-07", 60.0, 170.0, 90.0, 100.0));
    bm2.addMetrics(BodyMetrics("2025-11-07", 70.0, 180.0, 90.0, 100.0));
    UserManager m1(u1, bm1);
    UserManager m2(u2, bm2);

    double bmr1 = 10 * 60 + 6.25 * 170 - 5 * 18 - 161;
    double bmr2 = 10 * 70 + 6.25 * 180 - 5 * 20 + 5;
    EXPECT_DOUBLE_EQ(m1.getBMR(), bmr1);
    EXPECT_DOUBLE_EQ(m2.getBMR(), bmr2);
}

TEST(UserManagerTest, GetActivityMultiplier) {
    User u("Darya", 18, 60.0, 170.0, "woman", 0);
    BodyMetricsManager bm;
    bm.addMetrics(BodyMetrics("2025-11-07", 60.0, 170.0, 90.0, 100.0));
    UserManager manager(u, bm);

    EXPECT_DOUBLE_EQ(manager.getActivityMultiplier(0), 1.2);
    EXPECT_DOUBLE_EQ(manager.getActivityMultiplier(2), 1.375);
    EXPECT_DOUBLE_EQ(manager.getActivityMultiplier(4), 1.55);
    EXPECT_DOUBLE_EQ(manager.getActivityMultiplier(6), 1.725);
    EXPECT_DOUBLE_EQ(manager.getActivityMultiplier(7), 1.9);
}

TEST(UserManagerTest, GetTDEE) {
    User u("Darya", 18, 60.0, 170.0, "woman", 3);
    BodyMetricsManager bm;
    bm.addMetrics(BodyMetrics("2025-11-07", 60.0, 170.0, 90.0, 100.0));
    UserManager manager(u, bm);
    double tdee = manager.getBMR() * manager.getActivityMultiplier(3);
    EXPECT_DOUBLE_EQ(manager.getTDEE(3), tdee);
}

TEST(UserManagerTest, IsHealthyWeightRange) {
    User u("Darya", 18, 60.0, 170.0, "woman", 3);
    BodyMetricsManager bm;
    bm.addMetrics(BodyMetrics("2025-11-07", 60.0, 170.0, 90.0, 100.0));
    UserManager manager(u, bm);
    EXPECT_TRUE(manager.isHealthyWeightRange());
}

TEST(UserManagerTest, GetIdealWeightRange) {
    User u("Darya", 18, 60.0, 170.0, "woman", 3);
    BodyMetricsManager bm;
    bm.addMetrics(BodyMetrics("2025-11-07", 60.0, 170.0, 90.0, 100.0));
    UserManager manager(u, bm);
    auto range = manager.getIdealWeightRange();
    double minW = 18.5 * pow(1.7, 2);
    double maxW = 24.9 * pow(1.7, 2);
    EXPECT_DOUBLE_EQ(range.first, minW);
    EXPECT_DOUBLE_EQ(range.second, maxW);
}

TEST(UserManagerTest, PrintBMIStatusNormal) {
    User u("Darya", 18, 60.0, 170.0, "woman", 3);
    BodyMetricsManager bm;
    bm.addMetrics(BodyMetrics("2025-11-07", 60.0, 170.0, 90.0, 100.0));
    UserManager manager(u, bm);

    testing::internal::CaptureStdout();
    manager.printBMIStatus();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("BMI is normal"), string::npos);
}

TEST(UserManagerTest, PrintBMIStatusAttention) {
    User u("Darya", 18, 100.0, 170.0, "woman", 3);
    BodyMetricsManager bm;
    bm.addMetrics(BodyMetrics("2025-11-07", 100.0, 170.0, 90.0, 100.0));
    UserManager manager(u, bm);

    testing::internal::CaptureStdout();
    manager.printBMIStatus();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("need attention"), string::npos);
}

