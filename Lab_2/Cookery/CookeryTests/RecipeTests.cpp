#include <gtest/gtest.h>
#include <sstream>
#include <string>
#include "D:\Projects\Cookery\Cookery\Recipe.h"
#include "D:\Projects\Cookery\Cookery\RecipeManager.h"
#include "D:\Projects\Cookery\Cookery\ConsoleRecipePrinter.h"
#include "D:\Projects\Cookery\Cookery\Ingredient.h"
#include "D:\Projects\Cookery\Cookery\Exceptions.h"

TEST(RecipeTest, ConstructorSetsInitialValues) {
    Recipe r("Pasta", "Boil water, add pasta", 10);
    EXPECT_EQ(r.getName(), "Pasta");
    EXPECT_EQ(r.getInstruction(), "Boil water, add pasta");
    EXPECT_EQ(r.getCookingTime(), 10);
    EXPECT_EQ(r.getIngredients().size(), 0);
    EXPECT_FALSE(r.getIsVegetarian());
}

TEST(RecipeTest, SettersAndGettersWorkCorrectly) {
    Recipe r("Salad", "Mix veggies", 5);
    r.setCuisineType("Italian");
    r.setDifficultyLevel("Easy");
    r.setServings(2);
    r.setChefName("John");
    r.setNotes("Fresh only");
    r.setVegetarian(true);

    EXPECT_EQ(r.getCuisineType(), "Italian");
    EXPECT_EQ(r.getDifficultyLevel(), "Easy");
    EXPECT_EQ(r.getServings(), 2);
    EXPECT_EQ(r.getChefName(), "John");
    EXPECT_EQ(r.getNotes(), "Fresh only");
    EXPECT_TRUE(r.getIsVegetarian());
}

TEST(RecipeTest, AddIngredientInternalAddsIngredient) {
    Recipe r("Soup", "Boil water", 15);
    Ingredient i("Carrot", 2.0, "pcs");
    r.addIngredientInternal(i);

    ASSERT_EQ(r.getIngredients().size(), 1);
    EXPECT_EQ(r.getIngredients()[0].getName(), "Carrot");
}

TEST(RecipeManagerTest, AddIngredientAddsNewIngredient) {
    Recipe r("Cake", "Bake", 30);
    RecipeManager mgr;
    Ingredient i("Flour", 500.0, "g");

    EXPECT_NO_THROW(mgr.addIngredient(r, i));
    ASSERT_EQ(r.getIngredients().size(), 1);
    EXPECT_EQ(r.getIngredients()[0].getName(), "Flour");
}

TEST(RecipeManagerTest, AddIngredientThrowsOnDuplicate) {
    Recipe r("Cake", "Bake", 30);
    RecipeManager mgr;
    Ingredient i("Sugar", 100.0, "g");
    mgr.addIngredient(r, i);

    EXPECT_THROW(mgr.addIngredient(r, i), DuplicateDishException);
}

TEST(RecipeManagerTest, CookOutputsMessage) {
    Recipe r("Tea", "Boil water", 5);
    RecipeManager mgr;

    std::ostringstream oss;
    std::streambuf* oldCout = std::cout.rdbuf(oss.rdbuf());

    mgr.cook(r);

    std::cout.rdbuf(oldCout);
    EXPECT_NE(oss.str().find("Cooking Tea ... Done!"), std::string::npos);
}

TEST(RecipeManagerTest, RemoveRecipeOutputsMessage) {
    RecipeManager mgr;
    std::ostringstream oss;
    std::streambuf* oldCout = std::cout.rdbuf(oss.rdbuf());

    mgr.removeRecipe("Pizza");

    std::cout.rdbuf(oldCout);
    EXPECT_NE(oss.str().find("Recipe 'Pizza' has been removed"), std::string::npos);
}

TEST(RecipeManagerTest, FindRecipeOutputsMessage) {
    RecipeManager mgr;
    std::ostringstream oss;
    std::streambuf* oldCout = std::cout.rdbuf(oss.rdbuf());

    mgr.findRecipe("Burger");

    std::cout.rdbuf(oldCout);
    EXPECT_NE(oss.str().find("Recipe found successfully"), std::string::npos);
}

TEST(ConsoleRecipePrinterTest, PrintOutputsRecipeDetails) {
    Recipe r("Pancake", "Mix and fry", 15);
    r.addIngredientInternal(Ingredient("Flour", 200.0, "g"));
    r.addIngredientInternal(Ingredient("Eggs", 2.0, "pcs"));

    ConsoleRecipePrinter printer;

    std::ostringstream oss;
    std::streambuf* oldCout = std::cout.rdbuf(oss.rdbuf());

    printer.print(r);

    std::cout.rdbuf(oldCout);
    std::string output = oss.str();

    EXPECT_NE(output.find("Pancake"), std::string::npos);
    EXPECT_NE(output.find("Cooking time: 15"), std::string::npos);
    EXPECT_NE(output.find(" - Flour"), std::string::npos);
    EXPECT_NE(output.find(" - Eggs"), std::string::npos);
    EXPECT_NE(output.find("Mix and fry"), std::string::npos);
}

TEST(ConsoleRecipePrinterTest, PrintWithNoIngredients) {
    Recipe r("Tea", "Boil water", 5);
    ConsoleRecipePrinter printer;

    std::ostringstream oss;
    std::streambuf* oldCout = std::cout.rdbuf(oss.rdbuf());

    printer.print(r);

    std::cout.rdbuf(oldCout);
    std::string output = oss.str();

    EXPECT_NE(output.find("Ingredients:"), std::string::npos);
}
