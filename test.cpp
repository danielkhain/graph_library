#include <iostream>
#include "Graph.h"

using namespace std;

int main() {
    Graph g;

    // Error checks for addEdge
    g.addEdge(1, 2, 1, true);
    g.addEdge(1, 1, 1, true);

    // Error checks for removeEdge
    g.removeEdge(1, 2, 1);
    g.removeEdge(1, 1, 1);

    g.addNode();
    g.addNode();
    g.addNode();
    g.addNode();
    g.addNode();

    g.addEdge(0, 1, 1, true);
    g.addEdge(1, 2, 4, false);
    g.addEdge(4, 1, 3, true);
    g.addEdge(3, 4, 1, false);


    g.printMatrix();
    g.printList();

    g.removeEdge(0, 1, 1);

    g.printMatrix();
    g.printList();

    g.printCSV();

    cout << "Done!" << endl;
}
