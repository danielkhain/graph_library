#include "Graph.h"

using std::set;
using std::vector;

Graph::Graph(){
    node_ctr = 0;
    verbose = true;
}

void Graph::setVerbose(bool verbose_in){
    verbose = verbose_in;
}

int Graph::addNode(){
    adj_list[node_ctr] = set<int>();
    adj_matrix.push_back(vector<int>(node_ctr + 1, 0));

    for (int i = 0; i < adj_matrix.size()-1; i++){
        adj_matrix[i].push_back(0);
    }
    !verbose ? : printf("Adding node %d.\n", node_ctr);
    return node_ctr++;
}

void Graph::addEdge(int source, int dest, bool directed){
    adj_list[source].insert(dest);
    adj_matrix[source][dest] = 1;
    !verbose ? : printf("Adding edge from %d to %d.\n", source, dest);
    if (!directed){
        adj_list[dest].insert(source);
        adj_matrix[dest][source] = 1;
        !verbose ? : printf("Adding edge from %d to %d.\n", dest, source);
    }

}

void Graph::removeEdge(int source, int dest, bool directed){
    adj_list[source].erase(dest);
    adj_matrix[source][dest] = 0;
    !verbose ? : printf("Removing edge from %d to %d.\n", source, dest);
    if (!directed){
        adj_list[dest].erase(source);
        adj_matrix[dest][source] = 0;
        !verbose ? : printf("Removing edge from %d to %d.\n", dest, source);
    }


}

void Graph::printList(){
    printf("\n");
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
    printf("\n    ");
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

void Graph::printCSV(){
    printf("\n");
    for (int i = 0; i < adj_matrix.size(); i++){
        for (int k = 0; k < adj_matrix[i].size(); k++){
            printf("%d,", adj_matrix[i][k]);
        }
        printf("\n");
    }
}

int Graph::traverse(int sources[], int goal, bool bfs){
    return 0;
}
