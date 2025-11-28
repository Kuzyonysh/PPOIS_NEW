#include <gtest/gtest.h>
#include "Graph.h"

TEST(GraphTest, AddRemoveVertex) {
    Graph<int> g;
    EXPECT_TRUE(g.empty());

    g.addVertex();
    EXPECT_EQ(g.getVertexCount(), 1);
    g.addVertex();
    EXPECT_EQ(g.getVertexCount(), 2);

    g.removeVertex(0);
    EXPECT_EQ(g.getVertexCount(), 1);

    EXPECT_THROW(g.removeVertex(5), std::out_of_range);
}

TEST(GraphTest, AddRemoveEdge) {
    Graph<int> g(3);
    g.addEdge(0, 1);
    EXPECT_TRUE(g.hasEdge(0, 1));
    EXPECT_TRUE(g.hasEdge(1, 0));

    g.removeEdge(0, 1);
    EXPECT_FALSE(g.hasEdge(0, 1));
    EXPECT_FALSE(g.hasEdge(1, 0));

    EXPECT_THROW(g.addEdge(0, 5), std::out_of_range);
    EXPECT_THROW(g.removeEdge(0, 5), std::out_of_range);
}

TEST(GraphTest, DegreeVertex) {
    Graph<int> g(3);
    g.addEdge(0, 1);
    g.addEdge(0, 2);

    EXPECT_EQ(g.degreeVertex(0), 2);
    EXPECT_EQ(g.degreeVertex(1), 1);
    EXPECT_EQ(g.degreeEdge(), 2);

    EXPECT_THROW(g.degreeVertex(5), std::out_of_range);
}

TEST(GraphTest, AccessOperator) {
    Graph<int> g(2);
    g[0] = 10;
    g[1] = 20;

    EXPECT_EQ(g[0], 10);
    EXPECT_EQ(g.at(1), 20);
    EXPECT_THROW(g[5], std::out_of_range);
}

TEST(GraphTest, VertexIterator) {
    Graph<int> g;
    g.addVertex();
    g.addVertex();
    g[0] = 5;
    g[1] = 10;

    int sum = 0;
    for (auto it = g.begin(); it != g.end(); ++it) {
        sum += *it;
    }
    EXPECT_EQ(sum, 15);
}

TEST(GraphTest, AdjacentVertexIterator) {
    Graph<int> g(3);

    g[0] = 0;
    g[1] = 1;
    g[2] = 2;

    g.addEdge(0, 1);
    g.addEdge(0, 2);

    std::vector<int> adj;
    for (auto it = g.adjacentBegin(0); it != g.adjacentEnd(0); ++it) {
        adj.push_back(*it);
    }
    EXPECT_EQ(adj.size(), 2);
    EXPECT_NE(std::find(adj.begin(), adj.end(), 1), adj.end());
    EXPECT_NE(std::find(adj.begin(), adj.end(), 2), adj.end());
}

TEST(GraphTest, GraphComparison) {
    Graph<int> g1(2);
    Graph<int> g2(2);
    EXPECT_TRUE(g1 == g2);

    g1.addEdge(0, 1);
    EXPECT_TRUE(g1 != g2);
    EXPECT_TRUE(g1 > g2 || g2 < g1);
}

TEST(GraphTest, ClearGraph) {
    Graph<int> g(3);
    g.addEdge(0, 1);
    g.clear();
    EXPECT_TRUE(g.empty());
    EXPECT_EQ(g.getVertexCount(), 0);
    EXPECT_EQ(g.getEdgeCount(), 0);
}
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
