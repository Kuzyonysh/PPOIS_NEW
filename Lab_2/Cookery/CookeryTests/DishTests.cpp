#include <gtest/gtest.h>
#include <sstream>
#include "D:\Projects\Cookery\Cookery\Dish.h"
#include "D:\Projects\Cookery\Cookery\Category.h"
#include "D:\Projects\Cookery\Cookery\DishManager.h"
#include "D:\Projects\Cookery\Cookery\ConsoleDishPrinter.h"

TEST(CategoryTest, ConstructorSetsValues) {
    Category c("Main", "Main course");
    EXPECT_EQ(c.getName(), "Main");
    EXPECT_EQ(c.getDescription(), "Main course");
    EXPECT_EQ(c.getCuisineType(), "Unknown");
    EXPECT_EQ(c.getPopularityLevel(), 0);
    EXPECT_FALSE(c.isVegetarian());
    EXPECT_EQ(c.getRecommendedDishCount(), 0);
}

TEST(DishTest, ConstructorSetsValues) {
    Category c("Main", "Main course");
    Dish d("Steak", 500, c);
    EXPECT_EQ(d.getName(), "Steak");
    EXPECT_EQ(d.getCalories(), 500);
    EXPECT_EQ(d.getCategoryName(), "Main");
    EXPECT_EQ(d.getDescription(), "");
    EXPECT_EQ(d.getPrice(), 0);
    EXPECT_EQ(d.getSpicyLevel(), 0);
    EXPECT_FALSE(d.getIsVegetarian());
    EXPECT_EQ(d.getPreparationTime(), 0);
}

TEST(DishTest, SettersWorkCorrectly) {
    Category c("Main", "Main course");
    Dish d("Steak", 500, c);
    d.setCalories(600);
    d.setDescription("Juicy grilled steak");
    d.setPrice(25);
    d.setSpicyLevel(2);
    d.setIsVegetarian(true);
    d.setPreparationTime(20);

    EXPECT_EQ(d.getCalories(), 600);
    EXPECT_EQ(d.getDescription(), "Juicy grilled steak");
    EXPECT_EQ(d.getPrice(), 25);
    EXPECT_EQ(d.getSpicyLevel(), 2);
    EXPECT_TRUE(d.getIsVegetarian());
    EXPECT_EQ(d.getPreparationTime(), 20);
}

TEST(DishManagerTest, AddDishOutputsMessage) {
    Category c("Dessert", "Sweet");
    Dish d("Cake", 300, c);
    DishManager mgr;

    std::ostringstream oss;
    std::streambuf* oldCout = std::cout.rdbuf(oss.rdbuf());
    mgr.addDish(d);
    std::cout.rdbuf(oldCout);

    std::string output = oss.str();
    EXPECT_NE(output.find("Dish 'Cake' has been added to the menu."), std::string::npos);
}

TEST(DishManagerTest, RemoveDishOutputsMessage) {
    DishManager mgr;

    std::ostringstream oss;
    std::streambuf* oldCout = std::cout.rdbuf(oss.rdbuf());
    mgr.removeDish("Pizza");
    std::cout.rdbuf(oldCout);

    std::string output = oss.str();
    EXPECT_NE(output.find("Dish 'Pizza' has been removed from the menu."), std::string::npos);
}

TEST(DishManagerTest, FindDishOutputsMessage) {
    DishManager mgr;

    std::ostringstream oss;
    std::streambuf* oldCout = std::cout.rdbuf(oss.rdbuf());
    mgr.findDish("Burger");
    std::cout.rdbuf(oldCout);

    std::string output = oss.str();
    EXPECT_NE(output.find("Searching for dish: Burger"), std::string::npos);
    EXPECT_NE(output.find("Dish found successfully!"), std::string::npos);
}

TEST(ConsoleDishPrinterTest, PrintOutputsAllFields) {
    Category c("Appetizer", "Starter");
    Dish d("Salad", 150, c);
    d.setDescription("Fresh garden salad");
    d.setPrice(10);
    d.setSpicyLevel(1);
    d.setIsVegetarian(true);
    d.setPreparationTime(5);

    ConsoleDishPrinter printer;

    std::ostringstream oss;
    std::streambuf* oldCout = std::cout.rdbuf(oss.rdbuf());
    printer.print(d);
    std::cout.rdbuf(oldCout);

    std::string output = oss.str();
    EXPECT_NE(output.find("Dish: Salad"), std::string::npos);
    EXPECT_NE(output.find("Calories: 150"), std::string::npos);
    EXPECT_NE(output.find("Category: Appetizer"), std::string::npos);
    EXPECT_NE(output.find("Description: Fresh garden salad"), std::string::npos);
    EXPECT_NE(output.find("Price: 10"), std::string::npos);
    EXPECT_NE(output.find("Spicy level: 1"), std::string::npos);
    EXPECT_NE(output.find("Vegetarian: Yes"), std::string::npos);
    EXPECT_NE(output.find("Preparation time: 5"), std::string::npos);
}

TEST(DishTest, VegetarianDish) {
    Category c("Salad", "Healthy");
    Dish d("Vegan Salad", 120, c);
    d.setIsVegetarian(true);
    EXPECT_TRUE(d.getIsVegetarian());
}

TEST(DishTest, NonVegetarianDish) {
    Category c("Meat", "Protein");
    Dish d("Chicken Wings", 400, c);
    EXPECT_FALSE(d.getIsVegetarian());
}

TEST(DishTest, CategoryNameMatches) {
    Category c("Soup", "Hot soup");
    Dish d("Tomato Soup", 200, c);
    EXPECT_EQ(d.getCategoryName(), "Soup");
}

TEST(DishTest, PreparationTimeSetter) {
    Category c("Main", "Main course");
    Dish d("Pasta", 350, c);
    d.setPreparationTime(15);
    EXPECT_EQ(d.getPreparationTime(), 15);
}

TEST(DishTest, PriceSetter) {
    Category c("Dessert", "Sweet");
    Dish d("Pie", 250, c);
    d.setPrice(8);
    EXPECT_EQ(d.getPrice(), 8);
}

TEST(DishTest, SpicyLevelSetter) {
    Category c("Main", "Spicy");
    Dish d("Curry", 500, c);
    d.setSpicyLevel(3);
    EXPECT_EQ(d.getSpicyLevel(), 3);
}

TEST(DishTest, CaloriesSetter) {
    Category c("Snack", "Light");
    Dish d("Fries", 300, c);
    d.setCalories(350);
    EXPECT_EQ(d.getCalories(), 350);
}
