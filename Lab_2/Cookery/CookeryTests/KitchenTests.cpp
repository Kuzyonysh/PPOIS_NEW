#include <gtest/gtest.h>
#include "D:\Projects\Cookery\Cookery\Kitchen.h"
#include "D:\Projects\Cookery\Cookery\KitchenManager.h"
#include "D:\Projects\Cookery\Cookery\Tool.h"
TEST(ToolTest, ConstructorSetsValues) {
    Tool t("Oven", "New", "Cooking", "Metal", 25.0);
    EXPECT_EQ(t.getName(), "Oven");
    EXPECT_EQ(t.getConditionName(), "New");
    EXPECT_EQ(t.getPurposeName(), "Cooking");
    EXPECT_EQ(t.getMaterial(), "Metal");
    EXPECT_DOUBLE_EQ(t.getWeight(), 25.0);
    EXPECT_EQ(t.getBrand(), "Generic");
    EXPECT_EQ(t.getColor(), "None");
    EXPECT_EQ(t.getDurability(), 100);
    EXPECT_DOUBLE_EQ(t.getLength(), 10.0);
    EXPECT_DOUBLE_EQ(t.getWidth(), 5.0);
}

TEST(ToolTest, SettersModifyValues) {
    Tool t("Knife", "Used", "Cutting", "Steel", 2.0);
    t.setCondition("Refurbished");
    t.setMaterial("Titanium");
    t.setWeight(2.5);
    t.setBrand("ProChef");
    t.setColor("Silver");
    t.setDurability(90);
    t.setLength(15.0);
    t.setWidth(3.0);

    EXPECT_EQ(t.getConditionName(), "Refurbished");
    EXPECT_EQ(t.getMaterial(), "Titanium");
    EXPECT_DOUBLE_EQ(t.getWeight(), 2.5);
    EXPECT_EQ(t.getBrand(), "ProChef");
    EXPECT_EQ(t.getColor(), "Silver");
    EXPECT_EQ(t.getDurability(), 90);
    EXPECT_DOUBLE_EQ(t.getLength(), 15.0);
    EXPECT_DOUBLE_EQ(t.getWidth(), 3.0);
}

TEST(KitchenTest, ConstructorSetsValues) {
    Kitchen k("MyKitchen", 5);
    EXPECT_EQ(k.getName(), "MyKitchen");
    EXPECT_EQ(k.getCapacity(), 5);
    EXPECT_TRUE(k.getTools().empty());
    EXPECT_TRUE(k.getWorkplaces().empty());
    EXPECT_FALSE(k.isReady());
}

TEST(KitchenTest, AddToolsAndWorkplaces) {
    Kitchen k("TestKitchen", 3);
    Tool oven("Oven", "New", "Cooking", "Metal", 25.0);
    Tool knife("Knife", "Used", "Cutting", "Steel", 2.0);

    k.addTool(oven);
    k.addTool(knife);
    k.addWorkplace("Station1");
    k.addWorkplace("Station2");

    EXPECT_EQ(k.getTools().size(), 2);
    EXPECT_EQ(k.getWorkplaces().size(), 2);
    EXPECT_TRUE(k.isReady());
}

TEST(KitchenTest, CapacityExceededThrows) {
    Kitchen k("SmallKitchen", 1);
    Tool t1("Oven", "New", "Cooking", "Metal", 25.0);
    Tool t2("Knife", "Used", "Cutting", "Steel", 2.0);

    k.addTool(t1);
    EXPECT_THROW(k.addTool(t2), std::runtime_error);

    k.addWorkplace("Station1");
    EXPECT_THROW(k.addWorkplace("Station2"), std::runtime_error);
}

TEST(KitchenManagerTest, AddToolAndWorkplaceViaManager) {
    Kitchen k("ManagerKitchen", 5);
    KitchenManager mgr;
    Tool mixer("Mixer", "New", "Mixing", "Plastic", 5.0);

    mgr.addTool(k, mixer);
    mgr.addWorkplace(k, "Station1");

    EXPECT_EQ(k.getTools().size(), 1);
    EXPECT_EQ(k.getTools()[0].getName(), "Mixer");
    EXPECT_EQ(k.getWorkplaces().size(), 1);
    EXPECT_EQ(k.getWorkplaces()[0], "Station1");
    EXPECT_TRUE(k.isReady());
}

TEST(KitchenManagerTest, RenameAndChangeCapacity) {
    Kitchen k("OldName", 3);
    KitchenManager mgr;

    mgr.renameKitchen(k, "NewName");
    mgr.changeCapacity(k, 10);

    EXPECT_EQ(k.getName(), "NewName");
    EXPECT_EQ(k.getCapacity(), 10);
}

TEST(KitchenManagerTest, CheckReadyStatus) {
    Kitchen k("EmptyKitchen", 5);
    KitchenManager mgr;
    EXPECT_FALSE(mgr.checkReady(k));

    Tool t("Pan", "New", "Cooking", "Metal", 3.0);
    k.addTool(t);
    k.addWorkplace("Station1");

    EXPECT_TRUE(mgr.checkReady(k));
}