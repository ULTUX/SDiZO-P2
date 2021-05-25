//
// Created by Wladyslaw Nowak on 17.05.2021.
//

#include <stdexcept>
#include <iostream>
#include "MatrixRepresentation.h"

MatrixRepresentation::MatrixRepresentation(int vertSize, int edgeSize, int startVert, int endVert, bool isDirected)
        : vertSize(vertSize),
          edgeSize(edgeSize),
          startVert(startVert),
          endVert(endVert),
          isDirected(isDirected) {
    adjMatrix = new int *[vertSize];
    for (int i = 0; i < vertSize; i++) {
        adjMatrix[i] = new int[vertSize];
        for (int j = 0; j < vertSize; j++){
            adjMatrix[i][j] = 0;
        }
    }

}

void MatrixRepresentation::addConnection(int begin, int end, int weight) {
    if (isDirected) {
        if (begin < 0 || begin > vertSize || end < 0 || end > vertSize)
            throw std::invalid_argument("Invalid vertices were passed.");
        if ((adjMatrix[begin][end] == 0 && weight != 0 && currEdgeSize + 1 > edgeSize))
            throw std::logic_error("Graph is already completed, you can't add any more edges to this graph.");
        if (adjMatrix[begin][end] == 0 && weight != 0) {
            currEdgeSize++;
        }
        if (adjMatrix[begin][end] != 0 && weight == 0) currEdgeSize--;
        adjMatrix[begin][end] = weight;
    } else {
        if (begin < 0 || begin > vertSize || end < 0 || end > vertSize)
            throw std::invalid_argument("Invalid vertices were passed.");
        if (adjMatrix[begin][end] == 0 && weight != 0 && currEdgeSize + 1 > edgeSize)
            throw std::logic_error("Graph is already completed, you can't add any more edges to this graph.");
        if (adjMatrix[begin][end] == 0 && weight != 0) {
            currEdgeSize++;
        }
        if (adjMatrix[begin][end] != 0 && weight == 0) currEdgeSize--;
        adjMatrix[begin][end] = weight;
        adjMatrix[end][begin] = weight;
        print();
    }
}

int **MatrixRepresentation::getAdjMatrix() {
    if (currEdgeSize < edgeSize) throw std::logic_error("Graph was not fully created, waiting for more edges.");
    return this->adjMatrix;
}

void MatrixRepresentation::print() {
    std::cout<<std::endl;
    std::cout<<std::endl;
    for (int i = 0; i < vertSize; i++){
        for (int j = 0; j < vertSize; j++){
            std::cout<<adjMatrix[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
    std::cout<<std::endl;

}

void MatrixRepresentation::setEdgeSize(int n) {
    this->edgeSize = n;
}

void MatrixRepresentation::setVertSize(int n) {
    this->vertSize = n;
}

void MatrixRepresentation::setEndingVertex(int v) {
    this->endVert = v;
}

void MatrixRepresentation::setStartingVertex(int v) {
    this->startVert = v;
}
