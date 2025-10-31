#include <gtest/gtest.h>
#include "D:\Projects\Cookery\Cookery\Inventory.h"
#include "D:\Projects\Cookery\Cookery\InventoryManager.h"
#include "D:\Projects\Cookery\Cookery\Ingredient.h"

class MockInventory : public IInventory {
private:
    Inventory inv;
public:
    MockInventory(int c) : inv(c) {}
    void addIngredient(const Ingredient& i) override { inv.addIngredient(i); }
    int size() const override { return inv.size(); }
    int getCapacity() const override { return inv.getCapacity(); }
    const std::vector<Ingredient>& getIngredients() const override { return inv.getIngredients(); }
    std::string getName() const override { return inv.getName(); }
    std::string getLocation() const override { return inv.getLocation(); }
    std::string getOwner() const override { return inv.getOwner(); }
    std::string getLastUpdated() const override { return inv.getLastUpdated(); }
};

TEST(InventoryTest, ConstructorSetsValues) {
    Inventory inv(10, "Test Inventory", "Kitchen", "Chef", "Yesterday");
    EXPECT_EQ(inv.getCapacity(), 10);
    EXPECT_EQ(inv.getName(), "Test Inventory");
    EXPECT_EQ(inv.getLocation(), "Kitchen");
    EXPECT_EQ(inv.getOwner(), "Chef");
    EXPECT_EQ(inv.getLastUpdated(), "Yesterday");
    EXPECT_EQ(inv.size(), 0);
}

TEST(InventoryManagerTest, AddIngredientSuccess) {
    MockInventory inv(5);
    InventoryManager mgr(inv);
    Ingredient ing("Tomato", 2, "kg");
    EXPECT_TRUE(mgr.add(ing));
    EXPECT_EQ(inv.size(), 1);
    EXPECT_TRUE(mgr.hasIngredient("Tomato"));
}

TEST(InventoryManagerTest, AddIngredientFullInventory) {
    MockInventory inv(1);
    InventoryManager mgr(inv);
    Ingredient ing1("Tomato", 2, "kg");
    Ingredient ing2("Onion", 1, "kg");
    EXPECT_TRUE(mgr.add(ing1));
    EXPECT_FALSE(mgr.add(ing2));
    EXPECT_EQ(inv.size(), 1);
}

TEST(InventoryManagerTest, IsFullReturnsTrue) {
    MockInventory inv(1);
    InventoryManager mgr(inv);
    Ingredient ing("Tomato", 2, "kg");
    mgr.add(ing);
    EXPECT_TRUE(mgr.isFull());
}

TEST(InventoryManagerTest, IsFullReturnsFalse) {
    MockInventory inv(2);
    InventoryManager mgr(inv);
    EXPECT_FALSE(mgr.isFull());
}

TEST(InventoryManagerTest, FreeSpaceCorrect) {
    MockInventory inv(3);
    InventoryManager mgr(inv);
    Ingredient ing1("Tomato", 2, "kg");
    Ingredient ing2("Onion", 1, "kg");
    mgr.add(ing1);
    mgr.add(ing2);
    EXPECT_EQ(mgr.freeSpace(), 1);
}

TEST(InventoryManagerTest, HasIngredientReturnsTrue) {
    MockInventory inv(5);
    InventoryManager mgr(inv);
    Ingredient ing("Tomato", 2, "kg");
    mgr.add(ing);
    EXPECT_TRUE(mgr.hasIngredient("Tomato"));
}

TEST(InventoryManagerTest, HasIngredientReturnsFalse) {
    MockInventory inv(5);
    InventoryManager mgr(inv);
    EXPECT_FALSE(mgr.hasIngredient("Onion"));
}

TEST(InventoryManagerTest, ClearInventoryCall) {
    MockInventory inv(5);
    InventoryManager mgr(inv);
    EXPECT_NO_THROW(mgr.clearInventory());
}

TEST(InventoryTest, AddMultipleIngredients) {
    Inventory inv(5);
    Ingredient ing1("Tomato", 2, "kg");
    Ingredient ing2("Onion", 1, "kg");
    inv.addIngredient(ing1);
    inv.addIngredient(ing2);
    EXPECT_EQ(inv.size(), 2);
}

TEST(InventoryTest, AddIngredientDoesNotExceedCapacity) {
    Inventory inv(1);
    Ingredient ing1("Tomato", 2, "kg");
    Ingredient ing2("Onion", 1, "kg");
    inv.addIngredient(ing1);
    inv.addIngredient(ing2);
    EXPECT_EQ(inv.size(), 1);
}

TEST(InventoryTest, IngredientsVectorCorrect) {
    Inventory inv(3);
    Ingredient ing("Tomato", 2, "kg");
    inv.addIngredient(ing);
    const auto& ingredients = inv.getIngredients();
    EXPECT_EQ(ingredients.size(), 1);
    EXPECT_EQ(ingredients[0].getName(), "Tomato");
}

TEST(InventoryTest, InventoryNameDefault) {
    Inventory inv(5);
    EXPECT_EQ(inv.getName(), "Main Inventory");
}

TEST(InventoryTest, InventoryLocationDefault) {
    Inventory inv(5);
    EXPECT_EQ(inv.getLocation(), "Kitchen");
}

TEST(InventoryTest, InventoryOwnerDefault) {
    Inventory inv(5);
    EXPECT_EQ(inv.getOwner(), "Chef");
}
