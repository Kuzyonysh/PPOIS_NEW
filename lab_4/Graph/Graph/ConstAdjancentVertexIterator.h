#pragma once
#include <cstddef>
#include <vector>
using namespace std;

template<typename T, typename MatrixType>
class ConstAdjacentVertexIterator {
private:
    const std::vector<T>* vertices;
    const MatrixType* matrix;
    size_t vertex, current, n;

    void skipForward() { while (current < n && (*matrix)[vertex][current] == 0) ++current; }
    void skipBackward() { while (current > 0 && (*matrix)[vertex][current] == 0) --current; }

public:
    using iterator_category = bidirectional_iterator_tag;
    using value_type = const T;
    using difference_type = ptrdiff_t;
    using reference = const value_type&;
    using pointer = const value_type*;

    ConstAdjacentVertexIterator(const std::vector<T>* verts, const MatrixType* mat, size_t v, size_t start)
        : vertices(verts), matrix(mat), vertex(v), current(start), n(verts->size()) {
        skipForward();
    }

    reference operator*() const { return (*vertices)[current]; }
    pointer operator->() const { return &(*vertices)[current]; }

    ConstAdjacentVertexIterator& operator++() { ++current; skipForward(); return *this; }
    ConstAdjacentVertexIterator operator++(int) { ConstAdjacentVertexIterator tmp = *this; ++(*this); return tmp; }

    ConstAdjacentVertexIterator& operator--() { --current; skipBackward(); return *this; }
    ConstAdjacentVertexIterator operator--(int) { ConstAdjacentVertexIterator tmp = *this; --(*this); return tmp; }

    bool operator==(const ConstAdjacentVertexIterator& other) const {
        return vertices == other.vertices && matrix == other.matrix &&
            vertex == other.vertex && current == other.current;
    }
    bool operator!=(const ConstAdjacentVertexIterator& other) const { return !(*this == other); }
};
