//
// Created by Wladyslaw Nowak on 24.05.2021.
//

#ifndef SDIZO2_DIJSKTRAMATRIX_H
#define SDIZO2_DIJSKTRAMATRIX_H


#include "../../GraphRepresentations/MatrixRepresentation.h"
class DijsktraMatrix: public MatrixRepresentation {
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
    DijsktraMatrix(int vertSize, int edgeSize, int startVert)
            : MatrixRepresentation(vertSize, edgeSize, startVert, 0, true){};
    /**
     * Start Dijsktra's algorithm.
     */
    void start() override;
};


#endif //SDIZO2_DIJSKTRAMATRIX_H
