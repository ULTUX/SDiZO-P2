//
// Created by Władysław Nowak on 18/05/2021.
//

#ifndef SDIZO2_KRUSKALLIST_H
#define SDIZO2_KRUSKALLIST_H


#include "../../GraphRepresentations/ListRepresentation.h"

/**
 * Kruskal algorithm adjacency list implementation.
 */
class KruskalList: public ListRepresentation {
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
    KruskalList(int vertSize, int edgeSize) : ListRepresentation(vertSize, edgeSize, 0, 0, false) {};

    /**
     * Start the algorithm.
     */
    void start() override;


};

#endif //SDIZO2_KRUSKALLIST_H
