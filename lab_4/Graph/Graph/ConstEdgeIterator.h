#pragma once
#include <cstddef>
#include <utility>
using namespace std;

template<typename MatrixType>
class ConstEdgeIterator {
private:
    const MatrixType* matrix;
    size_t x, y, n;

    void skipForward() {
        while (x < n) {
            while (++y < n) if ((*matrix)[x][y] == 1) return;
            ++x;
            y = x;
        }
    }

    void skipBackward() {
        while (x < n) {
            while (y > 0) {
                --y;
                if ((*matrix)[x][y] == 1) return;
            }
            if (x == 0) break;
            --x;
            y = x;
        }
    }

public:
    using iterator_category = bidirectional_iterator_tag;
    using value_type = pair<size_t, size_t>;
    using difference_type = ptrdiff_t;
    using reference = value_type;
    using pointer = const value_type*;

    ConstEdgeIterator(const MatrixType* m, size_t i, size_t j)
        : matrix(m), x(i), y(j), n(m->size()) {
        if (x < n && (y >= n || (*matrix)[x][y] == 0)) skipForward();
    }

    reference operator*() const { return { x, y }; }

    ConstEdgeIterator& operator++() { skipForward(); return *this; }
    ConstEdgeIterator operator++(int) { ConstEdgeIterator tmp = *this; ++(*this); return tmp; }

    ConstEdgeIterator& operator--() { skipBackward(); return *this; }
    ConstEdgeIterator operator--(int) { ConstEdgeIterator tmp = *this; --(*this); return tmp; }

    bool operator==(const ConstEdgeIterator& other) const { return matrix == other.matrix && x == other.x && y == other.y; }
    bool operator!=(const ConstEdgeIterator& other) const { return !(*this == other); }
};
