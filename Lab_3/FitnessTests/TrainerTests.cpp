#include "gtest/gtest.h"
#include "Trainer.h"
#include "TrainerManager.h"
#include <string>
#include <vector>

using namespace std;

TEST(TrainerTest, ConstructorAndGetters) {
    Trainer t("John Doe", "Fitness", 5, 3000.0, true, "john@example.com", 30, 4.5, 20, "Male");
    EXPECT_EQ(t.getName(), "John Doe");
    EXPECT_EQ(t.getSpecialization(), "Fitness");
    EXPECT_EQ(t.getExperience(), 5);
    EXPECT_DOUBLE_EQ(t.getSalary(), 3000.0);
    EXPECT_TRUE(t.getAvailability());
    EXPECT_EQ(t.getContact(), "john@example.com");
    EXPECT_EQ(t.getAge(), 30);
    EXPECT_DOUBLE_EQ(t.getRating(), 4.5);
    EXPECT_EQ(t.getClientsCount(), 20);
    EXPECT_EQ(t.getGender(), "Male");
}

TEST(TrainerTest, Setters) {
    Trainer t("John Doe", "Fitness", 5, 3000.0, true, "john@example.com", 30, 4.5, 20, "Male");
    t.setSalary(3500.0);
    t.setAvailability(false);
    t.setContact("john.doe@example.com");
    EXPECT_DOUBLE_EQ(t.getSalary(), 3500.0);
    EXPECT_FALSE(t.getAvailability());
    EXPECT_EQ(t.getContact(), "john.doe@example.com");
}

TEST(TrainerManagerTest, AddTrainer) {
    TrainerManager manager;
    Trainer t("John Doe", "Fitness", 5, 3000.0, true, "john@example.com", 30, 4.5, 20, "Male");
    manager.addTrainer(t);
    vector<Trainer> all = manager.getAll();
    EXPECT_EQ(all.size(), 1);
    EXPECT_EQ(all[0].getName(), "John Doe");
}

TEST(TrainerManagerTest, GetAllMultipleTrainers) {
    TrainerManager manager;
    Trainer t1("John Doe", "Fitness", 5, 3000.0, true, "john@example.com", 30, 4.5, 20, "Male");
    Trainer t2("Alice Smith", "Yoga", 3, 2500.0, false, "alice@example.com", 28, 4.8, 15, "Female");
    manager.addTrainer(t1);
    manager.addTrainer(t2);
    vector<Trainer> all = manager.getAll();
    EXPECT_EQ(all.size(), 2);
    EXPECT_EQ(all[0].getName(), "John Doe");
    EXPECT_EQ(all[1].getName(), "Alice Smith");
}

TEST(TrainerManagerTest, GetAvailableCount) {
    TrainerManager manager;
    Trainer t1("John Doe", "Fitness", 5, 3000.0, true, "john@example.com", 30, 4.5, 20, "Male");
    Trainer t2("Alice Smith", "Yoga", 3, 2500.0, false, "alice@example.com", 28, 4.8, 15, "Female");
    Trainer t3("Bob Lee", "Cardio", 4, 2800.0, true, "bob@example.com", 32, 4.2, 18, "Male");
    manager.addTrainer(t1);
    manager.addTrainer(t2);
    manager.addTrainer(t3);
    EXPECT_EQ(manager.getAvailableCount(), 2);
}

TEST(TrainerManagerTest, AvailableCountEmpty) {
    TrainerManager manager;
    EXPECT_EQ(manager.getAvailableCount(), 0);
}

TEST(TrainerManagerTest, AddMultipleTrainersAndCheckAll) {
    TrainerManager manager;
    Trainer t1("John Doe", "Fitness", 5, 3000.0, true, "john@example.com", 30, 4.5, 20, "Male");
    Trainer t2("Alice Smith", "Yoga", 3, 2500.0, true, "alice@example.com", 28, 4.8, 15, "Female");
    Trainer t3("Bob Lee", "Cardio", 4, 2800.0, false, "bob@example.com", 32, 4.2, 18, "Male");
    manager.addTrainer(t1);
    manager.addTrainer(t2);
    manager.addTrainer(t3);
    vector<Trainer> all = manager.getAll();
    EXPECT_EQ(all.size(), 3);
    EXPECT_EQ(all[0].getName(), "John Doe");
    EXPECT_EQ(all[1].getName(), "Alice Smith");
    EXPECT_EQ(all[2].getName(), "Bob Lee");
}

TEST(TrainerTest, ChangeAvailabilityMultipleTimes) {
    Trainer t("John Doe", "Fitness", 5, 3000.0, true, "john@example.com", 30, 4.5, 20, "Male");
    t.setAvailability(false);
    EXPECT_FALSE(t.getAvailability());
    t.setAvailability(true);
    EXPECT_TRUE(t.getAvailability());
}

TEST(TrainerTest, ChangeSalaryMultipleTimes) {
    Trainer t("John Doe", "Fitness", 5, 3000.0, true, "john@example.com", 30, 4.5, 20, "Male");
    t.setSalary(3200.0);
    EXPECT_DOUBLE_EQ(t.getSalary(), 3200.0);
    t.setSalary(3500.0);
    EXPECT_DOUBLE_EQ(t.getSalary(), 3500.0);
}
