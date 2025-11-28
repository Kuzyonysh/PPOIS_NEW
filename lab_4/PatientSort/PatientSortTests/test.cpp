#include "gtest/gtest.h"
#include "Book.h"
#include "PatientSort.h"
#include <sstream>
#include <vector>



TEST(BookTest, ConstructorAndGetters) {
    Book b("Test", 120, 10);
    EXPECT_EQ(b.getName(), "Test");
    EXPECT_EQ(b.getPages(), 120);
    EXPECT_EQ(b.getChapter(), 10);
}

TEST(BookTest, Setters) {
    Book b("Old", 50, 5);

    b.setName("New");
    b.setPages(300);
    b.setChapter(20);

    EXPECT_EQ(b.getName(), "New");
    EXPECT_EQ(b.getPages(), 300);
    EXPECT_EQ(b.getChapter(), 20);
}

TEST(BookTest, PrintOutput) {
    Book b("PrintBook", 150, 8);

    std::stringstream ss;
    std::streambuf* oldCout = std::cout.rdbuf(ss.rdbuf());

    b.print();

    std::cout.rdbuf(oldCout);

    EXPECT_NE(ss.str().find("PrintBook"), std::string::npos);
    EXPECT_NE(ss.str().find("150"), std::string::npos);
    EXPECT_NE(ss.str().find("8"), std::string::npos);
}

TEST(ComparatorTest, CompareByPages) {
    Book a("A", 100, 10);
    Book b("B", 200, 5);
    EXPECT_TRUE(compareByPages(a, b));
    EXPECT_FALSE(compareByPages(b, a));
}

TEST(ComparatorTest, CompareByChapter) {
    Book a("A", 100, 3);
    Book b("B", 100, 7);
    EXPECT_TRUE(compareByChapter(a, b));
}

TEST(ComparatorTest, CompareByName) {
    Book a("Alice", 120, 3);
    Book b("Bob", 150, 5);
    EXPECT_TRUE(compareByName(a, b));
}


TEST(PatienceSortVectorTest, SortByPages) {
    std::vector<Book> books = {
        Book("A", 300, 10),
        Book("B", 100, 5),
        Book("C", 200, 8)
    };

    patienceSort(books, compareByPages);

    EXPECT_EQ(books[0].getPages(), 100);
    EXPECT_EQ(books[1].getPages(), 200);
    EXPECT_EQ(books[2].getPages(), 300);
}

TEST(PatienceSortVectorTest, AlreadySorted) {
    std::vector<Book> books = {
        Book("B", 1, 1),
        Book("C", 2, 2),
        Book("D", 3, 3)
    };

    patienceSort(books, compareByPages);

    EXPECT_EQ(books[0].getPages(), 1);
    EXPECT_EQ(books[1].getPages(), 2);
    EXPECT_EQ(books[2].getPages(), 3);
}

TEST(PatienceSortVectorTest, ReverseOrder) {
    std::vector<Book> books = {
        Book("Z", 3, 3),
        Book("Y", 2, 2),
        Book("X", 1, 1)
    };

    patienceSort(books, compareByPages);

    EXPECT_EQ(books[0].getPages(), 1);
    EXPECT_EQ(books[1].getPages(), 2);
    EXPECT_EQ(books[2].getPages(), 3);
}

TEST(PatienceSortVectorTest, SortByName) {
    std::vector<Book> books = {
        Book("Charlie", 200, 10),
        Book("Alice", 100, 3),
        Book("Bob", 150, 5)
    };

    patienceSort(books, compareByName);

    EXPECT_EQ(books[0].getName(), "Alice");
    EXPECT_EQ(books[1].getName(), "Bob");
    EXPECT_EQ(books[2].getName(), "Charlie");
}

TEST(PatienceSortArrayTest, SortByChapters) {
    Book arr[] = {
        Book("A", 100, 5),
        Book("B", 200, 3),
        Book("C", 150, 10)
    };

    patienceSort(arr, 3, compareByChapter);

    EXPECT_EQ(arr[0].getChapter(), 3);
    EXPECT_EQ(arr[1].getChapter(), 5);
    EXPECT_EQ(arr[2].getChapter(), 10);
}

TEST(PatienceSortArrayTest, Duplicates) {
    Book arr[] = {
        Book("A", 100, 1),
        Book("B", 100, 3),
        Book("C", 100, 2)
    };

    patienceSort(arr, 3, compareByPages);

    EXPECT_EQ(arr[0].getPages(), 100);
    EXPECT_EQ(arr[1].getPages(), 100);
    EXPECT_EQ(arr[2].getPages(), 100);
}

