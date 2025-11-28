#pragma once
#include <vector>
using namespace std;

template<typename T>
class VertexIterator {
private:
    std::vector<T>* vertices;
    size_t index;
public:
    VertexIterator(std::vector<T>* v, size_t i) : vertices(v), index(i) {}
    T& operator*() { return (*vertices)[index]; }

    VertexIterator& operator++() { ++index; return *this; }
    VertexIterator operator++(int) { VertexIterator tmp = *this; ++(*this); return tmp; }

    VertexIterator& operator--() { --index; return *this; }
    VertexIterator operator--(int) { VertexIterator tmp = *this; --(*this); return tmp; }

    bool operator==(const VertexIterator& other) const { return vertices == other.vertices && index == other.index; }
    bool operator!=(const VertexIterator& other) const { return !(*this == other); }

    size_t getIndex() const { return index; }
};
