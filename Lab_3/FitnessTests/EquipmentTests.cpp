#include "gtest/gtest.h"
#include "Equipment.h"

TEST(EquipmentTest, ConstructorSetsValuesCorrectly) {
    Equipment eq("Treadmill", "Cardio", true);
    EXPECT_EQ(eq.getName(), "Treadmill");
    EXPECT_EQ(eq.getType(), "Cardio");
    EXPECT_TRUE(eq.getAvailability());
}

TEST(EquipmentTest, ConstructorDefaultAvailabilityTrue) {
    Equipment eq("Bike", "Cardio");
    EXPECT_TRUE(eq.getAvailability());
}

TEST(EquipmentTest, SetAvailabilityFalse) {
    Equipment eq("Bench", "Strength");
    eq.setAvailability(false);
    EXPECT_FALSE(eq.getAvailability());
}

TEST(EquipmentTest, SetAvailabilityTrue) {
    Equipment eq("Dumbbell", "Strength", false);
    eq.setAvailability(true);
    EXPECT_TRUE(eq.getAvailability());
}

TEST(EquipmentTest, GetNameReturnsCorrectValue) {
    Equipment eq("Kettlebell", "Strength");
    EXPECT_EQ(eq.getName(), "Kettlebell");
}

TEST(EquipmentTest, GetTypeReturnsCorrectValue) {
    Equipment eq("Rowing Machine", "Cardio");
    EXPECT_EQ(eq.getType(), "Cardio");
}

TEST(EquipmentTest, AvailabilityTogglesCorrectly) {
    Equipment eq("Stepper", "Cardio");
    eq.setAvailability(false);
    EXPECT_FALSE(eq.getAvailability());
    eq.setAvailability(true);
    EXPECT_TRUE(eq.getAvailability());
}

TEST(EquipmentTest, MultipleObjectsIndependent) {
    Equipment eq1("Treadmill", "Cardio");
    Equipment eq2("Barbell", "Strength", false);
    EXPECT_TRUE(eq1.getAvailability());
    EXPECT_FALSE(eq2.getAvailability());
}

TEST(EquipmentTest, SameNameDifferentType) {
    Equipment eq1("Bike", "Cardio");
    Equipment eq2("Bike", "Spin");
    EXPECT_NE(eq1.getType(), eq2.getType());
}

TEST(EquipmentTest, EmptyNameAllowed) {
    Equipment eq("", "Unknown");
    EXPECT_EQ(eq.getName(), "");
}

TEST(EquipmentTest, EmptyTypeAllowed) {
    Equipment eq("Box", "");
    EXPECT_EQ(eq.getType(), "");
}
TEST(EquipmentTest, NameWithSpaces) {
    Equipment eq("Pull Up Bar", "Strength");
    EXPECT_EQ(eq.getName(), "Pull Up Bar");
}

TEST(EquipmentTest, CaseSensitiveName) {
    Equipment eq1("bike", "Cardio");
    Equipment eq2("Bike", "Cardio");
    EXPECT_NE(eq1.getName(), eq2.getName());
}

TEST(EquipmentTest, LongNameHandledCorrectly) {
    std::string longName(100, 'A');
    Equipment eq(longName, "Custom");
    EXPECT_EQ(eq.getName(), longName);
}
TEST(EquipmentTest, CopyConstructorRetainsType) {
    Equipment eq1("Mat", "Yoga");
    Equipment eq2 = eq1;
    EXPECT_EQ(eq2.getType(), "Yoga");
}
