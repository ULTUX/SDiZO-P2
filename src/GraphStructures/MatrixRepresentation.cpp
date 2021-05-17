//
// Created by Wladyslaw Nowak on 17.05.2021.
//

#include <stdexcept>
#include "MatrixRepresentation.h"

MatrixRepresentation::MatrixRepresentation(int vertSize, int edgeSize, int startVert, int endVert) : vertSize(vertSize),
                                                                                                     edgeSize(edgeSize),
                                                                                                     startVert(startVert),
                                                                                                     endVert(endVert) {
    adjMatrix = new int *[vertSize];
    for (int i = 0; i < vertSize; i++) {
        adjMatrix[i] = new int[vertSize];
        adjMatrix[i][i] = 0;
    }

}

void MatrixRepresentation::addConnection(int begin, int end, int weight) {
    if (begin < 0 || begin > vertSize || end < 0 || end > vertSize)
        throw std::invalid_argument("Invalid vertices were passed.");
    if ((adjMatrix[begin][end] == 0 && weight != 0 && currEdgeSize + 1 > edgeSize))
        throw std::logic_error("Graph is already completed, you can't add any more edges to this graph.");
    if (adjMatrix[begin][end] == 0 && weight != 0) {
        currEdgeSize++;
    }
    if (adjMatrix[begin][end] != 0 && weight == 0) currEdgeSize--;
    adjMatrix[begin][end] = weight;
}

int **MatrixRepresentation::getAdjMatrix() {
    if (currEdgeSize < edgeSize) throw std::logic_error("Graph was not fully created, waiting for more edges.");
    return this->adjMatrix;
}
