#include "Review.h"

Review::Review(string a, string c, int r)
    : author(a), comment(c), rating(r),
    title(""), productName(""), date(""),
    reviewerEmail(""), likes(0), dislikes(0) {}

string Review::getAuthor() const { return author; }
string Review::getComment() const { return comment; }
int Review::getRating() const { return rating; }

void Review::setAuthor(const string& a) { author = a; }
void Review::setComment(const string& c) { comment = c; }
void Review::setRating(int r) { rating = r; }
