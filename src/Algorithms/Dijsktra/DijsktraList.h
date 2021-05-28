//
// Created by Wladyslaw Nowak on 24.05.2021.
//

#ifndef SDIZO2_DIJSKTRALIST_H
#define SDIZO2_DIJSKTRALIST_H

#include "../../GraphRepresentations/ListRepresentation.h"

/**
 * Dijsktra's algorithm adjacency list implementation. <br/>
 * Based on: https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm#Pseudocode.
 */
class DijsktraList: public ListRepresentation {
private:
    /**
     * Find next min vertex from not yet processed nodes.
     * @return Vertex number.
     */
    int findMin(int* shortestPath, bool* isIncluded);

    /**
     * Traverse and print path.
     * @param parent Parent to traverse.
     * @param starting vertex.
     */
    void printPath(int* parent, int vert);
public:
    /**
     * Create new graph.
     * @param vertSize Amount of vertices in this graph.
     * @param edgeSize Amount of edges in this graph.
     * @param startVert Starting vertex.
     */
    DijsktraList(int vertSize, int edgeSize, int startVert)
            : ListRepresentation(vertSize, edgeSize, startVert, 0, true){};
    /**
     * Start Dijsktra's algorithm.
     */
    void start() override;
};


#endif //SDIZO2_DIJSKTRALIST_H
