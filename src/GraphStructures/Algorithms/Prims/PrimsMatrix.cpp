//
// Created by Wladyslaw Nowak on 20.05.2021.
//

#include <climits>
#include <iostream>
#include "PrimsMatrix.h"
using namespace std;
void PrimsMatrix::findMST() {
    int parent[vertSize];

    bool isIncluded[vertSize];

    int pathCost[vertSize];

    for (int i = 0; i < vertSize; i++){
        pathCost[i] = INT_MAX;
        isIncluded[i] = false;
    }
    pathCost[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < vertSize-1; i++){
        int currVert = findMin(pathCost, isIncluded);
        isIncluded[currVert] = true;
        for (int j = 0; j < vertSize; j++){
            if (adjMatrix[currVert][j] != 0 && !isIncluded[j] && adjMatrix[currVert][j] < pathCost[j]) {
                parent[j] = currVert;
                pathCost[j] = adjMatrix[currVert][j];
            }
        }
    }
    for (int i = 1; i < vertSize; i++){
        cout<<parent[i]<<" - "<<i<<" ("<<adjMatrix[i][parent[i]]<<endl;
    }

}

int PrimsMatrix::findMin(int *pathCost, bool *isIncluded) {
    int min = INT_MAX;
    int minIndex;
    for (int i = 0; i < vertSize; i++){
        if (!isIncluded[i] && pathCost[i] < min){
            min = pathCost[i];
            minIndex = i;
        }
    }
    return minIndex;
}
