#include "gtest/gtest.h"
#include "FoodProduct.h"
#include"FoodPrinter.h"
#include "FoodProductManager.h"
#include "Exception.h"
#include <sstream>
#include <iostream>

TEST(FoodProductTest, ConstructorAndGetters) {
    FoodProduct p("Apple", 2.5, "kg", 52);
    EXPECT_EQ(p.getName(), "Apple");
    EXPECT_DOUBLE_EQ(p.getQuantity(), 2.5);
    EXPECT_EQ(p.getUnit(), "kg");
    EXPECT_DOUBLE_EQ(p.getCaloriesPerUnit(), 52);
    EXPECT_DOUBLE_EQ(p.getProtein(), 0);
    EXPECT_DOUBLE_EQ(p.getFat(), 0);
    EXPECT_DOUBLE_EQ(p.getCarbs(), 0);
    EXPECT_TRUE(p.isHealthy());
}

TEST(FoodProductTest, Setters) {
    FoodProduct p("Banana", 1.0, "kg", 89);
    p.setQuantity(3.0);
    p.setCaloriesPerUnit(95);
    p.setProtein(1.2);
    p.setFat(0.3);
    p.setCarbs(27);
    p.setHealthy(false);

    EXPECT_DOUBLE_EQ(p.getQuantity(), 3.0);
    EXPECT_DOUBLE_EQ(p.getCaloriesPerUnit(), 95);
    EXPECT_DOUBLE_EQ(p.getProtein(), 1.2);
    EXPECT_DOUBLE_EQ(p.getFat(), 0.3);
    EXPECT_DOUBLE_EQ(p.getCarbs(), 27);
    EXPECT_FALSE(p.isHealthy());
}

TEST(FoodProductManagerTest, ConsumeNormal) {
    FoodProduct p("Milk", 2.0, "L", 60);
    FoodProductManager m(p);
    m.consume(1.0);
    EXPECT_DOUBLE_EQ(p.getQuantity(), 1.0);
}

TEST(FoodProductManagerTest, ConsumeTooMuch) {
    FoodProduct p("Milk", 1.0, "L", 60);
    FoodProductManager m(p);
    testing::internal::CaptureStdout();
    m.consume(2.0);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(p.getQuantity(), 0);
    EXPECT_NE(output.find("Not enough Milk left."), std::string::npos);
}

TEST(FoodProductManagerTest, ConsumeNegativeThrows) {
    FoodProduct p("Milk", 1.0, "L", 60);
    FoodProductManager m(p);
    EXPECT_THROW(m.consume(-1.0), InvalidIngredientAmountException);
}

TEST(FoodProductManagerTest, RefillNormal) {
    FoodProduct p("Milk", 1.0, "L", 60);
    FoodProductManager m(p);
    testing::internal::CaptureStdout();
    m.refill(2.0);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_DOUBLE_EQ(p.getQuantity(), 3.0);
    EXPECT_NE(output.find("Added 2"), std::string::npos);
}

TEST(FoodProductManagerTest, RefillNegativeThrows) {
    FoodProduct p("Milk", 1.0, "L", 60);
    FoodProductManager m(p);
    EXPECT_THROW(m.refill(-1.0), InvalidIngredientAmountException);
}

TEST(FoodProductManagerTest, IsLowStockTrue) {
    FoodProduct p("Sugar", 0.5, "kg", 400);
    FoodProductManager m(p);
    EXPECT_TRUE(m.isLowStock(1.0));
}

TEST(FoodProductManagerTest, IsLowStockFalse) {
    FoodProduct p("Sugar", 2.0, "kg", 400);
    FoodProductManager m(p);
    EXPECT_FALSE(m.isLowStock(1.0));
}

TEST(FoodProductManagerTest, CalculateTotalCalories) {
    FoodProduct p("Bread", 0.2, "kg", 250);
    FoodProductManager m(p);
    EXPECT_DOUBLE_EQ(m.calculateTotalCalories(), 50.0);
}

TEST(FoodProductManagerTest, GetCaloriesForAmountNormal) {
    FoodProduct p("Bread", 1.0, "kg", 250);
    FoodProductManager m(p);
    EXPECT_DOUBLE_EQ(m.getCaloriesForAmount(0.5), 125.0);
}

TEST(FoodProductManagerTest, GetCaloriesForAmountNegativeThrows) {
    FoodProduct p("Bread", 1.0, "kg", 250);
    FoodProductManager m(p);
    EXPECT_THROW(m.getCaloriesForAmount(-0.1), InvalidIngredientAmountException);
}

TEST(FoodProductManagerTest, EstimateDaysLeftNormal) {
    FoodProduct p("Rice", 5.0, "kg", 130);
    FoodProductManager m(p);
    EXPECT_DOUBLE_EQ(m.estimateDaysLeft(1.0), 5.0);
}

TEST(FoodProductManagerTest, EstimateDaysLeftZeroThrows) {
    FoodProduct p("Rice", 5.0, "kg", 130);
    FoodProductManager m(p);
    EXPECT_THROW(m.estimateDaysLeft(0), InvalidIngredientAmountException);
}

TEST(FoodPrinterTest, PrintOutput) {
    FoodProduct p("Carrot", 1.0, "kg", 41);
    p.setProtein(0.9);
    p.setFat(0.2);
    p.setCarbs(10);
    p.setHealthy(true);
    FoodPrinter printer;
    testing::internal::CaptureStdout();
    printer.print(p);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Food: Carrot"), std::string::npos);
    EXPECT_NE(output.find("Macros (P/F/C): 0.9/0.2/10"), std::string::npos);
    EXPECT_NE(output.find("Healthy choice"), std::string::npos);
}
