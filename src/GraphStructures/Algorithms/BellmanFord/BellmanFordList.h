//
// Created by Wladyslaw Nowak on 24.05.2021.
//

#ifndef SDIZO2_BELLMANFORDLIST_H
#define SDIZO2_BELLMANFORDLIST_H


#include "../../GraphRepresentations/ListRepresentation.h"

/**
 * Bellman-Ford algorithm adjacency list implementation. <br/>
 * Based on: https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm#Algorithm.
 */
class BellmanFordList: public ListRepresentation{
public:
    BellmanFordList(int vertSize, int edgeSize, int startVert)
            : ListRepresentation(vertSize, edgeSize, startVert, 0, true) {};
    /**
     * Start Bellman-Ford algorithm.
     */
    void start() override;
};


#endif //SDIZO2_BELLMANFORDLIST_H
