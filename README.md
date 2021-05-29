# Graph Library

## Sample Program: Infections on a Network
The Graph Library can be used to model an infection spreading through a network.
### Running Instructions
1. `make clean`
2. `make infection`
3. `./infection`

### Description
This sample program creates a random graph with `numNodes` nodes.
A randomly selected node is then infected.
The infection spreads with a defined transmission coefficient and can only be spread to neighbors.
The program first iterates through the initially-infected node's neighbors, infecting them with `transmission_coefficient` probability.
Then, the same occurs to each newly infected node.
Finally, some statistics are printed out.

### Example
This program was run with 50 nodes and a transmission coefficient of 0.3.
The resulting infection graph can be seen below (visualization courtesy of https://graphonline.ru/en/).
The initially infected node is colored pink, and the resultant infected nodes are beige.
In this simulation, 8/50 nodes were infected.
The number of edges is 56.
The average degree of each node is 2.

![](network.png)
