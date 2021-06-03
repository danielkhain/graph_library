#include <iostream>
#include "Graph.h"

using namespace std;

int main() {
    Graph g;

    // Error checks for addEdge
    g.addEdge(1, 2, 1);
    g.addEdge(1, 1, 1);

    // Error checks for removeEdge
    g.removeEdge(1, 2);
    g.removeEdge(1, 1);

    g.addNode();
    g.addNode();
    g.addNode();
    g.addNode();
    g.addNode();

    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 4);
    g.addEdge(4, 1, 3);
    g.addEdge(3, 4, 1);

    cout << "Shortest Path Tests:\n";
    cout << "Now 1,1\n";
    cout << g.shortestPath(1,1) << endl;
    cout << "Now 1,2\n";
    cout << g.shortestPath(1,2) << endl;
    cout << "Now 2,4\n";
    cout << g.shortestPath(2,4) << endl;
    g.addNode();
    cout << g.shortestPath(1,5) << endl;
    cout << g.shortestPath(5,1) << endl;

    cout << "Doing MST!\n";
    g.addEdge(1,5,1);
    g.addEdge(2,5,1);
    g.addEdge(3,5,1);

    std::vector<std::pair<unsigned int, unsigned int>> minTree;
    cout << g.minimumSpanningTree(&minTree) << endl;
    g.printCSV();
    for (int i = 0; i < minTree.size(); i++){
        cout << minTree[i].first << "-" << minTree[i].second << endl;
    }


    g.printMatrix();

    g.removeEdge(0, 1);

    g.printMatrix();

    g.printCSV();

    cout << "Done!" << endl;
}
