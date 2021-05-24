//
// Created by Wladyslaw Nowak on 24.05.2021.
//

#ifndef SDIZO2_BELLMANFORDMATRIX_H
#define SDIZO2_BELLMANFORDMATRIX_H


#include "../../MatrixRepresentation.h"

class BellmanFordMatrix: public MatrixRepresentation{
private:
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
    void start();
};


#endif //SDIZO2_BELLMANFORDMATRIX_H
