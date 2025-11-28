#include "gtest/gtest.h"
#include "Employee.h"
#include "Bubblesort.h"
#include <vector>
#include <string>

TEST(EmployeeTest, ConstructorAndGetters) {
    Employee e("Alice", 2500);
    EXPECT_EQ(e.getName(), "Alice");
    EXPECT_DOUBLE_EQ(e.getSalary(), 2500);
}

TEST(EmployeeTest, Setters) {
    Employee e("Bob", 1800);
    e.setName("Robert");
    e.setSalary(2000);
    EXPECT_EQ(e.getName(), "Robert");
    EXPECT_DOUBLE_EQ(e.getSalary(), 2000);
}

TEST(EmployeeTest, CompareBySalary) {
    Employee e1("Alice", 2500);
    Employee e2("Bob", 1800);
    EXPECT_TRUE(compareBySalary(e2, e1));
    EXPECT_FALSE(compareBySalary(e1, e2));
}

TEST(EmployeeTest, CompareByName) {
    Employee e1("Alice", 2500);
    Employee e2("Bob", 1800);
    EXPECT_TRUE(compareByName(e1, e2));
    EXPECT_FALSE(compareByName(e2, e1));
}

TEST(BubbleSortVectorTest, SortBySalary) {
    std::vector<Employee> employees = {
        Employee("Charlie", 3200),
        Employee("Alice", 2500),
        Employee("Bob", 1800)
    };
    bubbleSort(employees, compareBySalary);
    EXPECT_EQ(employees[0].getName(), "Bob");
    EXPECT_EQ(employees[1].getName(), "Alice");
    EXPECT_EQ(employees[2].getName(), "Charlie");
}

TEST(BubbleSortVectorTest, SortByName) {
    std::vector<Employee> employees = {
        Employee("Charlie", 3200),
        Employee("Alice", 2500),
        Employee("Bob", 1800)
    };
    bubbleSort(employees, compareByName);
    EXPECT_EQ(employees[0].getName(), "Alice");
    EXPECT_EQ(employees[1].getName(), "Bob");
    EXPECT_EQ(employees[2].getName(), "Charlie");
}

TEST(BubbleSortArrayTest, SortBySalary) {
    Employee arr[] = { Employee("Charlie", 3200), Employee("Alice", 2500), Employee("Bob", 1800) };
    size_t size = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, size, compareBySalary);
    EXPECT_EQ(arr[0].getName(), "Bob");
    EXPECT_EQ(arr[1].getName(), "Alice");
    EXPECT_EQ(arr[2].getName(), "Charlie");
}

TEST(BubbleSortArrayTest, SortByName) {
    Employee arr[] = { Employee("Charlie", 3200), Employee("Alice", 2500), Employee("Bob", 1800) };
    size_t size = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, size, compareByName);
    EXPECT_EQ(arr[0].getName(), "Alice");
    EXPECT_EQ(arr[1].getName(), "Bob");
    EXPECT_EQ(arr[2].getName(), "Charlie");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
