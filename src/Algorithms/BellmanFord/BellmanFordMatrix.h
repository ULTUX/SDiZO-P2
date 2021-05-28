//
// Created by Wladyslaw Nowak on 24.05.2021.
//

#ifndef SDIZO2_BELLMANFORDMATRIX_H
#define SDIZO2_BELLMANFORDMATRIX_H


#include "../../GraphRepresentations/MatrixRepresentation.h"

/**
 * Bellman-Ford algorithm adjacency matrix implementation. <br/>
 * Based on: https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm#Algorithm.
 */
class BellmanFordMatrix: public MatrixRepresentation{
private:
    /**
     * Traverse and print path.
     * @param parent Parent to traverse.
     * @param starting vertex.
     */
    void printPath(int *parent, int vert);
public:
    /**
     * Create new graph.
     * @param vertSize Amount of vertices in this graph.
     * @param edgeSize Amount of edges in this graph.
     * @param startVert Starting vertex.
     */
    BellmanFordMatrix(int vertSize, int edgeSize, int startVert)
            : MatrixRepresentation(vertSize, edgeSize, startVert, 0, true) {};
    /**
     * Start Bellman-Ford algorithm.
     */
    void start() override;
};


#endif //SDIZO2_BELLMANFORDMATRIX_H
