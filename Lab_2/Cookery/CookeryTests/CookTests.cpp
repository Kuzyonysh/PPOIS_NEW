#include <gtest/gtest.h>
#include <sstream>
#include <string>
#include "D:\Projects\Cookery\Cookery\Cook.h"
#include "D:\Projects\Cookery\Cookery\CookManager.h"
#include "D:\Projects\Cookery\Cookery\ConsoleCookPrinter.h"
#include "D:\Projects\Cookery\Cookery\Dish.h"
#include "D:\Projects\Cookery\Cookery\Exceptions.h"


TEST(CookTest, ConstructorSetsDefaults) {
    Cook cook;
    EXPECT_EQ(cook.getName(), "Unknown");
    EXPECT_EQ(cook.getSkillLevel(), 1);
    EXPECT_EQ(cook.getDishes().size(), 0);
    EXPECT_EQ(cook.getExperienceYears(), 0);
    EXPECT_EQ(cook.getSpecialty(), "");
    EXPECT_EQ(cook.getAge(), 0);
    EXPECT_EQ(cook.getAwards(), 0);
    EXPECT_TRUE(cook.getIsAvailable());
}

TEST(CookTest, ConstructorSetsValues) {
    Cook cook("John", 3);
    EXPECT_EQ(cook.getName(), "John");
    EXPECT_EQ(cook.getSkillLevel(), 3);
}

TEST(CookTest, SettersAndGettersWork) {
    Cook cook;
    cook.setName("Anna");
    cook.setSkillLevel(5);
    cook.setExperienceYears(10);
    cook.setSpecialty("Italian");
    cook.setAge(35);
    cook.setAwards(2);
    cook.setIsAvailable(false);

    EXPECT_EQ(cook.getName(), "Anna");
    EXPECT_EQ(cook.getSkillLevel(), 5);
    EXPECT_EQ(cook.getExperienceYears(), 10);
    EXPECT_EQ(cook.getSpecialty(), "Italian");
    EXPECT_EQ(cook.getAge(), 35);
    EXPECT_EQ(cook.getAwards(), 2);
    EXPECT_FALSE(cook.getIsAvailable());
}

TEST(CookTest, AddDishAddsCorrectly) {
    Cook cook;
    Category cat("Main", "Main course dishes");
    Dish dish("Pasta", 500, cat);
    cook.addDish(dish);

    ASSERT_EQ(cook.getDishes().size(), 1);
    EXPECT_EQ(cook.getDishes()[0].getName(), "Pasta");
}

TEST(CookManagerTest, AddDishAddsNewDish) {
    Cook cook("Mary", 2);
    CookManager mgr;
    Category cat("Soup", "Warm starter");
    Dish dish("Soup", 200, cat);

    std::ostringstream oss;
    std::streambuf* oldCout = std::cout.rdbuf(oss.rdbuf());

    EXPECT_NO_THROW(mgr.addDish(cook, dish));

    std::cout.rdbuf(oldCout);
    EXPECT_EQ(cook.getDishes().size(), 1);
    EXPECT_EQ(cook.getDishes()[0].getName(), "Soup");
    EXPECT_NE(oss.str().find("learned to cook: Soup"), std::string::npos);
}

TEST(CookManagerTest, AddDishThrowsOnDuplicate) {
    Cook cook("Sam", 1);
    CookManager mgr;
    Category cat("Salad", "Fresh vegetables");
    Dish dish("Salad", 150, cat);
    mgr.addDish(cook, dish);

    EXPECT_THROW(mgr.addDish(cook, dish), DuplicateDishException);
}

TEST(CookManagerTest, ImproveSkillIncreasesLevel) {
    Cook cook("Leo", 2);
    CookManager mgr;

    std::ostringstream oss;
    std::streambuf* oldCout = std::cout.rdbuf(oss.rdbuf());

    mgr.improveSkill(cook);

    std::cout.rdbuf(oldCout);
    EXPECT_EQ(cook.getSkillLevel(), 3);
    EXPECT_NE(oss.str().find("has improved skill to level 3"), std::string::npos);
}

TEST(CookManagerTest, CanCookOutputsCorrectMessage) {
    Cook cook("Anna", 4);
    Category cat("Pizza", "Cheesy dishes");
    cook.addDish(Dish("Pizza", 300, cat));
    CookManager mgr;

    std::ostringstream oss;
    std::streambuf* oldCout = std::cout.rdbuf(oss.rdbuf());

    mgr.canCook(cook, "Pizza");
    mgr.canCook(cook, "Burger");

    std::cout.rdbuf(oldCout);
    std::string output = oss.str();
    EXPECT_NE(output.find("can cook Pizza"), std::string::npos);
    EXPECT_NE(output.find("cannot cook Burger"), std::string::npos);
}

TEST(CookManagerTest, CookDishOutputsCorrectMessage) {
    Cook cook("Leo", 5);
    Category cat("Steak", "Grilled dishes");
    Dish dish("Steak", 700, cat);
    cook.addDish(dish);
    CookManager mgr;

    std::ostringstream oss;
    std::streambuf* oldCout = std::cout.rdbuf(oss.rdbuf());

    mgr.cookDish(cook, "Steak");

    std::cout.rdbuf(oldCout);
    std::string output = oss.str();
    EXPECT_NE(output.find("is cooking Steak"), std::string::npos);
    EXPECT_NE(output.find("Dish ready! (700 kcal)"), std::string::npos);
}

TEST(CookManagerTest, CookDishThrowsIfNotFound) {
    Cook cook("Tom", 2);
    CookManager mgr;

    EXPECT_THROW(mgr.cookDish(cook, "Burger"), DishNotFoundException);
}

TEST(ConsoleCookPrinterTest, PrintOutputsCookDetails) {
    Cook cook("Emma", 3);
    cook.setExperienceYears(5);
    cook.setSpecialty("Desserts");
    cook.setAge(28);
    cook.setAwards(1);
    cook.setIsAvailable(true);

    ConsoleCookPrinter printer;
    std::ostringstream oss;
    std::streambuf* oldCout = std::cout.rdbuf(oss.rdbuf());

    printer.print(cook);

    std::cout.rdbuf(oldCout);
    std::string output = oss.str();
    EXPECT_NE(output.find("Emma"), std::string::npos);
    EXPECT_NE(output.find("Skill Level: 3"), std::string::npos);
    EXPECT_NE(output.find("Experience: 5 years"), std::string::npos);
    EXPECT_NE(output.find("Specialty: Desserts"), std::string::npos);
    EXPECT_NE(output.find("Age: 28"), std::string::npos);
    EXPECT_NE(output.find("Awards: 1"), std::string::npos);
    EXPECT_NE(output.find("Available: Yes"), std::string::npos);
}

TEST(CookTest, AddMultipleDishes) {
    Cook cook;
    Category cat1("Soup", "Starter"), cat2("Main", "Main course");
    cook.addDish(Dish("Soup", 100, cat1));
    cook.addDish(Dish("Steak", 500, cat2));

    EXPECT_EQ(cook.getDishes().size(), 2);
    EXPECT_EQ(cook.getDishes()[0].getName(), "Soup");
    EXPECT_EQ(cook.getDishes()[1].getName(), "Steak");
}

TEST(CookTest, SetAvailabilityWorks) {
    Cook cook;
    cook.setIsAvailable(false);
    EXPECT_FALSE(cook.getIsAvailable());
}

TEST(CookTest, SetExperienceYearsWorks) {
    Cook cook;
    cook.setExperienceYears(8);
    EXPECT_EQ(cook.getExperienceYears(), 8);
}

TEST(CookTest, SetAgeAndAwardsWorks) {
    Cook cook;
    cook.setAge(40);
    cook.setAwards(3);
    EXPECT_EQ(cook.getAge(), 40);
    EXPECT_EQ(cook.getAwards(), 3);
}
