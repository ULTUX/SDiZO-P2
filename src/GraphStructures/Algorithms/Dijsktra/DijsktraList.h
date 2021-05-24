//
// Created by Wladyslaw Nowak on 24.05.2021.
//

#ifndef SDIZO2_DIJSKTRALIST_H
#define SDIZO2_DIJSKTRALIST_H

#include "../../ListRepresentation.h"

//TODO: Override start function.
class DijsktraList: public ListRepresentation {
private:
    /**
     * Find next min vertex from not yet processed nodes.
     * @return Vertex number.
     */
    int findMin(int* shortestPath, bool* isIncluded);
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
    void start();
};


#endif //SDIZO2_DIJSKTRALIST_H
