#pragma once
#include <vector>
#include <utility>
using namespace std;

template<typename T>
class EdgeIterator {
private:
    std::vector<std::vector<int>>* matrix;
    size_t x, y, n;

    void skipForward() {
        while (x < n) {
            while (++y < n) if ((*matrix)[x][y] == 1) return;
            ++x;
            y = x;
        }
    }

    void skipBackward() {
        while (x < n && y < n) {
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
    EdgeIterator(std::vector<std::vector<int>>* m, size_t i, size_t j) : matrix(m), x(i), y(j), n(m->size()) {
        if (x < n && (y >= n || (*matrix)[x][y] == 0)) skipForward();
    }

    std::pair<size_t, size_t> operator*() const { return { x, y }; }

    EdgeIterator& operator++() { skipForward(); return *this; }
    EdgeIterator operator++(int) { EdgeIterator tmp = *this; ++(*this); return tmp; }

    EdgeIterator& operator--() { skipBackward(); return *this; }
    EdgeIterator operator--(int) { EdgeIterator tmp = *this; --(*this); return tmp; }

    bool operator==(const EdgeIterator& other) const { return matrix == other.matrix && x == other.x && y == other.y; }
    bool operator!=(const EdgeIterator& other) const { return !(*this == other); }
};
