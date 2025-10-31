#include <gtest/gtest.h>
#include "D:\Projects\Cookery\Cookery\Order.h"
#include "D:\Projects\Cookery\Cookery\OrderManager.h"
#include "D:\Projects\Cookery\Cookery\ConsoleOrderPrinter.h"
#include "D:\Projects\Cookery\Cookery\Customer.h"
#include "D:\Projects\Cookery\Cookery\Dish.h"
#include "D:\Projects\Cookery\Cookery\Category.h"
#include <sstream>
#include <iostream>

TEST(OrderTest, ConstructorSetsValues) {
    Customer c("John Doe");
    Order order(c, 30);

    EXPECT_EQ(order.getClient().getName(), "John Doe");
    EXPECT_EQ(order.getOrderTime(), 30);
    EXPECT_EQ(order.getStatus(), "pending");
    EXPECT_TRUE(order.getDishes().empty());
    EXPECT_EQ(order.getDeliveryAddress(), "");
    EXPECT_EQ(order.getPaymentMethod(), "");
    EXPECT_EQ(order.getComment(), "");
    EXPECT_TRUE(order.isReadyToServe() == false); 
}

TEST(OrderTest, AddDishAndCheckReady) {
    Category catMain("Main", "Main course");
    Dish dish("Steak", 600, catMain);

    Customer c("Alice");
    Order order(c, 20);

    EXPECT_FALSE(order.isReadyToServe());
    order.addOrder(dish);
    EXPECT_TRUE(order.isReadyToServe());
    EXPECT_EQ(order.getDishes().size(), 1);
    EXPECT_EQ(order.getDishes()[0].getName(), "Steak");
}

TEST(OrderTest, SettersUpdateValues) {
    Customer c("Bob");
    Order order(c, 15);

    order.setStatus("processing");
    order.setDeliveryAddress("123 Street");
    order.setPaymentMethod("Card");
    order.setComment("No onions");

    EXPECT_EQ(order.getStatus(), "processing");
    EXPECT_EQ(order.getDeliveryAddress(), "123 Street");
    EXPECT_EQ(order.getPaymentMethod(), "Card");
    EXPECT_EQ(order.getComment(), "No onions");
}

TEST(OrderManagerTest, ManageOrder) {
    Customer c("Eve");
    Category cat("Main", "Main course");
    Dish dish("Burger", 500, cat);

    Order order(c, 25);
    OrderManager manager;

    manager.addDishToOrder(order, dish);
    EXPECT_EQ(order.getDishes().size(), 1);
    EXPECT_EQ(manager.getTotalCalories(order), 500);

    manager.markAsServed(order);
    EXPECT_EQ(order.getStatus(), "served");

    manager.cancelOrder(order);
    EXPECT_EQ(order.getStatus(), "cancelled");

    manager.updateDeliveryAddress(order, "456 Avenue");
    EXPECT_EQ(order.getDeliveryAddress(), "456 Avenue");

    manager.updatePaymentMethod(order, "Cash");
    EXPECT_EQ(order.getPaymentMethod(), "Cash");

    manager.addComment(order, "Extra ketchup");
    EXPECT_EQ(order.getComment(), "Extra ketchup");
}

TEST(ConsoleOrderPrinterTest, PrintsOrder) {
    Customer c("Charlie");
    Category cat("Dessert", "Sweet");
    Dish dish("Cake", 350, cat);

    Order order(c, 10);
    order.addOrder(dish);
    order.setDeliveryAddress("789 Road");
    order.setPaymentMethod("Card");
    order.setComment("Gluten free");

    ConsoleOrderPrinter printer;

    std::ostringstream out;
    std::streambuf* oldCout = std::cout.rdbuf(out.rdbuf());

    printer.print(order);

    std::cout.rdbuf(oldCout);
    std::string output = out.str();

    EXPECT_NE(output.find("Customer: Charlie"), std::string::npos);
    EXPECT_NE(output.find("Order time: 10"), std::string::npos);
    EXPECT_NE(output.find("Dishes:"), std::string::npos);
    EXPECT_NE(output.find("Cake"), std::string::npos);
    EXPECT_NE(output.find("350"), std::string::npos);
    EXPECT_NE(output.find("Delivery address: 789 Road"), std::string::npos);
    EXPECT_NE(output.find("Payment method: Card"), std::string::npos);
    EXPECT_NE(output.find("Comment: Gluten free"), std::string::npos);
}

TEST(ConsoleOrderPrinterTest, PrintsEmptyOrder) {
    Customer c("Dana");
    Order order(c, 5);

    ConsoleOrderPrinter printer;

    std::ostringstream out;
    std::streambuf* oldCout = std::cout.rdbuf(out.rdbuf());

    printer.print(order);

    std::cout.rdbuf(oldCout);
    std::string output = out.str();

    EXPECT_NE(output.find("Customer: Dana"), std::string::npos);
    EXPECT_NE(output.find("No dishes in this order."), std::string::npos);
}
