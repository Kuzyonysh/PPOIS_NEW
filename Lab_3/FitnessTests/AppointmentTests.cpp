#include <gtest/gtest.h>
#include "Appointment.h"
#include "AppointmentManager.h"
#include "Exception.h"


TEST(AppointmentTest, ConstructorStoresValuesCorrectly) {
    Appointment app("2025-11-07", "10:00", "Dr. Smith", "Clinic A", "Checkup");
    EXPECT_EQ(app.getDate(), "2025-11-07");
    EXPECT_EQ(app.getTime(), "10:00");
    EXPECT_EQ(app.getDoctor(), "Dr. Smith");
    EXPECT_EQ(app.getLocation(), "Clinic A");
    EXPECT_EQ(app.getReason(), "Checkup");
    EXPECT_FALSE(app.isAttended());
}

TEST(AppointmentTest, MarkAttendedSetsFlag) {
    Appointment app("2025-11-07", "11:00", "Dr. Jones", "Clinic B", "Flu Shot");
    app.markAttended();
    EXPECT_TRUE(app.isAttended());
}

TEST(AppointmentManagerTest, AddAppointmentIncreasesCount) {
    AppointmentManager manager;
    manager.addAppointment(Appointment("2025-11-07", "09:00", "Dr. Smith", "Clinic A", "Checkup"));
    EXPECT_EQ(manager.getTotalAppointments(), 1);
}

TEST(AppointmentManagerTest, AddDuplicateAppointmentThrowsException) {
    AppointmentManager manager;
    manager.addAppointment(Appointment("2025-11-07", "09:00", "Dr. Smith", "Clinic A", "Checkup"));
    EXPECT_THROW(
        manager.addAppointment(Appointment("2025-11-07", "09:00", "Dr. Brown", "Clinic B", "Consultation")),
        AppointmentException
    );
}

TEST(AppointmentManagerTest, CancelExistingAppointmentReducesCount) {
    AppointmentManager manager;
    manager.addAppointment(Appointment("2025-11-07", "09:00", "Dr. Smith", "Clinic A", "Checkup"));
    manager.cancelAppointment("2025-11-07", "09:00");
    EXPECT_EQ(manager.getTotalAppointments(), 0);
}

TEST(AppointmentManagerTest, CancelNonExistingAppointmentThrowsException) {
    AppointmentManager manager;
    EXPECT_THROW(
        manager.cancelAppointment("2025-11-07", "10:00"),
        AppointmentException
    );
}

TEST(AppointmentManagerTest, GetAppointmentReturnsCorrectData) {
    AppointmentManager manager;
    manager.addAppointment(Appointment("2025-11-07", "09:00", "Dr. Brown", "Clinic B", "Consultation"));
    Appointment found = manager.getAppointment("2025-11-07", "09:00");
    EXPECT_EQ(found.getDoctor(), "Dr. Brown");
    EXPECT_EQ(found.getReason(), "Consultation");
}

TEST(AppointmentManagerTest, GetAppointmentThrowsWhenNotFound) {
    AppointmentManager manager;
    EXPECT_THROW(manager.getAppointment("2025-11-07", "09:00"), AppointmentException);
}

TEST(AppointmentManagerTest, GetAppointmentsByDoctorReturnsCorrectOnes) {
    AppointmentManager manager;
    manager.addAppointment(Appointment("2025-11-07", "09:00", "Dr. Smith", "Clinic A", "Checkup"));
    manager.addAppointment(Appointment("2025-11-08", "10:00", "Dr. Brown", "Clinic B", "Consultation"));
    manager.addAppointment(Appointment("2025-11-09", "11:00", "Dr. Smith", "Clinic C", "X-Ray"));
    auto list = manager.getAppointmentsByDoctor("Dr. Smith");
    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list[0].getDoctor(), "Dr. Smith");
}

TEST(AppointmentManagerTest, GetAppointmentsByDateReturnsCorrectOnes) {
    AppointmentManager manager;
    manager.addAppointment(Appointment("2025-11-07", "09:00", "Dr. A", "Clinic A", "Checkup"));
    manager.addAppointment(Appointment("2025-11-07", "10:00", "Dr. B", "Clinic B", "X-Ray"));
    manager.addAppointment(Appointment("2025-11-08", "11:00", "Dr. C", "Clinic C", "Flu Shot"));
    auto list = manager.getAppointmentsByDate("2025-11-07");
    EXPECT_EQ(list.size(), 2);
}

TEST(AppointmentManagerTest, MarkAppointmentAttendedSetsFlagCorrectly) {
    AppointmentManager manager;
    manager.addAppointment(Appointment("2025-11-07", "09:00", "Dr. Smith", "Clinic A", "Checkup"));
    manager.markAppointmentAttended("2025-11-07", "09:00");
    Appointment a = manager.getAppointment("2025-11-07", "09:00");
    EXPECT_TRUE(a.isAttended());
}

TEST(AppointmentManagerTest, MarkAppointmentAttendedThrowsIfNotFound) {
    AppointmentManager manager;
    EXPECT_THROW(
        manager.markAppointmentAttended("2025-11-07", "09:00"),
        AppointmentException
    );
}

TEST(AppointmentManagerTest, MultipleAppointmentsCanBeManaged) {
    AppointmentManager manager;
    for (int i = 0; i < 5; ++i) {
        manager.addAppointment(Appointment("2025-11-07", "0" + to_string(i) + ":00", "Dr. X", "Clinic", "Reason"));
    }
    EXPECT_EQ(manager.getTotalAppointments(), 5);
}

TEST(AppointmentManagerTest, CancelOneAppointmentKeepsOthers) {
    AppointmentManager manager;
    manager.addAppointment(Appointment("2025-11-07", "09:00", "Dr. Smith", "Clinic A", "Checkup"));
    manager.addAppointment(Appointment("2025-11-07", "10:00", "Dr. Smith", "Clinic A", "Consultation"));
    manager.cancelAppointment("2025-11-07", "09:00");
    EXPECT_EQ(manager.getTotalAppointments(), 1);
    EXPECT_EQ(manager.getAppointment("2025-11-07", "10:00").getReason(), "Consultation");
}

TEST(AppointmentManagerTest, AppointmentsRemainIndependent) {
    AppointmentManager manager;
    manager.addAppointment(Appointment("2025-11-07", "09:00", "Dr. A", "Clinic A", "Checkup"));
    manager.addAppointment(Appointment("2025-11-08", "10:00", "Dr. B", "Clinic B", "Consultation"));
    auto a1 = manager.getAppointment("2025-11-07", "09:00");
    auto a2 = manager.getAppointment("2025-11-08", "10:00");
    EXPECT_NE(a1.getDate(), a2.getDate());
    EXPECT_NE(a1.getDoctor(), a2.getDoctor());
}
