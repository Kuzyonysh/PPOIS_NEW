#include "gtest/gtest.h"
#include "D:\Projects\Cookery\Cookery\Category.h"
#include "D:\Projects\Cookery\Cookery\ConsoleCategoryPrinter.h"
#include <sstream>
#include <iostream>

using namespace std;

TEST(CategoryTest, ConstructorSetsInitialValues) {
    Category cat("Desserts", "Sweet dishes");

    EXPECT_EQ(cat.getName(), "Desserts");
    EXPECT_EQ(cat.getDescription(), "Sweet dishes");
    EXPECT_EQ(cat.getCuisineType(), "Unknown");
    EXPECT_EQ(cat.getPopularityLevel(), 0);
    EXPECT_FALSE(cat.isVegetarian());
    EXPECT_EQ(cat.getRecommendedDishCount(), 0);
}

TEST(CategoryTest, SettersAndGettersWorkCorrectly) {
    Category cat("Main Course", "Hearty dishes");

    cat.setDescription("Main hot dishes");
    cat.setCuisineType("Italian");
    cat.setPopularityLevel(5);
    cat.setVegetarian(true);
    cat.setRecommendedDishCount(3);

    EXPECT_EQ(cat.getDescription(), "Main hot dishes");
    EXPECT_EQ(cat.getCuisineType(), "Italian");
    EXPECT_EQ(cat.getPopularityLevel(), 5);
    EXPECT_TRUE(cat.isVegetarian());
    EXPECT_EQ(cat.getRecommendedDishCount(), 3);
}

TEST(CategoryTest, MatchesWorksCorrectly) {
    Category cat("Soups", "Warm and liquid dishes");
    EXPECT_TRUE(cat.matches("Soups"));
    EXPECT_FALSE(cat.matches("Desserts"));
}


TEST(ConsoleCategoryPrinterTest, PrintOutputsCorrectText) {
    Category cat("Salads", "Fresh and light");
    cat.setCuisineType("Greek");
    cat.setPopularityLevel(4);
    cat.setVegetarian(true);
    cat.setRecommendedDishCount(2);

    ConsoleCategoryPrinter printer;

    stringstream buffer;
    streambuf* oldCout = cout.rdbuf(buffer.rdbuf());

    printer.print(cat);

  
    cout.rdbuf(oldCout);

    string output = buffer.str();

    EXPECT_NE(output.find("Category: Salads"), string::npos);
    EXPECT_NE(output.find("Description: Fresh and light"), string::npos);
    EXPECT_NE(output.find("Cuisine Type: Greek"), string::npos);
    EXPECT_NE(output.find("Popularity Level: 4"), string::npos);
    EXPECT_NE(output.find("Vegetarian: Yes"), string::npos);
    EXPECT_NE(output.find("Recommended Dish Count: 2"), string::npos);
}
