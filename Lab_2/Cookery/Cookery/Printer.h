#pragma once
#include <iostream>

template <typename T>
class Printer {
public:
    virtual void print(const T& item) const = 0;
    virtual ~Printer() = default;
};
