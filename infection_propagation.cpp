#include <iostream>
#include <queue>
#include "Graph.h"

using namespace std;

int main() {
    Graph g;
    int numNodes = 100;
    double transmission_coefficient = 0.5;

    //////////////////////////////////
    ////////// SET UP GRAPH //////////
    //////////////////////////////////

    // Add nodes
    for (int i = 0; i < numNodes; i++){
        g.addNode();
    }

    // Add edges
    for (int i = 0; i < numNodes; i++){
        g.addEdge(i, i*7 % numNodes, 0); // Fix the thingy and put in rand()...
        g.addEdge(i, i*23 % numNodes, 0);
        g.addEdge(i, i*85 % numNodes, 0);
        g.addEdge(i, i*17 % numNodes, 0);
        g.addEdge(i, i*15 % numNodes, 0);
    }

    g.printList();

    //////////////////////////////////
    /// SAMPLE PROGRAM: INFECTIONS ///
    //////////////////////////////////

    vector<bool> infected(numNodes, false);
    unsigned int source = 26;
    int numInfected = 1;

    queue<unsigned int> bfs_queue;

    bfs_queue.push(source);
    infected[source] = true;
    cout << "Node " << source << " starts out infected!" << endl;

    while(!bfs_queue.empty()){
        set<unsigned int> nbors;
        g.neighbors(bfs_queue.front(), nbors);
        bfs_queue.pop();

        auto it = nbors.begin();
        while(it != nbors.end()){
            if (!infected[*it]){
                infected[*it] = true;
                bfs_queue.push(*it);
                cout << "Node " << *it << " was infected!" << endl;
                numInfected++;
            }
            it++;
        }

    }

    cout << "The number of infected nodes is  " << numInfected << "/" << numNodes << endl;

}
