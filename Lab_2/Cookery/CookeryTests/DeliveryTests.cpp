#include <gtest/gtest.h>
#include <sstream>
#include "D:\Projects\Cookery\Cookery\Delivery.h"
#include "D:\Projects\Cookery\Cookery\DeliveryCalculator.h"
#include "D:\Projects\Cookery\Cookery\ConsoleDeliveryPrinter.h"

TEST(DeliveryTest, ConstructorSetsValues) {
    Delivery d(10, 5, 20, 2, "Pending");
    EXPECT_EQ(d.getDistance(), 10);
    EXPECT_EQ(d.getWeight(), 5);
    EXPECT_EQ(d.getSpeed(), 20);
    EXPECT_EQ(d.getBaseRate(), 2);
    EXPECT_EQ(d.getStatus(), "Pending");
}

TEST(DeliveryTest, SetStatusChangesStatus) {
    Delivery d(10, 5, 20, 2, "Pending");
    d.setStatus("Delivered");
    EXPECT_EQ(d.getStatus(), "Delivered");
}

TEST(DeliveryCalculatorTest, CalculateTimeNormal) {
    Delivery d(100, 10, 50, 2, "Pending");
    DeliveryCalculator calc;
    double time = calc.calculateTime(d);
    EXPECT_DOUBLE_EQ(time, 2.0);
}

TEST(DeliveryCalculatorTest, CalculateTimeZeroSpeed) {
    Delivery d(100, 10, 0, 2, "Pending");
    DeliveryCalculator calc;
    double time = calc.calculateTime(d);
    EXPECT_DOUBLE_EQ(time, 0.0);
}

TEST(DeliveryCalculatorTest, CalculateCost) {
    Delivery d(50, 10, 25, 3, "Pending");
    DeliveryCalculator calc;
    double cost = calc.calculateCost(d);
    EXPECT_DOUBLE_EQ(cost, 150);
}

TEST(DeliveryCalculatorTest, EstimateDelayPositive) {
    Delivery d(100, 10, 20, 2, "Pending");
    DeliveryCalculator calc;
    double delay = calc.estimateDelay(d, 25);
    EXPECT_DOUBLE_EQ(delay, 20.0);
}

TEST(DeliveryCalculatorTest, IsPriorityTrue) {
    Delivery d(100, 15, 25, 2, "Pending");
    DeliveryCalculator calc;
    EXPECT_TRUE(calc.isPriority(d, 10));
}

TEST(DeliveryCalculatorTest, IsPriorityFalse) {
    Delivery d(100, 5, 25, 2, "Pending");
    DeliveryCalculator calc;
    EXPECT_FALSE(calc.isPriority(d, 10));
}

TEST(DeliveryCalculatorTest, CalculateCostWithWeight) {
    Delivery d(50, 10, 25, 3, "Pending");
    DeliveryCalculator calc;
    double cost = calc.calculateCostWithWeight(d, 5);
    EXPECT_DOUBLE_EQ(cost, 50 * 3 + 10 * 5);
}

TEST(DeliveryCalculatorTest, CanDeliverTrue) {
    Delivery d(50, 10, 25, 3, "Pending");
    DeliveryCalculator calc;
    EXPECT_TRUE(calc.canDeliver(d, 60));
}

TEST(DeliveryCalculatorTest, CanDeliverFalse) {
    Delivery d(50, 10, 25, 3, "Pending");
    DeliveryCalculator calc;
    EXPECT_FALSE(calc.canDeliver(d, 40));
}

TEST(DeliveryCalculatorTest, AverageDeliveryTime) {
    Delivery d1(100, 10, 50, 2, "Pending");
    Delivery d2(50, 5, 25, 2, "Pending");
    vector<IDelivery*> deliveries = { &d1, &d2 };
    DeliveryCalculator calc;
    double avg = calc.averageDeliveryTime(deliveries);
    EXPECT_DOUBLE_EQ(avg, (2.0 + 2.0) / 2);
}

TEST(ConsoleDeliveryPrinterTest, PrintOutputsAllFields) {
    Delivery d(100, 10, 50, 2, "Pending");
    DeliveryCalculator calc;
    ConsoleDeliveryPrinter printer(calc);

    std::ostringstream oss;
    std::streambuf* oldCout = std::cout.rdbuf(oss.rdbuf());
    printer.print(d);
    std::cout.rdbuf(oldCout);

    std::string output = oss.str();
    EXPECT_NE(output.find("Distance: 100"), std::string::npos);
    EXPECT_NE(output.find("Weight: 10"), std::string::npos);
    EXPECT_NE(output.find("Speed: 50"), std::string::npos);
    EXPECT_NE(output.find("Base rate: 2"), std::string::npos);
    EXPECT_NE(output.find("Status: Pending"), std::string::npos);
}

TEST(ConsoleDeliveryPrinterTest, PrintAllOutputsMultipleDeliveries) {
    Delivery d1(100, 10, 50, 2, "Pending");
    Delivery d2(50, 5, 25, 3, "In Transit");
    vector<IDelivery*> deliveries = { &d1, &d2 };
    DeliveryCalculator calc;
    ConsoleDeliveryPrinter printer(calc);

    std::ostringstream oss;
    std::streambuf* oldCout = std::cout.rdbuf(oss.rdbuf());
    printer.printAll(deliveries);
    std::cout.rdbuf(oldCout);

    std::string output = oss.str();
    EXPECT_NE(output.find("Distance: 100"), std::string::npos);
    EXPECT_NE(output.find("Distance: 50"), std::string::npos);
    EXPECT_NE(output.find("Status: In Transit"), std::string::npos);
}
