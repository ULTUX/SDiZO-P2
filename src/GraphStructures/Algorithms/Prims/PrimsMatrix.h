//
// Created by Wladyslaw Nowak on 20.05.2021.
//

#ifndef SDIZO2_PRIMSMATRIX_H
#define SDIZO2_PRIMSMATRIX_H


#include "../../MatrixRepresentation.h"
//TODO: Change findMst function to overridden start function
class PrimsMatrix: public MatrixRepresentation {

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
    PrimsMatrix(int vertSize, int edgeSize) : MatrixRepresentation(vertSize, edgeSize, 0, 0, false) {};


    /**
     * Start Kruskal algorithm.
     */
    void findMST();
};


#endif //SDIZO2_PRIMSMATRIX_H
