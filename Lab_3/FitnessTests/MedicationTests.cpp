#include "gtest/gtest.h"
#include "Medication.h"
#include "MedicationManager.h"
#include <string>
#include <vector>

using namespace std;

TEST(MedicationTest, ConstructorAndGetters) {
    Medication med("Aspirin", "500mg", "Twice a day", "2025-11-01", "2025-11-10", "Take after meals");
    EXPECT_EQ(med.getName(), "Aspirin");
    EXPECT_EQ(med.getDose(), "500mg");
    EXPECT_EQ(med.getFrequency(), "Twice a day");
    EXPECT_EQ(med.getStartDate(), "2025-11-01");
    EXPECT_EQ(med.getEndDate(), "2025-11-10");
    EXPECT_EQ(med.getNote(), "Take after meals");
}

TEST(MedicationTest, Setters) {
    Medication med("Ibuprofen", "200mg", "Once a day", "2025-11-01", "2025-11-05", "");
    med.setDose("400mg");
    med.setFrequency("Twice a day");
    med.setStartDate("2025-11-02");
    med.setEndDate("2025-11-06");
    med.setNote("With water");
    EXPECT_EQ(med.getDose(), "400mg");
    EXPECT_EQ(med.getFrequency(), "Twice a day");
    EXPECT_EQ(med.getStartDate(), "2025-11-02");
    EXPECT_EQ(med.getEndDate(), "2025-11-06");
    EXPECT_EQ(med.getNote(), "With water");
}

TEST(MedicationManagerTest, AddMedication) {
    MedicationManager manager;
    Medication med("Aspirin", "500mg", "Twice a day", "2025-11-01", "2025-11-10", "Take after meals");
    manager.addMedication(med);
    vector<Medication> meds = manager.getAllMedications();
    EXPECT_EQ(meds.size(), 1);
    EXPECT_EQ(meds[0].getName(), "Aspirin");
}

TEST(MedicationManagerTest, RemoveMedicationExisting) {
    MedicationManager manager;
    Medication med1("Aspirin", "500mg", "Twice a day", "2025-11-01", "2025-11-10", "");
    Medication med2("Ibuprofen", "200mg", "Once a day", "2025-11-01", "2025-11-05", "");
    manager.addMedication(med1);
    manager.addMedication(med2);
    bool removed = manager.removeMedication("Aspirin");
    EXPECT_TRUE(removed);
    vector<Medication> meds = manager.getAllMedications();
    EXPECT_EQ(meds.size(), 1);
    EXPECT_EQ(meds[0].getName(), "Ibuprofen");
}

TEST(MedicationManagerTest, RemoveMedicationNonExisting) {
    MedicationManager manager;
    Medication med("Ibuprofen", "200mg", "Once a day", "2025-11-01", "2025-11-05", "");
    manager.addMedication(med);
    bool removed = manager.removeMedication("Aspirin");
    EXPECT_FALSE(removed);
    EXPECT_EQ(manager.getAllMedications().size(), 1);
}

TEST(MedicationManagerTest, MultipleMedications) {
    MedicationManager manager;
    Medication med1("Aspirin", "500mg", "Twice a day", "2025-11-01", "2025-11-10", "");
    Medication med2("Ibuprofen", "200mg", "Once a day", "2025-11-01", "2025-11-05", "");
    Medication med3("Paracetamol", "500mg", "Three times a day", "2025-11-03", "2025-11-07", "");
    manager.addMedication(med1);
    manager.addMedication(med2);
    manager.addMedication(med3);
    vector<Medication> meds = manager.getAllMedications();
    EXPECT_EQ(meds.size(), 3);
}

TEST(MedicationManagerTest, RemoveAllMedications) {
    MedicationManager manager;
    Medication med1("Aspirin", "500mg", "Twice a day", "2025-11-01", "2025-11-10", "");
    Medication med2("Ibuprofen", "200mg", "Once a day", "2025-11-01", "2025-11-05", "");
    manager.addMedication(med1);
    manager.addMedication(med2);
    manager.removeMedication("Aspirin");
    manager.removeMedication("Ibuprofen");
    EXPECT_EQ(manager.getAllMedications().size(), 0);
}

TEST(MedicationManagerTest, AddDuplicateMedication) {
    MedicationManager manager;
    Medication med("Aspirin", "500mg", "Twice a day", "2025-11-01", "2025-11-10", "");
    manager.addMedication(med);
    manager.addMedication(med);
    EXPECT_EQ(manager.getAllMedications().size(), 2);
}

TEST(MedicationTest, NameImmutability) {
    Medication med("Aspirin", "500mg", "Twice a day", "2025-11-01", "2025-11-10", "");
    EXPECT_EQ(med.getName(), "Aspirin");
}

TEST(MedicationTest, UpdateDoseAndFrequency) {
    Medication med("Ibuprofen", "200mg", "Once a day", "2025-11-01", "2025-11-05", "");
    med.setDose("400mg");
    med.setFrequency("Twice a day");
    EXPECT_EQ(med.getDose(), "400mg");
    EXPECT_EQ(med.getFrequency(), "Twice a day");
}

TEST(MedicationTest, UpdateStartAndEndDates) {
    Medication med("Paracetamol", "500mg", "Three times a day", "2025-11-03", "2025-11-07", "");
    med.setStartDate("2025-11-04");
    med.setEndDate("2025-11-08");
    EXPECT_EQ(med.getStartDate(), "2025-11-04");
    EXPECT_EQ(med.getEndDate(), "2025-11-08");
}

TEST(MedicationTest, UpdateNote) {
    Medication med("Paracetamol", "500mg", "Three times a day", "2025-11-03", "2025-11-07", "");
    med.setNote("Take with food");
    EXPECT_EQ(med.getNote(), "Take with food");
}

TEST(MedicationManagerTest, RemoveMedicationFromEmptyManager) {
    MedicationManager manager;
    bool removed = manager.removeMedication("Aspirin");
    EXPECT_FALSE(removed);
    EXPECT_EQ(manager.getAllMedications().size(), 0);
}
