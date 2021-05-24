//
// Created by Wladyslaw Nowak on 24.05.2021.
//

#ifndef SDIZO2_BELLMANFORDLIST_H
#define SDIZO2_BELLMANFORDLIST_H


#include "../../ListRepresentation.h"
//TODO: Override start function
class BellmanFordList: public ListRepresentation{
public:
    BellmanFordList(int vertSize, int edgeSize, int startVert)
            : ListRepresentation(vertSize, edgeSize, startVert, 0, true) {};
    /**
     * Start Bellman-Ford algorithm.
     */
    void start();
};


#endif //SDIZO2_BELLMANFORDLIST_H
