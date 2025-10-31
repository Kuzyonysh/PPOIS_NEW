#pragma once
#include <iostream>
#include "Review.h"
using namespace std;

class ReviewManager {
public:
    void addReview(Review& review, const string& author, const string& comment, int rating);
    bool isPositive(const IReview& review) const;
};

