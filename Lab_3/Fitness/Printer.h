#pragma once
template<typename T>
class Printer {
public:
    virtual void print(const T& item) const = 0;
};
