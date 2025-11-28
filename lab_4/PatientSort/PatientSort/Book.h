#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string name;
    int pages;
    int chapter;
public:
    Book(string n, int p, int c);

    string getName() const;
    int getPages() const;
    int getChapter()const;

    void setName(const string& newName);
    void setPages(int newPages);
    void setChapter(int newChapter);

    void print() const;
};

bool compareByPages(const Book& a, const Book& b);
bool compareByChapter(const Book& a, const Book& b);
bool compareByName(const Book& a, const Book& b);

#endif 

