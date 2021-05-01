#include <iostream>
#include "Graph.h"

using namespace std;

int main() {
    Graph g;

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
