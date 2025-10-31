#include <gtest/gtest.h>
#include "D:\Projects\Cookery\Cookery\Ingredient.h"
#include "D:\Projects\Cookery\Cookery\IngredientManager.h"

TEST(IngredientTest, ConstructorSetsValues) {
    Ingredient ing("Tomato", 5.0, "kg");
    EXPECT_EQ(ing.getName(), "Tomato");
    EXPECT_DOUBLE_EQ(ing.getQuantity(), 5.0);
    EXPECT_EQ(ing.getUnit(), "kg");
    EXPECT_EQ(ing.getSupplier(), "");
    EXPECT_EQ(ing.getExpirationDate(), "");
    EXPECT_EQ(ing.getStorageLocation(), "");
    EXPECT_DOUBLE_EQ(ing.getPricePerUnit(), 0);
    EXPECT_EQ(ing.getCategory(), "");
    EXPECT_FALSE(ing.isOrganic());
}

TEST(IngredientTest, SettersWorkCorrectly) {
    Ingredient ing("Tomato", 5.0, "kg");
    ing.setQuantity(10.0);
    ing.setSupplier("Farm");
    ing.setExpirationDate("2025-12-31");
    ing.setStorageLocation("Fridge");
    ing.setPricePerUnit(2.5);
    ing.setCategory("Vegetable");
    ing.setOrganic(true);

    EXPECT_DOUBLE_EQ(ing.getQuantity(), 10.0);
    EXPECT_EQ(ing.getSupplier(), "Farm");
    EXPECT_EQ(ing.getExpirationDate(), "2025-12-31");
    EXPECT_EQ(ing.getStorageLocation(), "Fridge");
    EXPECT_DOUBLE_EQ(ing.getPricePerUnit(), 2.5);
    EXPECT_EQ(ing.getCategory(), "Vegetable");
    EXPECT_TRUE(ing.isOrganic());
}

TEST(IngredientManagerTest, DecreaseReducesQuantity) {
    Ingredient ing("Tomato", 5.0, "kg");
    IngredientManager mgr(ing);
    mgr.decrease(2.0);
    EXPECT_DOUBLE_EQ(ing.getQuantity(), 3.0);
}

TEST(IngredientManagerTest, DecreaseMoreThanQuantitySetsZero) {
    Ingredient ing("Tomato", 5.0, "kg");
    IngredientManager mgr(ing);
    mgr.decrease(10.0);
    EXPECT_DOUBLE_EQ(ing.getQuantity(), 0.0);
}

TEST(IngredientManagerTest, DecreaseNegativeThrows) {
    Ingredient ing("Tomato", 5.0, "kg");
    IngredientManager mgr(ing);
    EXPECT_THROW(mgr.decrease(-1.0), InvalidIngredientAmountException);
}

TEST(IngredientManagerTest, RefillIncreasesQuantity) {
    Ingredient ing("Tomato", 5.0, "kg");
    IngredientManager mgr(ing);
    mgr.refill(3.0);
    EXPECT_DOUBLE_EQ(ing.getQuantity(), 8.0);
}

TEST(IngredientManagerTest, RefillZeroThrows) {
    Ingredient ing("Tomato", 5.0, "kg");
    IngredientManager mgr(ing);
    EXPECT_THROW(mgr.refill(0.0), InvalidIngredientAmountException);
}

TEST(IngredientManagerTest, RefillNegativeThrows) {
    Ingredient ing("Tomato", 5.0, "kg");
    IngredientManager mgr(ing);
    EXPECT_THROW(mgr.refill(-2.0), InvalidIngredientAmountException);
}

TEST(IngredientTest, NameAndUnitAreCorrect) {
    Ingredient ing("Salt", 1.0, "kg");
    EXPECT_EQ(ing.getName(), "Salt");
    EXPECT_EQ(ing.getUnit(), "kg");
}

TEST(IngredientTest, PriceAndCategoryDefaults) {
    Ingredient ing("Sugar", 2.0, "kg");
    EXPECT_DOUBLE_EQ(ing.getPricePerUnit(), 0);
    EXPECT_EQ(ing.getCategory(), "");
}

TEST(IngredientTest, OrganicDefaultsToFalse) {
    Ingredient ing("Pepper", 1.0, "kg");
    EXPECT_FALSE(ing.isOrganic());
}

TEST(IngredientManagerTest, DecreaseToExactZero) {
    Ingredient ing("Tomato", 5.0, "kg");
    IngredientManager mgr(ing);
    mgr.decrease(5.0);
    EXPECT_DOUBLE_EQ(ing.getQuantity(), 0.0);
}

TEST(IngredientManagerTest, MultipleRefillAndDecrease) {
    Ingredient ing("Tomato", 5.0, "kg");
    IngredientManager mgr(ing);
    mgr.refill(3.0);
    mgr.decrease(4.0);
    EXPECT_DOUBLE_EQ(ing.getQuantity(), 4.0);
}

TEST(IngredientManagerTest, RefillThenDecreaseMoreThanTotal) {
    Ingredient ing("Tomato", 5.0, "kg");
    IngredientManager mgr(ing);
    mgr.refill(2.0);
    mgr.decrease(10.0);
    EXPECT_DOUBLE_EQ(ing.getQuantity(), 0.0);
}

TEST(IngredientManagerTest, RefillMultipleTimes) {
    Ingredient ing("Tomato", 5.0, "kg");
    IngredientManager mgr(ing);
    mgr.refill(2.0);
    mgr.refill(3.0);
    EXPECT_DOUBLE_EQ(ing.getQuantity(), 10.0);
}
