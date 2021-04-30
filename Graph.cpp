#include "Graph.h"

using std::list;
using std::vector;

Graph::Graph(){
    node_ctr = 0;
}

int Graph::addNode(){
    adj_list[node_ctr] = list<int>();
    adj_matrix.push_back(vector<int>(node_ctr + 1, 0));

    for (int i = 0; i < adj_matrix.size()-1; i++){
        adj_matrix[i].push_back(0);
    }
    return node_ctr++;
}

void Graph::addEdge(int source, int dest, bool directed){
    adj_list[source].push_back(dest);
    adj_matrix[source][dest] = 1;
    if (!directed){
        adj_list[dest].push_back(source);
        adj_matrix[dest][source] = 1;
    }

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

void Graph::printMatrix(){
    printf("    ");
    for (int i = 0; i < adj_matrix.size(); i++){
        printf("%d ", i);
    }
    printf("\n----");
    for (int i = 0; i < adj_matrix.size(); i++){
        printf("--");
    }
    printf("\n");
    for (int i = 0; i < adj_matrix.size(); i++){
        printf("%d | ", i);
        for (int k = 0; k < adj_matrix[i].size(); k++){
            printf("%d ", adj_matrix[i][k]);
        }
        printf("\n");
    }
}

int Graph::traverse(int sources[], int goal, bool bfs){
    return 0;
}
