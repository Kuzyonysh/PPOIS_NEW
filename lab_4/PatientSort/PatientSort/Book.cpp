#include "Book.h"

Book::Book(string n, int p,int c) : name(n), pages(p), chapter(c) {}

string Book::getName() const { return name; }
int Book::getPages() const { return pages; }
int Book::getChapter()const { return chapter; }


void Book::setName(const string& newName) { name = newName; }
void Book::setPages(int newPages) { pages = newPages; }
void Book::setChapter(int newChapter) { chapter = newChapter; }

void Book::print() const {
    cout << name << " (" << pages << " pages, "<<chapter<<"chapters)" << endl;
}

bool compareByPages(const Book& a, const Book& b) {
    return a.getPages() < b.getPages();
}
bool compareByChapter(const Book& a, const Book & b) {
    return a.getChapter() < b.getChapter();
}
bool compareByName(const Book& a, const Book& b) {
    return a.getName() < b.getName();
}
