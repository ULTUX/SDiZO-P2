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
     * Find this vertex's node.
     * @param i Input node.
     * @return Master parent node.
     */
    int find(int i);

    /**
     * Union two vertices groups into one.
     * @param i Vertex 1.
     * @param j Vertex 2.
     */
    void unionVert(int i, int j);

    /**
     * Init algorithm.
     */
    void init();

    /**
     * Array of parent structure.
     */
    int *parent;

    /**
     * Minimum cost of this graph.
     */
    int minCost = -1;

     /**
     * Print Kruskal algorithm results.
     */
    void print();

public:
    KruskalList(int vertSize, int edgeSize) : ListRepresentation(vertSize, edgeSize, 0, 0, false) {
        parent = new int[vertSize];
    };

    /**
     * Start the algorithm.
     */
    void start() override;


};

#endif //SDIZO2_KRUSKALLIST_H
