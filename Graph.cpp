
#include "Graph.h"

using std::list;

Graph::Graph(){
    node_ctr = 0;
}

int Graph::addNode(){
    adj_list[node_ctr] = list<int>();
    return node_ctr++;
}

void Graph::addEdge(int source, int dest){
    adj_list[source].push_back(dest);
}

void Graph::printList(){
    auto it = adj_list.begin();
    while (it != adj_list.end()){
        printf("Node %d: ", it->first);
        auto it2 = it->second.begin();
        while(it2 != it->second.end()){
            printf("%d ", *it2);
            it2++;
        }
        printf("\n");
        it++;
    }
}
