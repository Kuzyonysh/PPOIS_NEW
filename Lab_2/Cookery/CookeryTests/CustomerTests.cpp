#include <gtest/gtest.h>
#include <sstream>
#include "D:\Projects\Cookery\Cookery\Customer.h"
#include "D:\Projects\Cookery\Cookery\MakeOrder.h"
#include "D:\Projects\Cookery\Cookery\Dish.h"
#include "D:\Projects\Cookery\Cookery\Category.h"

TEST(CustomerTest, ConstructorSetsValues) {
    Customer c("Alice", "Vegan", "alice@mail.com", "123456", 50, true);
    EXPECT_EQ(c.getName(), "Alice");
    EXPECT_EQ(c.getPreferences(), "Vegan");
    EXPECT_EQ(c.getEmail(), "alice@mail.com");
    EXPECT_EQ(c.getPhone(), "123456");
    EXPECT_EQ(c.getLoyaltyPoints(), 50);
    EXPECT_TRUE(c.isVIP());
    EXPECT_TRUE(c.getOrders().empty());
}

TEST(CustomerTest, SettersWorkCorrectly) {
    Customer c("Bob", "None", "bob@mail.com", "654321", 0, false);
    c.setPreference("Vegetarian");
    c.setEmail("bob123@mail.com");
    c.setPhone("000111");
    c.addLoyaltyPoints(20);
    c.setVIP(true);

    EXPECT_EQ(c.getPreferences(), "Vegetarian");
    EXPECT_EQ(c.getEmail(), "bob123@mail.com");
    EXPECT_EQ(c.getPhone(), "000111");
    EXPECT_EQ(c.getLoyaltyPoints(), 20);
    EXPECT_TRUE(c.isVIP());
}

TEST(CustomerTest, AddOrderAddsDish) {
    Category cat("Dessert", "Sweet");
    Dish dish("Cake", 300, cat);
    Customer c("Charlie", "Sweet tooth", "charlie@mail.com", "555555", 10, false);
    c.addOrder(dish);

    ASSERT_EQ(c.getOrders().size(), 1);
    EXPECT_EQ(c.getOrders()[0].getName(), "Cake");
}

TEST(MakeOrderTest, MakeOrderAddsDishAndPoints) {
    Category cat("Main", "Main course");
    Dish dish("Steak", 600, cat);
    Customer c("David", "Carnivore", "david@mail.com", "777777", 0, false);
    ConsoleMakeOrder order;

    std::ostringstream oss;
    std::streambuf* oldCout = std::cout.rdbuf(oss.rdbuf());

    order.makeOrder(c, dish);

    std::cout.rdbuf(oldCout);
    EXPECT_EQ(c.getOrders().size(), 1);
    EXPECT_EQ(c.getOrders()[0].getName(), "Steak");
    EXPECT_EQ(c.getLoyaltyPoints(), 10);
    std::string output = oss.str();
    EXPECT_NE(output.find("ordered Steak"), std::string::npos);
    EXPECT_NE(output.find("earned 10 loyalty points"), std::string::npos);
}

TEST(CustomerTest, AddMultipleOrders) {
    Category cat1("Starter", "Light");
    Category cat2("Main", "Main course");
    Dish d1("Soup", 150, cat1);
    Dish d2("Pasta", 400, cat2);
    Customer c("Eve", "Healthy", "eve@mail.com", "888888", 5, false);

    c.addOrder(d1);
    c.addOrder(d2);

    EXPECT_EQ(c.getOrders().size(), 2);
    EXPECT_EQ(c.getOrders()[0].getName(), "Soup");
    EXPECT_EQ(c.getOrders()[1].getName(), "Pasta");
}

TEST(CustomerTest, LoyaltyPointsAccumulate) {
    Customer c("Frank", "", "f@mail.com", "999999", 5, false);
    c.addLoyaltyPoints(15);
    c.addLoyaltyPoints(10);
    EXPECT_EQ(c.getLoyaltyPoints(), 30);
}

TEST(CustomerTest, VIPStatusToggle) {
    Customer c("Grace", "", "g@mail.com", "111222", 0, false);
    EXPECT_FALSE(c.isVIP());
    c.setVIP(true);
    EXPECT_TRUE(c.isVIP());
}

TEST(CustomerTest, PreferencesCanBeChanged) {
    Customer c("Hank", "None", "h@mail.com", "333444", 0, false);
    c.setPreference("Gluten-Free");
    EXPECT_EQ(c.getPreferences(), "Gluten-Free");
}

TEST(CustomerTest, EmailAndPhoneChange) {
    Customer c("Ivy", "", "ivy@mail.com", "555666", 0, false);
    c.setEmail("ivy123@mail.com");
    c.setPhone("777888");
    EXPECT_EQ(c.getEmail(), "ivy123@mail.com");
    EXPECT_EQ(c.getPhone(), "777888");
}

TEST(MakeOrderTest, MultipleOrdersUpdatePoints) {
    Category cat("Dessert", "Sweet");
    Dish d1("Pie", 250, cat);
    Dish d2("Ice Cream", 200, cat);
    Customer c("Jack", "", "jack@mail.com", "444555", 0, false);
    ConsoleMakeOrder order;

    order.makeOrder(c, d1);
    order.makeOrder(c, d2);

    EXPECT_EQ(c.getOrders().size(), 2);
    EXPECT_EQ(c.getLoyaltyPoints(), 20);
}

TEST(CustomerTest, OrdersEmptyInitially) {
    Customer c("Kate", "", "k@mail.com", "111333", 0, true);
    EXPECT_TRUE(c.getOrders().empty());
}

TEST(MakeOrderTest, OutputMessageIncludesCustomerName) {
    Category cat("Main", "Main course");
    Dish dish("Burger", 500, cat);
    Customer c("Leo", "", "leo@mail.com", "222333", 0, false);
    ConsoleMakeOrder order;

    std::ostringstream oss;
    std::streambuf* oldCout = std::cout.rdbuf(oss.rdbuf());
    order.makeOrder(c, dish);
    std::cout.rdbuf(oldCout);

    std::string output = oss.str();
    EXPECT_NE(output.find("Customer Leo ordered Burger"), std::string::npos);
}

TEST(CustomerTest, OrdersMaintainInsertionOrder) {
    Category cat("Snack", "Light");
    Dish d1("Fries", 300, cat);
    Dish d2("Nachos", 350, cat);
    Customer c("Mia", "", "mia@mail.com", "666777", 0, false);

    c.addOrder(d1);
    c.addOrder(d2);

    EXPECT_EQ(c.getOrders()[0].getName(), "Fries");
    EXPECT_EQ(c.getOrders()[1].getName(), "Nachos");
}

TEST(CustomerTest, AddingOrdersDoesNotAffectVIP) {
    Category cat("Main", "Main course");
    Dish dish("Pizza", 450, cat);
    Customer c("Nina", "", "nina@mail.com", "888999", 0, true);
    c.addOrder(dish);
    EXPECT_TRUE(c.isVIP());
}

TEST(MakeOrderTest, LoyaltyPointsIncreaseEvenIfVIP) {
    Category cat("Dessert", "Sweet");
    Dish dish("Cupcake", 200, cat);
    Customer c("Oscar", "", "oscar@mail.com", "000111", 0, true);
    ConsoleMakeOrder order;

    order.makeOrder(c, dish);

    EXPECT_EQ(c.getLoyaltyPoints(), 10);
}
