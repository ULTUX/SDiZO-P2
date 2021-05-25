//
// Created by Wladyslaw Nowak on 24.05.2021.
//

#include <climits>
#include <iostream>
#include "DijsktraMatrix.h"
using namespace std;
void DijsktraMatrix::start() {
    //Array storing bool values, true is vertex is included in spt.
    bool isIncluded[vertSize];

    //Stores shortest path from start to given node
    int shortestPath[vertSize];

    for (int i = 0; i < vertSize; i++) {
        isIncluded[i] = false;
        shortestPath[i] = INT_MAX;
    }
    shortestPath[startVert] = 0;

    for (int i = 0; i < vertSize - 1; i++) {
        int minV = findMin(shortestPath, isIncluded);
        isIncluded[minV] = true;
        for (int adj = 0; adj < vertSize; adj++) {
            if (!isIncluded[adj] && adjMatrix[minV][adj] != 0 && shortestPath[minV] != INT_MAX &&
                shortestPath[minV] + adjMatrix[minV][adj] < shortestPath[adj]){
                shortestPath[adj] = shortestPath[minV] + adjMatrix[minV][adj];
            }
        }
    }
    for (int i = 1; i < vertSize; i++){
        cout<<startVert<<" - "<<i<<" ("<<shortestPath[i]<<")"<<endl;
    }
}

int DijsktraMatrix::findMin(int *shortestPath, bool *isIncluded) {
    int min = INT_MAX;
    int minIndex;
    for (int i = 0; i < vertSize; i++) {
        if (!isIncluded[i] && shortestPath[i] < min) {
            min = shortestPath[i];
            minIndex = i;
        }
    }
    return minIndex;
}
