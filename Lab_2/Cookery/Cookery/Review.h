#pragma once
#include "IReview.h"
#include <string>
using namespace std;

class Review : public IReview {
private:
    string author;
    string comment;
    int rating;
    string title;
    string productName;
    string date;
    string reviewerEmail;
    int likes;
    int dislikes;

public:
    Review(string a = "Unknown", string c = "", int r = 0);

    string getAuthor() const override;
    string getComment() const override;
    int getRating() const override;

    void setAuthor(const string& a);
    void setComment(const string& c);
    void setRating(int r);
};
