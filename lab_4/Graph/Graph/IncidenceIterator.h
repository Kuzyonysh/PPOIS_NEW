#pragma once
#include <vector>
#include <utility>
using namespace std;

template<typename T>
class IncidenceIterator {
private:
    std::vector<std::vector<int>>* matrix;
    size_t vertex, current, n;

    void skipForward() { while (current < n && (*matrix)[vertex][current] == 0) ++current; }
    void skipBackward() { while (current > 0 && (*matrix)[vertex][current] == 0) --current; }

public:
    IncidenceIterator(std::vector<std::vector<int>>* m, size_t v, size_t start)
        : matrix(m), vertex(v), current(start), n(m->size()) {
        skipForward();
    }

    std::pair<size_t, size_t> operator*() const { return { vertex, current }; }

    IncidenceIterator& operator++() { ++current; skipForward(); return *this; }
    IncidenceIterator operator++(int) { IncidenceIterator tmp = *this; ++(*this); return tmp; }

    IncidenceIterator& operator--() { --current; skipBackward(); return *this; }
    IncidenceIterator operator--(int) { IncidenceIterator tmp = *this; --(*this); return tmp; }

    bool operator==(const IncidenceIterator& other) const { return matrix == other.matrix && vertex == other.vertex && current == other.current; }
    bool operator!=(const IncidenceIterator& other) const { return !(*this == other); }
};
