#pragma once
#include <cstddef>
#include <utility>
using namespace std;

template<typename MatrixType>
class ConstIncidenceIterator {
private:
    const MatrixType* matrix;
    size_t vertex, current, n;

    void skipForward() { while (current < n && (*matrix)[vertex][current] == 0) ++current; }
    void skipBackward() { while (current > 0 && (*matrix)[vertex][current] == 0) --current; }

public:
    using iterator_category = bidirectional_iterator_tag;
    using value_type = pair<size_t, size_t>;
    using difference_type = ptrdiff_t;
    using reference = value_type;
    using pointer = const value_type*;

    ConstIncidenceIterator(const MatrixType* m, size_t v, size_t start)
        : matrix(m), vertex(v), current(start), n(m->size()) {
        skipForward();
    }

    value_type operator*() const { return { vertex, current }; }

    ConstIncidenceIterator& operator++() { ++current; skipForward(); return *this; }
    ConstIncidenceIterator operator++(int) { ConstIncidenceIterator tmp = *this; ++(*this); return tmp; }

    ConstIncidenceIterator& operator--() { --current; skipBackward(); return *this; }
    ConstIncidenceIterator operator--(int) { ConstIncidenceIterator tmp = *this; --(*this); return tmp; }

    bool operator==(const ConstIncidenceIterator& other) const { return matrix == other.matrix && vertex == other.vertex && current == other.current; }
    bool operator!=(const ConstIncidenceIterator& other) const { return !(*this == other); }
};
