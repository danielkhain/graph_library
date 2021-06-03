// Copyright 2021 Daniel Khain

#include "Graph.h"
#include <limits>

using std::set;
using std::vector;
using std::list;
using std::pair;
using std::make_pair;

Graph::Graph() {
    node_ctr = 0;
    verbose = false;
}

///////////////////////////////
///// GRAPH MODIFICATIONS /////
///////////////////////////////

// Add node to the graph
int Graph::addNode() {
    adj_matrix.push_back(vector<double>(node_ctr + 1, inf));

    for (int i = 0; i < adj_matrix.size()-1; i++) {
        adj_matrix[i].push_back(std::numeric_limits<double>::infinity());
    }
    adj_matrix[node_ctr][node_ctr] = 0;
    !verbose ? : printf("Adding node %d.\n", node_ctr);
    return node_ctr++;
}

// Add edge to the graph
int Graph::addEdge(unsigned int source, unsigned int dest, double weight) {
    if (source >= node_ctr || dest >= node_ctr || source == dest) {
        !verbose ? : printf("Error adding edge from %d to %d.\n", source, dest);
        return -1;
    }
    adj_matrix[source][dest] = weight;
    !verbose ? : printf("Adding edge from %d to %d.\n", source, dest);
    adj_matrix[dest][source] = weight;
    !verbose ? : printf("Adding edge from %d to %d.\n", dest, source);
    return 0;
}

// Remove edge from graph
int Graph::removeEdge(unsigned int source, unsigned int dest) {
    if (source >= node_ctr || dest >= node_ctr || source == dest) {
        !verbose ? : printf("Error removing edge from %d to %d.\n", source,
                            dest);
        return -1;
    }

    adj_matrix[source][dest] = 0;
    !verbose ? : printf("Removing edge from %d to %d.\n", source, dest);
    adj_matrix[dest][source] = 0;
    !verbose ? : printf("Removing edge from %d to %d.\n", dest, source);
    return 0;
}


////////////////////////////////
////// GRAPH CALCULATIONS //////
////////////////////////////////

// Returns a node's neighbors
int Graph::neighbors(unsigned int source, set<unsigned int>& nbors) {
    if (source >= node_ctr) {
        !verbose ? : printf("Node %d not in graph.\n", source);
        return -1;
    }

    for (int i = 0; i < adj_matrix.size(); i++) {
        if ((source != i) && (adj_matrix[source][i] != inf)) {
            nbors.insert(i);
        }
    }

    return 0;
}

// Dijkstra's Shortest Path Algorithm
double Graph::shortestPath(unsigned int source, unsigned int dest) {
    set<unsigned int> tree;
    vector<double> distToNode(node_ctr, inf);
    vector<bool> visited(node_ctr, false);

    distToNode[source] = 0;
    int numIters = 0;

    while (numIters < node_ctr) {
        // Select closest unvisited node
        double min = inf;
        int min_index;
        for (int i = 0; i < node_ctr; i++) {
            if (!visited[i] && distToNode[i] <= min) {
                min = distToNode[i];
                min_index = i;
            }
        }

        visited[min_index] = true;

        set<unsigned int> nbors;
        neighbors(min_index, nbors);

        // Update distance to selected node's neighbors
        auto it = nbors.begin();
        while (it != nbors.end()) {
            if (!visited[*it] &&
                (!isinf(distToNode[min_index]) &&
                !isinf(adj_matrix[*it][min_index])) &&
                (distToNode[min_index] + adj_matrix[*it][min_index] <
                                         distToNode[*it])) {
                distToNode[*it] = distToNode[min_index] +
                                  adj_matrix[*it][min_index];
            }
            it++;
        }
        numIters++;
    }
    !verbose ? : printf("The shortest path from node %d to %d is %f.\n",
                        source, dest, distToNode[dest]);
    return distToNode[dest];
}

// Prim's Minimum Spanning Tree Algorithm
double Graph::minimumSpanningTree(vector<pair<unsigned int,
                                              unsigned int>>* minTree) {
    vector<unsigned int> included(node_ctr, false);
    vector<double> value(node_ctr, inf);
    vector<unsigned int> mostRecentNode(node_ctr, 0);
    int numIncluded = 0;
    double MSTWeight = 0;

    value[0] = 0;

    while (numIncluded < node_ctr) {
        numIncluded++;

        double min = inf;
        int minIndex = 0;
        for (int i = 0; i < node_ctr; i++) {
            if (!included[i] && value[i] < min) {
                min = value[i];
                minIndex = i;
            }
        }

        included[minIndex] = true;
        if (minIndex != 0) {
            minTree->push_back(make_pair(minIndex, mostRecentNode[minIndex]));
        }

        MSTWeight += min;


        set<unsigned int> nbors;
        neighbors(minIndex, nbors);

        // Update distance to selected node's neighbors
        auto it = nbors.begin();
        while (it != nbors.end()) {
            if ((!included[*it]) && (adj_matrix[*it][minIndex] < value[*it])) {
                value[*it] = adj_matrix[*it][minIndex];
                mostRecentNode[*it] = minIndex;
            }

            it++;
        }
    }
    !verbose ? : printf("The weight of the minimum spanning tree is %f.\n",
                        MSTWeight);
    return MSTWeight;
}


////////////////////////////////
/////// PRINTING HELPERS ///////
////////////////////////////////

// Set flag for informative prints
void Graph::setVerbose(bool verbose_in) {
    verbose = verbose_in;
}

// Print graph in CSV format
void Graph::printCSV() {
    printf("\n");
    for (int i = 0; i < adj_matrix.size(); i++) {
        for (int k = 0; k < adj_matrix[i].size(); k++) {
            printf("%f,", adj_matrix[i][k]);
        }
        printf("\n");
    }
}
