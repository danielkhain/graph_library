#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <unordered_map>
#include <set>
#include <vector>


class Graph {
public:
    Graph();
    int addNode();
    void addEdge(int, int, bool);
    void removeEdge(int, int, bool);
    void printList();
    int traverse(int[], int, bool);
    void printMatrix();
    int shortestPath(int, int);
    void printCSV();
    void setVerbose(bool);

private:
    std::unordered_map<int, std::set<int> > adj_list;
    std::vector<std::vector<int> > adj_matrix;
    int node_ctr;
    bool verbose;

};

// TODO:
// 1) Error checking for removeEdge



#endif /* _GRAPH_H_ */
