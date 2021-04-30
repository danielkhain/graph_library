#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <unordered_map>
#include <list>


class Graph {
public:
    Graph();
    int addNode();
    void addEdge(int, int);
    void printList();

private:
    std::unordered_map<int, std::list<int> > adj_list;
    int node_ctr;

};


#endif /* _GRAPH_H_ */
