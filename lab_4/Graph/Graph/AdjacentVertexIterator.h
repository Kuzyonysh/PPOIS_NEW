#pragma once
#include <vector>
using namespace std;

template<typename T>
class AdjacentVertexIterator {
private:
    std::vector<T>* vertices;
    std::vector<std::vector<int>>* matrix;
    size_t vertex, current, n;

    void skipForward() { while (current < n && (*matrix)[vertex][current] == 0) ++current; }
    void skipBackward() { while (current > 0 && (*matrix)[vertex][current] == 0) --current; }

public:
    AdjacentVertexIterator(std::vector<T>* v, std::vector<std::vector<int>>* m, size_t vert, size_t start)
        : vertices(v), matrix(m), vertex(vert), current(start), n(v->size()) {
        skipForward();
    }

    T& operator*() { return (*vertices)[current]; }

    AdjacentVertexIterator& operator++() { ++current; skipForward(); return *this; }
    AdjacentVertexIterator operator++(int) { AdjacentVertexIterator tmp = *this; ++(*this); return tmp; }

    AdjacentVertexIterator& operator--() { --current; skipBackward(); return *this; }
    AdjacentVertexIterator operator--(int) { AdjacentVertexIterator tmp = *this; --(*this); return tmp; }

    bool operator==(const AdjacentVertexIterator& other) const { return vertices == other.vertices && vertex == other.vertex && current == other.current; }
    bool operator!=(const AdjacentVertexIterator& other) const { return !(*this == other); }
};
