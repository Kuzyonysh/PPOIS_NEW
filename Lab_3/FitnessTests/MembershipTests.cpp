#include "gtest/gtest.h"
#include "Membership.h"
#include "MembershipManager.h"
#include "Exception.h"
#include <string>
#include <vector>

using namespace std;

TEST(MembershipTest, ConstructorAndGetters) {
    Membership m("John Doe", "Premium", 99.99, "2025-11-01", "2025-12-01", false);
    EXPECT_EQ(m.getType(), "Premium");
    EXPECT_EQ(m.getStartDate(), "2025-11-01");
    EXPECT_EQ(m.getEndDate(), "2025-12-01");
    EXPECT_TRUE(m.getActive());
    EXPECT_FALSE(m.getPaid());
}

TEST(MembershipTest, DeactivateMembership) {
    Membership m("John Doe", "Premium", 99.99, "2025-11-01", "2025-12-01", true);
    m.deactivate();
    EXPECT_FALSE(m.getActive());
}

TEST(MembershipTest, RenewMembership) {
    Membership m("John Doe", "Premium", 99.99, "2025-11-01", "2025-12-01", true);
    m.deactivate();
    m.renew("2026-01-01");
    EXPECT_TRUE(m.getActive());
    EXPECT_EQ(m.getEndDate(), "2026-01-01");
}

TEST(MembershipTest, MarkPaid) {
    Membership m("John Doe", "Premium", 99.99, "2025-11-01", "2025-12-01", false);
    m.markPaid();
    EXPECT_TRUE(m.getPaid());
}

TEST(MembershipManagerTest, AddMembership) {
    MembershipManager manager;
    Membership m("John Doe", "Premium", 99.99, "2025-11-01", "2025-12-01", false);
    manager.addMembership(m);
    vector<Membership> all = manager.getAll();
    EXPECT_EQ(all.size(), 1);
    EXPECT_EQ(all[0].getType(), "Premium");
}

TEST(MembershipManagerTest, GetActiveCount) {
    MembershipManager manager;
    Membership m1("John", "Premium", 99.99, "2025-11-01", "2025-12-01", true);
    Membership m2("Alice", "Standard", 49.99, "2025-11-01", "2025-12-01", true);
    m2.deactivate();
    manager.addMembership(m1);
    manager.addMembership(m2);
    EXPECT_EQ(manager.getActiveCount(), 1);
}

TEST(MembershipManagerTest, FindByTypeExisting) {
    MembershipManager manager;
    Membership m("John", "Premium", 99.99, "2025-11-01", "2025-12-01", true);
    manager.addMembership(m);
    Membership& found = manager.findByType("Premium");
    EXPECT_EQ(found.getType(), "Premium");
}

TEST(MembershipManagerTest, FindByTypeThrowsException) {
    MembershipManager manager;
    Membership m("John", "Premium", 99.99, "2025-11-01", "2025-12-01", true);
    manager.addMembership(m);
    EXPECT_THROW(manager.findByType("Standard"), MembershipException);
}

TEST(MembershipManagerTest, GetAllMemberships) {
    MembershipManager manager;
    Membership m1("John", "Premium", 99.99, "2025-11-01", "2025-12-01", true);
    Membership m2("Alice", "Standard", 49.99, "2025-11-01", "2025-12-01", true);
    manager.addMembership(m1);
    manager.addMembership(m2);
    vector<Membership> all = manager.getAll();
    EXPECT_EQ(all.size(), 2);
    EXPECT_EQ(all[0].getType(), "Premium");
    EXPECT_EQ(all[1].getType(), "Standard");
}

TEST(MembershipTest, RenewReactivatesMembership) {
    Membership m("John", "Premium", 99.99, "2025-11-01", "2025-12-01", true);
    m.deactivate();
    EXPECT_FALSE(m.getActive());
    m.renew("2026-01-01");
    EXPECT_TRUE(m.getActive());
    EXPECT_EQ(m.getEndDate(), "2026-01-01");
}

TEST(MembershipTest, MultipleMarkPaid) {
    Membership m("John", "Premium", 99.99, "2025-11-01", "2025-12-01", false);
    EXPECT_FALSE(m.getPaid());
    m.markPaid();
    EXPECT_TRUE(m.getPaid());
    m.markPaid();
    EXPECT_TRUE(m.getPaid());
}

TEST(MembershipManagerTest, ActiveCountWithNoMemberships) {
    MembershipManager manager;
    EXPECT_EQ(manager.getActiveCount(), 0);
}

TEST(MembershipManagerTest, AddMultipleMemberships) {
    MembershipManager manager;
    Membership m1("John", "Premium", 99.99, "2025-11-01", "2025-12-01", true);
    Membership m2("Alice", "Standard", 49.99, "2025-11-01", "2025-12-01", false);
    manager.addMembership(m1);
    manager.addMembership(m2);
    EXPECT_EQ(manager.getAll().size(), 2);
}

TEST(MembershipManagerTest, FindByTypeReturnsReference) {
    MembershipManager manager;
    Membership m("John", "Premium", 99.99, "2025-11-01", "2025-12-01", true);
    manager.addMembership(m);
    Membership& ref = manager.findByType("Premium");
    ref.deactivate();
    Membership& ref2 = manager.findByType("Premium");
    EXPECT_FALSE(ref2.getActive());
}

TEST(MembershipManagerTest, AddAndRemoveMultiple) {
    MembershipManager manager;
    Membership m1("John", "Premium", 99.99, "2025-11-01", "2025-12-01", true);
    Membership m2("Alice", "Standard", 49.99, "2025-11-01", "2025-12-01", true);
    manager.addMembership(m1);
    manager.addMembership(m2);
    EXPECT_EQ(manager.getActiveCount(), 2);
}
