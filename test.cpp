#include <iostream>
#include "Graph.h"

using namespace std;

int main() {
    Graph g;

    g.addNode();
    g.addNode();

    g.addEdge(0, 1, 1);

    g.printMatrix();
    g.printList();

    cout << "Done!" << endl;
}
