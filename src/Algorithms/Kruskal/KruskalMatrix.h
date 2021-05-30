//
// Created by Władysław Nowak on 18/05/2021.
//

#ifndef SDIZO2_KRUSKALMATRIX_H
#define SDIZO2_KRUSKALMATRIX_H


#include "../../GraphRepresentations/MatrixRepresentation.h"
#include "../../util/AdjList.h"

/**
 * Kruskal algorithm adjacency matrix implementation.
 */
class KruskalMatrix: public MatrixRepresentation{
private:

    /**
     * Find parent of input vertex.
     * @param i Input vertex.
     * @return Parent of this vertex.
     */
    int find(int i, int* parent);

    /**
     * Connect 2 groups into one.
     * @param i Vertex 1.
     * @param j Vertex 2.
     */
    void unionVert(int i, int j, int* parent);


public:
    /**
     * Create new graph.
     * @param vertSize Amount of vertices in this graph.
     * @param edgeSize Amount of edges in this graph.
     */
    KruskalMatrix(int vertSize, int edgeSize) : MatrixRepresentation(vertSize, edgeSize, 0, 0, false) {}

    /**
     * Start Kruskal algorithm.
     */
    void start() override;
};


#endif //SDIZO2_KRUSKALMATRIX_H
