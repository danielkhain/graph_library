#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <unordered_map>
#include <set>
#include <vector>


class Graph {
public:
    Graph();
    void setVerbose(bool);

    int addNode();
    int addEdge(unsigned int, unsigned int, bool);
    int removeEdge(unsigned int, unsigned int, bool);

    int shortestPath(int, int); // NOT DONE
    int neighbors(unsigned int, std::set<unsigned int>&);
    int traverseBFS(unsigned int);

    void printList();
    void printMatrix();
    void printCSV();



private:
    std::unordered_map<int, std::set<unsigned int> > adj_list; // node -> list of nodes it connects to
    std::vector<std::vector<int> > adj_matrix;
    unsigned int node_ctr;
    bool verbose;

};

// TODO:
// 1) Error checking for removeEdge and addEdge
// 2) Remove node
// 3) Write program with covid ideas for this
// 4) Weights for adj_list
// 5) Traversal with custom function
// 6) Adjacent nodes
// 7) Fix formatting for prints

// Infections:
// Do a BFS traversal starting with infected node
// Custom function: mark neighbors infected with some coeff


#endif /* _GRAPH_H_ */
