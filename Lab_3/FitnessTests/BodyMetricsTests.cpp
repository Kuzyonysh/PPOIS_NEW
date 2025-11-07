#include "gtest/gtest.h"
#include "BodyMetrics.h"
#include "BodyMetricsManager.h"
#include "Exception.h"

TEST(BodyMetricsTests, ConstructorAndGettersWork) {
    BodyMetrics bm("2025-11-07", 60.5, 170.0, 70.0, 95.0);
    EXPECT_EQ(bm.getDate(), "2025-11-07");
    EXPECT_DOUBLE_EQ(bm.getWeight(), 60.5);
    EXPECT_DOUBLE_EQ(bm.getHeight(), 170.0);
    EXPECT_DOUBLE_EQ(bm.getWaist(), 70.0);
    EXPECT_DOUBLE_EQ(bm.getHips(), 95.0);
}

TEST(BodyMetricsTests, SettersChangeValues) {
    BodyMetrics bm("2025-11-07", 60, 170, 70, 95);
    bm.setDate("2025-11-08");
    bm.setWeight(61.2);
    bm.setHeight(171.3);
    bm.setWaist(72);
    bm.setHips(96);

    EXPECT_EQ(bm.getDate(), "2025-11-08");
    EXPECT_DOUBLE_EQ(bm.getWeight(), 61.2);
    EXPECT_DOUBLE_EQ(bm.getHeight(), 171.3);
    EXPECT_DOUBLE_EQ(bm.getWaist(), 72);
    EXPECT_DOUBLE_EQ(bm.getHips(), 96);
}

TEST(BodyMetricsManagerTests, AddMetricsAddsRecord) {
    BodyMetricsManager mgr;
    mgr.addMetrics(BodyMetrics("2025-11-07", 60, 170, 70, 90));

    EXPECT_NO_THROW(mgr.getLatestMetrics());
    EXPECT_DOUBLE_EQ(mgr.getLatestMetrics().getWeight(), 60);
}

TEST(BodyMetricsManagerTests, GetLatestMetricsThrowsIfEmpty) {
    BodyMetricsManager mgr;
    EXPECT_THROW(mgr.getLatestMetrics(), InvalidBodyMetricsException);
}

TEST(BodyMetricsManagerTests, GetBMIWorksCorrectly) {
    BodyMetricsManager mgr;
    mgr.addMetrics(BodyMetrics("2025-11-07", 60, 170, 70, 90));

    double bmi = mgr.getBMI();
    EXPECT_NEAR(bmi, 20.76, 0.1);
}

TEST(BodyMetricsManagerTests, GetBMIThrowsOnInvalidHeightWeight) {
    BodyMetricsManager mgr;
    mgr.addMetrics(BodyMetrics("2025-11-07", 0, 0, 0, 0));
    EXPECT_THROW(mgr.getBMI(), InvalidHeightWeightException);
}

TEST(BodyMetricsManagerTests, MultipleRecordsReturnsLastOne) {
    BodyMetricsManager mgr;
    mgr.addMetrics(BodyMetrics("2025-11-06", 58, 170, 70, 90));
    mgr.addMetrics(BodyMetrics("2025-11-07", 59, 171, 71, 91));

    BodyMetrics latest = mgr.getLatestMetrics();
    EXPECT_EQ(latest.getDate(), "2025-11-07");
    EXPECT_DOUBLE_EQ(latest.getWeight(), 59);
}

TEST(BodyMetricsManagerTests, ResetRecordsClearsData) {
    BodyMetricsManager mgr;
    mgr.addMetrics(BodyMetrics("2025-11-07", 60, 170, 70, 90));
    mgr.resetRecords();
    EXPECT_THROW(mgr.getLatestMetrics(), InvalidBodyMetricsException);
}

TEST(BodyMetricsManagerTests, BMI_LowCategoryMessage) {
    BodyMetricsManager mgr;
    mgr.addMetrics(BodyMetrics("2025-11-07", 45, 170, 60, 85));
    EXPECT_NO_THROW(mgr.notifyBMIStatus());
}

TEST(BodyMetricsManagerTests, BMI_NormalCategoryMessage) {
    BodyMetricsManager mgr;
    mgr.addMetrics(BodyMetrics("2025-11-07", 65, 170, 70, 90));
    EXPECT_NO_THROW(mgr.notifyBMIStatus());
}

TEST(BodyMetricsManagerTests, BMI_HighCategoryMessage) {
    BodyMetricsManager mgr;
    mgr.addMetrics(BodyMetrics("2025-11-07", 90, 170, 80, 100));
    EXPECT_NO_THROW(mgr.notifyBMIStatus());
}

TEST(BodyMetricsManagerTests, PrintLatestWeightWorks) {
    BodyMetricsManager mgr;
    mgr.addMetrics(BodyMetrics("2025-11-07", 61, 171, 71, 91));
    EXPECT_NO_THROW(mgr.printLatestWeight());
}

TEST(BodyMetricsManagerTests, PrintLatestHeightWorks) {
    BodyMetricsManager mgr;
    mgr.addMetrics(BodyMetrics("2025-11-07", 61, 171, 71, 91));
    EXPECT_NO_THROW(mgr.printLatestHeight());
}

TEST(BodyMetricsManagerTests, ShowAllRecordsWorks) {
    BodyMetricsManager mgr;
    mgr.addMetrics(BodyMetrics("2025-11-07", 61, 171, 71, 91));
    EXPECT_NO_THROW(mgr.showAllRecords());
}

TEST(BodyMetricsManagerTests, AddMultipleMetricsDoesNotThrow) {
    BodyMetricsManager mgr;
    EXPECT_NO_THROW({
        for (int i = 0; i < 5; ++i)
            mgr.addMetrics(BodyMetrics("2025-11-" + to_string(7 + i), 60 + i, 170 + i, 70 + i, 90 + i));
        });
}
