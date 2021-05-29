#include "Graph.h"


using std::set;
using std::vector;
using std::list;

Graph::Graph(){
    node_ctr = 0;
    verbose = true;
}



///////////////////////////////
///// GRAPH MODIFICATIONS /////
///////////////////////////////

// Add node to the graph
int Graph::addNode(){
    adj_list[node_ctr] = set<unsigned int>();
    adj_matrix.push_back(vector<int>(node_ctr + 1, 0));

    for (int i = 0; i < adj_matrix.size()-1; i++){
        adj_matrix[i].push_back(0);
    }
    !verbose ? : printf("Adding node %d.\n", node_ctr);
    return node_ctr++;
}

// Add edge to the graph
int Graph::addEdge(unsigned int source, unsigned int dest, int weight, bool directed){
    if (source >= node_ctr || dest >= node_ctr || source == dest){
        !verbose ? : printf("Error adding edge from %d to %d.\n", source, dest);
        return -1;
    }
    // adj_list[source].insert(dest);
    adj_matrix[source][dest] = weight;
    !verbose ? : printf("Adding edge from %d to %d.\n", source, dest);
    if (!directed){
        // adj_list[dest].insert(source);
        adj_matrix[dest][source] = weight;
        !verbose ? : printf("Adding edge from %d to %d.\n", dest, source);
    }
    return 0;

}

// Remove edge from graph
int Graph::removeEdge(unsigned int source, unsigned int dest, bool directed){
    if (source >= node_ctr || dest >= node_ctr || source == dest){
        !verbose ? : printf("Error removing edge from %d to %d.\n", source, dest);
        return -1;
    }

    // adj_list[source].erase(dest);
    adj_matrix[source][dest] = 0;
    !verbose ? : printf("Removing edge from %d to %d.\n", source, dest);
    if (!directed){
        // adj_list[dest].erase(source);
        adj_matrix[dest][source] = 0;
        !verbose ? : printf("Removing edge from %d to %d.\n", dest, source);
    }
    return 0;

}


////////////////////////////////
////// GRAPH CALCULATIONS //////
////////////////////////////////

// Returns a node's neighbors
int Graph::neighbors(unsigned int source, set<unsigned int>& nbors){
    if (source >= node_ctr){
        !verbose ? : printf("Node %d not in graph.\n", source);
        return -1;
    }

    for (int i = 0; i < adj_matrix.size(); i++){
        if (adj_matrix[source][i] != 0){
            nbors.insert(i);
        }
    }

    // nbors = adj_list[source];

    return 0;

}


////////////////////////////////
/////// PRINTING HELPERS ///////
////////////////////////////////

// Set flag for informative prints
void Graph::setVerbose(bool verbose_in){
    verbose = verbose_in;
}

// Print adjacency list
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
    printf("\n");
}

// Print adjacency matrix
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

// Print graph in CSV format
void Graph::printCSV(){
    printf("\n");
    for (int i = 0; i < adj_matrix.size(); i++){
        for (int k = 0; k < adj_matrix[i].size(); k++){
            printf("%d,", adj_matrix[i][k]);
        }
        printf("\n");
    }
}
