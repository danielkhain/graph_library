// Copyright 2021 Daniel Khain

#ifndef GRAPH_H_
#define GRAPH_H_

#include <unordered_map>
#include <set>
#include <vector>
#include <list>
#include <utility>
#include <limits>


class Graph {
 public:
    Graph();

    ///////////////////////////////
    ///// GRAPH MODIFICATIONS /////
    ///////////////////////////////

    int addNode();
    int addEdge(unsigned int, unsigned int, double);
    int removeEdge(unsigned int, unsigned int);

    ////////////////////////////////
    ////// GRAPH CALCULATIONS //////
    ////////////////////////////////

    int neighbors(unsigned int, std::set<unsigned int>&);
    double shortestPath(unsigned int, unsigned int);
    double minimumSpanningTree(std::vector<
                            std::pair<unsigned int, unsigned int>>* minTree);

    ////////////////////////////////
    /////// PRINTING HELPERS ///////
    ////////////////////////////////

    void setVerbose(bool);
    void printMatrix();
    void printCSV();

 private:
    std::vector<std::vector<double> > adj_matrix;
    unsigned int node_ctr;
    bool verbose;
    double inf = std::numeric_limits<double>::infinity();
};

#endif  // GRAPH_H_
