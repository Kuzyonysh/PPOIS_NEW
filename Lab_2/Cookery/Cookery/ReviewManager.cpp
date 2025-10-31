#include "ReviewManager.h"

void ReviewManager::addReview(Review& review, const string& author, const string& comment, int rating) {
    review.setAuthor(author);
    review.setComment(comment);
    review.setRating(rating);
    cout << "Review added: " << author << " — Rating: " << rating << endl;
}

bool ReviewManager::isPositive(const IReview& review) const {
    return review.getRating() >= 4;
}
