#pragma once
#include <string>
using namespace std;

class IReview {
public:
    virtual ~IReview() = default;
    virtual string getAuthor() const = 0;
    virtual string getComment() const = 0;
    virtual int getRating() const = 0;
};
