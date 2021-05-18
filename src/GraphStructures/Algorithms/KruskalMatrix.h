//
// Created by Władysław Nowak on 18/05/2021.
//

#ifndef SDIZO2_KRUSKALMATRIX_H
#define SDIZO2_KRUSKALMATRIX_H


#include "../MatrixRepresentation.h"
#include "../util/AdjList.h"

class KruskalMatrix: MatrixRepresentation{
private:
    void findMST(int** graph);
    int** mst;
    void sort();
    Connection* minConnections;
public:
    KruskalMatrix(int vertSize, int edgeSize, int startVert, int endVert) : MatrixRepresentation(vertSize, edgeSize, startVert, endVert) {
        minConnections = new Connection[vertSize*vertSize];
    }

};


#endif //SDIZO2_KRUSKALMATRIX_H
