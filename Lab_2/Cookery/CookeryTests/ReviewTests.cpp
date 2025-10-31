#include "gtest/gtest.h"
#include "D:\Projects\Cookery\Cookery\Review.h"
#include "D:\Projects\Cookery\Cookery\ReviewManager.h"
#include <sstream>
#include <iostream>

using namespace std;



TEST(ReviewTest, ConstructorSetsInitialValues) {
    Review review("Alice", "Great product!", 5);

    EXPECT_EQ(review.getAuthor(), "Alice");
    EXPECT_EQ(review.getComment(), "Great product!");
    EXPECT_EQ(review.getRating(), 5);
}

TEST(ReviewTest, DefaultConstructorSetsUnknownAuthor) {
    Review review;

    EXPECT_EQ(review.getAuthor(), "Unknown");
    EXPECT_EQ(review.getComment(), "");
    EXPECT_EQ(review.getRating(), 0);
}

TEST(ReviewTest, SettersAndGettersWork) {
    Review review;
    review.setAuthor("Bob");
    review.setComment("Not bad");
    review.setRating(3);

    EXPECT_EQ(review.getAuthor(), "Bob");
    EXPECT_EQ(review.getComment(), "Not bad");
    EXPECT_EQ(review.getRating(), 3);
}


TEST(ReviewManagerTest, AddReviewSetsProperties) {
    Review review;
    ReviewManager manager;

    manager.addReview(review, "Charlie", "Excellent!", 5);

    EXPECT_EQ(review.getAuthor(), "Charlie");
    EXPECT_EQ(review.getComment(), "Excellent!");
    EXPECT_EQ(review.getRating(), 5);
}

TEST(ReviewManagerTest, AddReviewOutputsMessage) {
    Review review;
    ReviewManager manager;

    stringstream buffer;
    streambuf* oldCout = cout.rdbuf(buffer.rdbuf());

    manager.addReview(review, "Dana", "Loved it", 4);

    cout.rdbuf(oldCout);
    string output = buffer.str();

    EXPECT_NE(output.find("Review added"), string::npos);
    EXPECT_NE(output.find("Dana"), string::npos);
    EXPECT_NE(output.find("Rating: 4"), string::npos);
}

TEST(ReviewManagerTest, IsPositiveReturnsTrueForHighRating) {
    Review review("Eve", "Awesome!", 5);
    ReviewManager manager;

    EXPECT_TRUE(manager.isPositive(review));
}

TEST(ReviewManagerTest, IsPositiveReturnsTrueForRating4) {
    Review review("Frank", "Good", 4);
    ReviewManager manager;

    EXPECT_TRUE(manager.isPositive(review));
}

TEST(ReviewManagerTest, IsPositiveReturnsFalseForLowRating) {
    Review review("Grace", "Okay", 3);
    ReviewManager manager;

    EXPECT_FALSE(manager.isPositive(review));
}

TEST(ReviewManagerTest, IsPositiveReturnsFalseForZeroRating) {
    Review review("Hank", "Terrible", 0);
    ReviewManager manager;

    EXPECT_FALSE(manager.isPositive(review));
}

TEST(ReviewManagerTest, AddReviewTwiceOverwritesPrevious) {
    Review review;
    ReviewManager manager;

    manager.addReview(review, "Ivy", "Nice", 4);
    manager.addReview(review, "Jack", "Better", 5);

    EXPECT_EQ(review.getAuthor(), "Jack");
    EXPECT_EQ(review.getComment(), "Better");
    EXPECT_EQ(review.getRating(), 5);
}


TEST(ReviewTest, SetEmptyAuthor) {
    Review review;
    review.setAuthor("");
    EXPECT_EQ(review.getAuthor(), "");
}

TEST(ReviewTest, SetEmptyComment) {
    Review review;
    review.setComment("");
    EXPECT_EQ(review.getComment(), "");
}

TEST(ReviewTest, SetNegativeRating) {
    Review review;
    review.setRating(-1);
    EXPECT_EQ(review.getRating(), -1);
}

TEST(ReviewTest, SetRatingAboveMax) {
    Review review;
    review.setRating(10);
    EXPECT_EQ(review.getRating(), 10);
}


TEST(ReviewManagerTest, IsPositiveWithNegativeRating) {
    Review review("Kate", "Bad", -2);
    ReviewManager manager;

    EXPECT_FALSE(manager.isPositive(review));
}

TEST(ReviewManagerTest, IsPositiveWithHighRating) {
    Review review("Leo", "Perfect!", 10);
    ReviewManager manager;

    EXPECT_TRUE(manager.isPositive(review));
}

TEST(ReviewManagerTest, MultipleReviews) {
    Review r1, r2, r3;
    ReviewManager manager;

    manager.addReview(r1, "Mia", "Good", 4);
    manager.addReview(r2, "Nina", "Bad", 2);
    manager.addReview(r3, "Owen", "Excellent", 5);

    EXPECT_TRUE(manager.isPositive(r1));
    EXPECT_FALSE(manager.isPositive(r2));
    EXPECT_TRUE(manager.isPositive(r3));
}

TEST(ReviewManagerTest, AddReviewWithEmptyValues) {
    Review review;
    ReviewManager manager;

    manager.addReview(review, "", "", 0);

    EXPECT_EQ(review.getAuthor(), "");
    EXPECT_EQ(review.getComment(), "");
    EXPECT_EQ(review.getRating(), 0);
}

TEST(ReviewManagerTest, IsPositiveBoundaryRating3) {
    Review review("Paul", "Average", 3);
    ReviewManager manager;

    EXPECT_FALSE(manager.isPositive(review));
}

TEST(ReviewManagerTest, IsPositiveBoundaryRating4) {
    Review review("Quinn", "Good", 4);
    ReviewManager manager;

    EXPECT_TRUE(manager.isPositive(review));
}
