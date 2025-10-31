#include <gtest/gtest.h>
#include "D:\Projects\Cookery\Cookery\Menu.h"
#include "D:\Projects\Cookery\Cookery\Dish.h"
#include "D:\Projects\Cookery\Cookery\Category.h"
#include "D:\Projects\Cookery\Cookery\ConsoleMenuPrinter.h"
#include <sstream>
#include <iostream>

TEST(MenuTest, ConstructorSetsValues) {
    Menu menu("Lunch Menu", "Daily lunch specials");
    EXPECT_EQ(menu.getName(), "Lunch Menu");
    EXPECT_EQ(menu.getDescription(), "Daily lunch specials");
    EXPECT_DOUBLE_EQ(menu.getAveragePrice(), 0.0);
    EXPECT_TRUE(menu.getDishes().empty());
}

TEST(MenuTest, AddDishAndGetByCategory) {
    Category catMain("Main", "Main courses");
    Category catDessert("Dessert", "Sweet dishes");

    Dish d1("Steak", 600, catMain);
    d1.setPrice(15.0);
    Dish d2("Cake", 350, catDessert);
    d2.setPrice(6.0);

    Menu menu("Lunch Menu", "Daily lunch specials");
    menu.addDish(d1);
    menu.addDish(d2);

    EXPECT_EQ(menu.getDishes().size(), 2);
    EXPECT_TRUE(menu.hasDish("Steak"));
    EXPECT_TRUE(menu.hasDish("Cake"));
    EXPECT_FALSE(menu.hasDish("Soup"));

    auto mains = menu.getByCategory("Main");
    EXPECT_EQ(mains.size(), 1);
    EXPECT_EQ(mains[0].getName(), "Steak");

    auto desserts = menu.getByCategory("Dessert");
    EXPECT_EQ(desserts.size(), 1);
    EXPECT_EQ(desserts[0].getName(), "Cake");
}

TEST(MenuTest, SettersModifyValues) {
    Menu menu;
    menu.setName("Dinner Menu");
    menu.setDescription("Evening specials");
    menu.setAveragePrice(12.5);

    EXPECT_EQ(menu.getName(), "Dinner Menu");
    EXPECT_EQ(menu.getDescription(), "Evening specials");
    EXPECT_DOUBLE_EQ(menu.getAveragePrice(), 12.5);
}

TEST(ConsoleMenuPrinterTest, PrintsMenu) {
    Category catMain("Main", "Main courses");
    Dish d1("Steak", 600, catMain);
    d1.setPrice(15.0);

    Menu menu("Lunch Menu", "Daily lunch specials");
    menu.addDish(d1);
    menu.setAveragePrice(15.0);

    ConsoleMenuPrinter printer;

    std::ostringstream out;
    std::streambuf* oldCout = std::cout.rdbuf(out.rdbuf());

    printer.print(menu);

    std::cout.rdbuf(oldCout);
    std::string output = out.str();

    EXPECT_NE(output.find("Menu: Lunch Menu"), std::string::npos);
    EXPECT_NE(output.find("Description: Daily lunch specials"), std::string::npos);
    EXPECT_NE(output.find("Steak"), std::string::npos);
    EXPECT_NE(output.find("Main"), std::string::npos);
    EXPECT_NE(output.find("600"), std::string::npos);
    EXPECT_NE(output.find("Average price: 15"), std::string::npos);
}

TEST(ConsoleMenuPrinterTest, PrintsEmptyMenu) {
    Menu menu("Empty Menu", "No dishes");
    ConsoleMenuPrinter printer;

    std::ostringstream out;
    std::streambuf* oldCout = std::cout.rdbuf(out.rdbuf());

    printer.print(menu);

    std::cout.rdbuf(oldCout);
    std::string output = out.str();

    EXPECT_NE(output.find("Menu: Empty Menu"), std::string::npos);
    EXPECT_NE(output.find("The menu is empty."), std::string::npos);
}
