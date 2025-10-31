#include "gtest/gtest.h"
#include "D:\Projects\Cookery\Cookery\Reservation.h"
#include "D:\Projects\Cookery\Cookery\ReservationManager.h"
#include "D:\Projects\Cookery\Cookery\Customer.h"
#include <sstream>
#include <iostream>

using namespace std;

TEST(ReservationTest, ConstructorSetsInitialValues) {
    Customer cust("John Doe", "1234567890", "john@example.com");
    Reservation res(cust, "2025-11-01", 5, 4, "Window seat");

    EXPECT_EQ(res.getCustomer().getName(), "John Doe");
    EXPECT_EQ(res.getDate(), "2025-11-01");
    EXPECT_EQ(res.getTableNumber(), 5);
    EXPECT_FALSE(res.isConfirmed());
    EXPECT_EQ(res.getNumberOfGuests(), 4);
    EXPECT_EQ(res.getSpecialRequest(), "Window seat");
    EXPECT_EQ(res.getOccasion(), "");
    EXPECT_EQ(res.getNotes(), "");
    EXPECT_EQ(res.getDepositAmount(), 0);
    EXPECT_EQ(res.getContactPhone(), "");
    EXPECT_EQ(res.getEmail(), "");
    EXPECT_FALSE(res.isVIP());
}

TEST(ReservationTest, SettersAndGettersWork) {
    Customer cust("Alice", "0987654321", "alice@example.com");
    Reservation res(cust, "2025-11-05", 10);

    res.setConfirmed(true);
    res.setNumberOfGuests(3);
    res.setSpecialRequest("Near stage");
    res.setOccasion("Birthday");
    res.setNotes("Vegetarian menu");
    res.setDepositAmount(50.0);
    res.setContactPhone("111222333");
    res.setEmail("alice@domain.com");
    res.setVIP(true);

    EXPECT_TRUE(res.isConfirmed());
    EXPECT_EQ(res.getNumberOfGuests(), 3);
    EXPECT_EQ(res.getSpecialRequest(), "Near stage");
    EXPECT_EQ(res.getOccasion(), "Birthday");
    EXPECT_EQ(res.getNotes(), "Vegetarian menu");
    EXPECT_DOUBLE_EQ(res.getDepositAmount(), 50.0);
    EXPECT_EQ(res.getContactPhone(), "111222333");
    EXPECT_EQ(res.getEmail(), "alice@domain.com");
    EXPECT_TRUE(res.isVIP());
}


TEST(ReservationManagerTest, ConfirmReservationChangesStatus) {
    Customer cust("Bob", "123", "bob@example.com");
    Reservation res(cust, "2025-11-10", 2);
    ReservationManager manager;

    manager.confirm(res);
    EXPECT_TRUE(res.isConfirmed());
}

TEST(ReservationManagerTest, CancelReservationChangesStatus) {
    Customer cust("Charlie", "456", "charlie@example.com");
    Reservation res(cust, "2025-11-15", 3);
    res.setConfirmed(true);
    ReservationManager manager;

    manager.cancel(res);
    EXPECT_FALSE(res.isConfirmed());
}

TEST(ReservationManagerTest, ConfirmReservationOutputsMessage) {
    Customer cust("David", "789", "david@example.com");
    Reservation res(cust, "2025-11-20", 1);
    ReservationManager manager;

    stringstream buffer;
    streambuf* oldCout = cout.rdbuf(buffer.rdbuf());

    manager.confirm(res);

    cout.rdbuf(oldCout);
    string output = buffer.str();
    EXPECT_NE(output.find("has been confirmed"), string::npos);
    EXPECT_NE(output.find("David"), string::npos);
    EXPECT_NE(output.find("2025-11-20"), string::npos);
    EXPECT_NE(output.find("table 1"), string::npos);
}

TEST(ReservationManagerTest, CancelReservationOutputsMessage) {
    Customer cust("Eve", "987", "eve@example.com");
    Reservation res(cust, "2025-11-25", 4);
    ReservationManager manager;

    stringstream buffer;
    streambuf* oldCout = cout.rdbuf(buffer.rdbuf());

    manager.cancel(res);

    cout.rdbuf(oldCout);
    string output = buffer.str();
    EXPECT_NE(output.find("has been canceled"), string::npos);
    EXPECT_NE(output.find("Eve"), string::npos);
    EXPECT_NE(output.find("2025-11-25"), string::npos);
}


TEST(ReservationTest, ConfirmThenCancel) {
    Customer cust("Frank", "555", "frank@example.com");
    Reservation res(cust, "2025-12-01", 6);
    ReservationManager manager;

    manager.confirm(res);
    EXPECT_TRUE(res.isConfirmed());

    manager.cancel(res);
    EXPECT_FALSE(res.isConfirmed());
}

TEST(ReservationTest, ZeroGuestsAllowed) {
    Customer cust("Grace", "222", "grace@example.com");
    Reservation res(cust, "2025-12-05", 7);
    res.setNumberOfGuests(0);
    EXPECT_EQ(res.getNumberOfGuests(), 0);
}

TEST(ReservationTest, VIPStatusToggle) {
    Customer cust("Hank", "333", "hank@example.com");
    Reservation res(cust, "2025-12-10", 8);
    res.setVIP(true);
    EXPECT_TRUE(res.isVIP());
    res.setVIP(false);
    EXPECT_FALSE(res.isVIP());
}

TEST(ReservationTest, SetDepositAmountZero) {
    Customer cust("Ivy", "444", "ivy@example.com");
    Reservation res(cust, "2025-12-15", 9);
    res.setDepositAmount(0);
    EXPECT_DOUBLE_EQ(res.getDepositAmount(), 0);
}

TEST(ReservationTest, SetDepositAmountPositive) {
    Customer cust("Jack", "555", "jack@example.com");
    Reservation res(cust, "2025-12-20", 10);
    res.setDepositAmount(100.5);
    EXPECT_DOUBLE_EQ(res.getDepositAmount(), 100.5);
}

TEST(ReservationTest, ChangeSpecialRequest) {
    Customer cust("Karen", "666", "karen@example.com");
    Reservation res(cust, "2025-12-25", 11, 2, "Near window");
    res.setSpecialRequest("Near stage");
    EXPECT_EQ(res.getSpecialRequest(), "Near stage");
}

TEST(ReservationTest, ChangeOccasion) {
    Customer cust("Leo", "777", "leo@example.com");
    Reservation res(cust, "2025-12-30", 12);
    res.setOccasion("Anniversary");
    EXPECT_EQ(res.getOccasion(), "Anniversary");
}

TEST(ReservationTest, ChangeNotes) {
    Customer cust("Mia", "888", "mia@example.com");
    Reservation res(cust, "2026-01-05", 13);
    res.setNotes("Allergic to peanuts");
    EXPECT_EQ(res.getNotes(), "Allergic to peanuts");
}

TEST(ReservationTest, ChangeContactInfo) {
    Customer cust("Nick", "999", "nick@example.com");
    Reservation res(cust, "2026-01-10", 14);
    res.setContactPhone("1010101010");
    res.setEmail("nick@domain.com");
    EXPECT_EQ(res.getContactPhone(), "1010101010");
    EXPECT_EQ(res.getEmail(), "nick@domain.com");
}

TEST(ReservationTest, ConfirmReservationTwice) {
    Customer cust("Olivia", "111", "olivia@example.com");
    Reservation res(cust, "2026-01-15", 15);
    ReservationManager manager;

    manager.confirm(res);
    manager.confirm(res);
    EXPECT_TRUE(res.isConfirmed());
}

TEST(ReservationTest, CancelReservationTwice) {
    Customer cust("Paul", "222", "paul@example.com");
    Reservation res(cust, "2026-01-20", 16);
    ReservationManager manager;

    manager.cancel(res);
    manager.cancel(res);
    EXPECT_FALSE(res.isConfirmed());
}
