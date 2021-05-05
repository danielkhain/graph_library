#include <iostream>
#include "Graph.h"

using namespace std;

int main() {
    Graph g;

    // Error checks for addEdge
    g.addEdge(1, 2, 1);
    g.addEdge(1, 1, 1);

    // Error checks for removeEdge
    g.removeEdge(1, 2, 1);
    g.removeEdge(1, 1, 1);

    g.addNode();
    g.addNode();
    g.addNode();
    g.addNode();
    g.addNode();

    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 0);
    g.addEdge(4, 1, 1);
    g.addEdge(3, 4, 0);

    g.printMatrix();
    g.printList();

    g.removeEdge(0, 1, 1);

    g.printMatrix();
    g.printList();

    g.printCSV();

    cout << "Done!" << endl;
}
