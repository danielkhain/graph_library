// Copyright 2021 Daniel Khain

#include "Graph.h"
#include <time.h>
#include <iostream>
#include <queue>

using std::cout;
using std::endl;
using std::set;
using std::queue;
using std::vector;

int main() {
    Graph g;

    //////////////////////////////////
    /////////// PARAMETERS ///////////
    //////////////////////////////////

    int numNodes = 50;
    double transmission_coefficient = 0.3;


    ////////////////////////////////
    ///////// GRAPH SETUP //////////
    ////////////////////////////////

    int numEdges = 0;
    srand(time(NULL));
    g.setVerbose(false);

    // Add nodes
    for (int i = 0; i < numNodes; i++) {
        g.addNode();
    }

    // Add random edges
    for (int i = 0; i < numNodes; i++) {
        for (int k = 0; k < ((rand() % numNodes) / 15); k++) {
            g.addEdge(i, (rand() % numNodes), 1);
            numEdges++;
        }
    }


    //////////////////////////////////
    /// SAMPLE PROGRAM: INFECTIONS ///
    //////////////////////////////////

    vector<bool> infected(numNodes, false);
    unsigned int source = rand() % numNodes;

    queue<unsigned int> bfs_queue;

    bfs_queue.push(source);
    infected[source] = true;
    int numInfected = 1;
    cout << "Node " << source << " starts out infected!" << endl;

    while (!bfs_queue.empty()) {
        set<unsigned int> nbors;
        g.neighbors(bfs_queue.front(), nbors);
        bfs_queue.pop();

        auto it = nbors.begin();
        while (it != nbors.end()) {
            if (!infected[*it]) {
                if (rand() % 100 <= transmission_coefficient * 100) {
                    infected[*it] = true;
                    bfs_queue.push(*it);
                    cout << "Node " << *it << " was infected!" << endl;
                    numInfected++;
                }
            }
            it++;
        }
    }

    cout << "The number of infected nodes is  " << numInfected << "/"
         << numNodes << endl;
    cout << "The number of edges is " << numEdges << endl;
    cout << "The average degree of each node is " << numEdges / numNodes * 2
         << endl;
}
