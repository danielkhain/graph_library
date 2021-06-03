// Copyright 2021 Daniel Khain

#include "Graph.h"

int main() {
    Graph g;

    g.setVerbose(true);

    g.addNode();
    g.addNode();
    g.addNode();

    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 7);

    g.shortestPath(0, 2);
    g.printCSV();
}
