#pragma once
#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>

#include "VertexIterator.h"
#include "EdgeIterator.h"
#include "IncidenceIterator.h"
#include "AdjacentVertexIterator.h"

using namespace std;

template<typename T>
class Graph {
private:
    using MatrixType = vector<vector<int>>;
    vector<T> vertices;
    vector<vector<int>> matrix;

public:
    using value_type = T;
    using size_type = size_t;
    using reference = T&;
    using pointer = T*;
    using const_reference = const T&;
    using const_pointer = const T*;

    Graph() = default;
    Graph(size_t n) {
        vertices.resize(n);
        matrix.resize(n, vector<int>(n, 0));
    }

    Graph(const Graph& other) : vertices(other.vertices), matrix(other.matrix) {}
    ~Graph() = default;

    Graph& operator=(const Graph& other) {
        if (this != &other) {
            vertices = other.vertices;
            matrix = other.matrix;
        }
        return *this;
    }

    bool operator==(const Graph& other)const {
        return vertices == other.vertices && matrix == other.matrix;
    }
    bool operator!=(const Graph& other)const { return !(*this == other); }
    bool operator<(const Graph& other)const { return matrix < other.matrix; }
    bool operator>(const Graph& other)const { return other < *this; }
    bool operator<=(const Graph& other)const { return !(other < *this); }
    bool operator>=(const Graph& other)const { return !(*this > other); }

    reference operator[](size_t index) {
        if (index >= vertices.size()) throw out_of_range("Invalid index");
        return vertices[index];
    }

    const_reference operator[](size_t index) const {
        if (index >= vertices.size()) throw out_of_range("Invalid index");
        return vertices[index];
    }

    reference at(size_t index) {
        if (index >= vertices.size()) throw out_of_range("Invalid index");
        return vertices[index];
    }

    const_reference at(size_t index) const {
        if (index >= vertices.size()) throw out_of_range("Invalid index");
        return vertices[index];
    }

    void print()const {
        for (const auto& row : matrix) {
            for (int value : row) cout << value << " ";
            cout << endl;
        }
    }

    bool empty() const { return vertices.empty(); }
    void clear() { vertices.clear(); matrix.clear(); }
    size_t getVertexCount()const { return vertices.size(); }

    size_t getEdgeCount()const {
        size_t count = 0;
        for (size_t i = 0; i < vertices.size(); i++)
            for (size_t j = 0; j < vertices.size(); j++)
                if (matrix[i][j] == 1) count++;
        return count / 2;
    }

    bool hasVertex(size_t index)const { return index < vertices.size(); }
    bool hasEdge(size_t x, size_t y)const {
        if (x >= vertices.size() || y >= vertices.size()) throw out_of_range("Invalid value");
        return matrix[x][y] == 1;
    }

    void addVertex() {
        vertices.push_back(T());
        matrix.push_back(vector<int>(vertices.size(), 0));
        for (size_t i = 0; i < matrix.size() - 1; i++) matrix[i].push_back(0);
    }

    void addEdge(size_t x, size_t y) {
        if (x >= vertices.size() || y >= vertices.size()) throw out_of_range("Invalid value");
        matrix[x][y] = 1;
        matrix[y][x] = 1;
    }

    void removeVertex(size_t index) {
        if (index >= vertices.size()) throw out_of_range("Invalid index");
        vertices.erase(vertices.begin() + index);
        matrix.erase(matrix.begin() + index);
        for (auto& row : matrix) row.erase(row.begin() + index);
    }

    void removeEdge(size_t x, size_t y) {
        if (x >= vertices.size() || y >= vertices.size()) throw out_of_range("Invalid value");
        matrix[x][y] = 0;
        matrix[y][x] = 0;
    }

    size_t degreeVertex(size_t index) const {
        if (index >= vertices.size())throw out_of_range("Invalid index");
        size_t count = 0;
        for (size_t j = 0; j < vertices.size(); j++) if (matrix[index][j] == 1) count++;
        return count;
    }

    size_t degreeEdge()const {
        size_t totalDegree = 0;
        for (size_t i = 0; i < vertices.size(); i++) totalDegree += degreeVertex(i);
        return totalDegree / 2;
    }

    //Iterators
    VertexIterator<T> begin() { return VertexIterator<T>(&vertices, 0); }
    VertexIterator<T> end() { return VertexIterator<T>(&vertices, vertices.size()); }

    EdgeIterator<T> edgeBegin() { return EdgeIterator<T>(&matrix, 0, 0); }
    EdgeIterator<T> edgeEnd() { return EdgeIterator<T>(&matrix, matrix.size(), 0); }

    IncidenceIterator<T> incidentBegin(size_t v) { return IncidenceIterator<T>(&matrix, v, 0); }
    IncidenceIterator<T> incidentEnd(size_t v) { return IncidenceIterator<T>(&matrix, v, vertices.size()); }

    AdjacentVertexIterator<T> adjacentBegin(size_t v) { return AdjacentVertexIterator<T>(&vertices, &matrix, v, 0); }
    AdjacentVertexIterator<T> adjacentEnd(size_t v) { return AdjacentVertexIterator<T>(&vertices, &matrix, v, vertices.size()); }

    void removeVertex(VertexIterator<T> it) { removeVertex(it.getIndex()); }
};
