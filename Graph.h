#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <unordered_map>
#include <set>
#include <vector>
#include <list>


class Graph {
public:
    Graph();

    ///////////////////////////////
    ///// GRAPH MODIFICATIONS /////
    ///////////////////////////////

    int addNode();
    int addEdge(unsigned int, unsigned int, double, bool);
    int removeEdge(unsigned int, unsigned int, bool);

    ////////////////////////////////
    ////// GRAPH CALCULATIONS //////
    ////////////////////////////////

    int neighbors(unsigned int, std::set<unsigned int>&);
    double shortestPath(unsigned int, unsigned int);
    double minimumSpanningTree(std::vector<std::pair<unsigned int, unsigned int>>& minTree);

    ////////////////////////////////
    /////// PRINTING HELPERS ///////
    ////////////////////////////////

    void setVerbose(bool);
    void printList();
    void printMatrix();
    void printCSV();

private:
    std::unordered_map<int, std::set<unsigned int> > adj_list; // node -> list of nodes it connects to
    std::vector<std::vector<double> > adj_matrix;
    unsigned int node_ctr;
    bool verbose;
    double inf = std::numeric_limits<double>::infinity();

};

#endif /* _GRAPH_H_ */
