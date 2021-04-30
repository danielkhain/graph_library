#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <unordered_map>
#include <list>
#include <vector>


class Graph {
public:
    Graph();
    int addNode();
    void addEdge(int, int, bool);
    void printList();
    int traverse(int[], int, bool);
    void printMatrix();

private:
    std::unordered_map<int, std::list<int> > adj_list;
    std::vector<std::vector<int> > adj_matrix;
    int node_ctr;

};


#endif /* _GRAPH_H_ */
