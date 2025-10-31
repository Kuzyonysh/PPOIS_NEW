#include <gtest/gtest.h>
#include "D:\Projects\Cookery\Cookery\Fridge.h"
#include "D:\Projects\Cookery\Cookery\FridgeManager.h"
#include "D:\Projects\Cookery\Cookery\ITemperatureSensor.h"
#include "D:\Projects\Cookery\Cookery\Ingredient.h"
#include "D:\Projects\Cookery\Cookery\Inventory.h"

class MockSensor : public ITemperatureSensor {
private:
    double temp;
public:
    MockSensor() : temp(0) {}

    void setCurrentTemperature(double t) override { temp = t; }
    double getCurrentTemperature() const override { return temp; }

    double getMinSafe() const override { return 0; } 
    double getMaxSafe() const override { return 10; } 
    string getSensorLocation() const override { return "MockLocation"; }
    string getSensorType() const override { return "MockType"; }
};

TEST(FridgeTest, ConstructorSetsValues) {
    Inventory inv(10, "FridgeInventory", "Kitchen", "Chef", "2025-10-30");
    Fridge fridge(5.0, 10, inv, "Off");
    EXPECT_EQ(fridge.getTemperature(), 5.0);
    EXPECT_EQ(fridge.getState(), "Off");
    EXPECT_EQ(fridge.getMaxCapacity(), 10);
    EXPECT_EQ(fridge.getInventory().size(), 0);
}

TEST(FridgeTest, SetTemperatureWorks) {
    Inventory inv(10, "FridgeInventory", "Kitchen", "Chef", "2025-10-30");
    Fridge fridge(5.0, 10, inv, "Off");
    fridge.setTemperature(3.5);
    EXPECT_EQ(fridge.getTemperature(), 3.5);
}

TEST(FridgeTest, SetStateWorks) {
    Inventory inv(10, "FridgeInventory", "Kitchen", "Chef", "2025-10-30");
    Fridge fridge(5.0, 10, inv, "Off");
    fridge.setState("On");
    EXPECT_EQ(fridge.getState(), "On");
}

TEST(FridgeManagerTest, TurnOnFridge) {
    Inventory inv(10, "FridgeInventory", "Kitchen", "Chef", "2025-10-30");
    Fridge fridge(0, 10, inv, "Off");
    MockSensor sensor;
    FridgeManager mgr(sensor, 5);
    mgr.turnOnOff(fridge);
    EXPECT_EQ(fridge.getState(), "On");
    EXPECT_EQ(fridge.getTemperature(), 4);
    EXPECT_EQ(sensor.getCurrentTemperature(), 4);
}

TEST(FridgeManagerTest, TurnOffFridge) {
    Inventory inv(10, "FridgeInventory", "Kitchen", "Chef", "2025-10-30");
    Fridge fridge(4, 10, inv, "On");
    MockSensor sensor;
    FridgeManager mgr(sensor, 5);
    mgr.turnOnOff(fridge);
    EXPECT_EQ(fridge.getState(), "Off");
}

TEST(FridgeManagerTest, SetTemperatureUpdatesSensor) {
    Inventory inv(10, "FridgeInventory", "Kitchen", "Chef", "2025-10-30");
    Fridge fridge(4, 10, inv, "On");
    MockSensor sensor;
    FridgeManager mgr(sensor, 5);
    mgr.setTemperature(fridge, 2);
    EXPECT_EQ(fridge.getTemperature(), 2);
    EXPECT_EQ(sensor.getCurrentTemperature(), 2);
}

TEST(FridgeManagerTest, AddIngredientSuccessful) {
    Inventory inv(2, "FridgeInventory", "Kitchen", "Chef", "2025-10-30");
    Fridge fridge(4, 2, inv, "On");
    MockSensor sensor;
    sensor.setCurrentTemperature(3);
    FridgeManager mgr(sensor, 5);
    Ingredient i("Carrot", 1, "kg");
    EXPECT_NO_THROW(mgr.addIngredient(fridge, i));
    EXPECT_EQ(fridge.getInventory().size(), 1);
}

TEST(FridgeManagerTest, AddIngredientFridgeOffThrows) {
    Inventory inv(2, "FridgeInventory", "Kitchen", "Chef", "2025-10-30");
    Fridge fridge(4, 2, inv, "Off");
    MockSensor sensor;
    sensor.setCurrentTemperature(3);
    FridgeManager mgr(sensor, 5);
    Ingredient i("Carrot", 1, "kg");
    EXPECT_THROW(mgr.addIngredient(fridge, i), NotEnoughTemperatureException);
}

TEST(FridgeManagerTest, AddIngredientTooHotThrows) {
    Inventory inv(2, "FridgeInventory", "Kitchen", "Chef", "2025-10-30");
    Fridge fridge(6, 2, inv, "On");
    MockSensor sensor;
    sensor.setCurrentTemperature(7);
    FridgeManager mgr(sensor, 5);
    Ingredient i("Carrot", 1, "kg");
    EXPECT_THROW(mgr.addIngredient(fridge, i), NotEnoughTemperatureException);
}

TEST(FridgeManagerTest, AddIngredientOverflowThrows) {
    Inventory inv(1, "FridgeInventory", "Kitchen", "Chef", "2025-10-30");
    Fridge fridge(4, 1, inv, "On");
    MockSensor sensor;
    sensor.setCurrentTemperature(3);
    FridgeManager mgr(sensor, 5);
    Ingredient i1("Carrot", 1, "kg");
    Ingredient i2("Tomato", 1, "kg");
    mgr.addIngredient(fridge, i1);
    EXPECT_THROW(mgr.addIngredient(fridge, i2), FridgeOverflowException);
}

TEST(InventoryTest, AddIngredientRespectsCapacity) {
    Inventory inv(2, "Inv", "Kitchen", "Chef", "2025-10-30");
    Ingredient i1("Apple", 1, "kg");
    Ingredient i2("Banana", 1, "kg");
    Ingredient i3("Cherry", 1, "kg");
    inv.addIngredient(i1);
    inv.addIngredient(i2);
    inv.addIngredient(i3);
    EXPECT_EQ(inv.size(), 2);
}

TEST(InventoryTest, GettersReturnCorrectValues) {
    Inventory inv(5, "Inv", "Kitchen", "Chef", "2025-10-30");
    EXPECT_EQ(inv.getCapacity(), 5);
    EXPECT_EQ(inv.getName(), "Inv");
    EXPECT_EQ(inv.getLocation(), "Kitchen");
    EXPECT_EQ(inv.getOwner(), "Chef");
    EXPECT_EQ(inv.getLastUpdated(), "2025-10-30");
}

TEST(FridgeTest, GetInventoryReference) {
    Inventory inv(5, "Inv", "Kitchen", "Chef", "2025-10-30");
    Fridge fridge(4, 5, inv, "On");
    EXPECT_EQ(&fridge.getInventory(), &inv);
}

TEST(FridgeManagerTest, MultipleIngredientsAdded) {
    Inventory inv(3, "Inv", "Kitchen", "Chef", "2025-10-30");
    Fridge fridge(4, 3, inv, "On");
    MockSensor sensor;
    sensor.setCurrentTemperature(4);
    FridgeManager mgr(sensor, 5);
    Ingredient i1("Apple", 1, "kg");
    Ingredient i2("Banana", 1, "kg");
    mgr.addIngredient(fridge, i1);
    mgr.addIngredient(fridge, i2);
    EXPECT_EQ(fridge.getInventory().size(), 2);
}

TEST(FridgeManagerTest, TurnOnSetsTemperatureAndSensor) {
    Inventory inv(3, "Inv", "Kitchen", "Chef", "2025-10-30");
    Fridge fridge(0, 3, inv, "Off");
    MockSensor sensor;
    FridgeManager mgr(sensor, 5);
    mgr.turnOnOff(fridge);
    EXPECT_EQ(fridge.getState(), "On");
    EXPECT_EQ(fridge.getTemperature(), 4);
    EXPECT_EQ(sensor.getCurrentTemperature(), 4);
}