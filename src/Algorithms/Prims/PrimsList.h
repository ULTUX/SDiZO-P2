//
// Created by Wladyslaw Nowak on 20.05.2021.
//

#ifndef SDIZO2_PRIMSLIST_H
#define SDIZO2_PRIMSLIST_H


#include "../../GraphRepresentations/ListRepresentation.h"

/**
 * Prims list graph algorithm.
 */
class PrimsList: public ListRepresentation{

    /**
      * Find next vertex with min value.
      * @param key
      * @param mstSet
      * @return
      */
    int findMin(int pathCost[], bool isIncluded[]);



public:
    /**
     * Create new graph.
     * @param vertSize Amount of vertices in this graph.
     * @param edgeSize Amount of edges in this graph.
     */
    PrimsList(int vertSize, int edgeSize) : ListRepresentation(vertSize, edgeSize, 0, 0, false) {};


    /**
     * Start Kruskal algorithm.
     */
    void start() override;

};


#endif //SDIZO2_PRIMSLIST_H
