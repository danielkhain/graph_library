#include <iostream>
#include "Graph.h"

using namespace std;

int main() {
    Graph g;

    cout << g.addNode();
    cout << g.addNode() << endl; 
    g.addEdge(0, 1);
    g.printList();

    cout << "Done!" << endl;
}
