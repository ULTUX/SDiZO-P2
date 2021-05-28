//
// Created by Wladyslaw Nowak on 20.05.2021.
//

#include <climits>
#include <iostream>
#include "PrimsMatrix.h"
using namespace std;
void PrimsMatrix::start() {
    int parent[vertSize];

    bool isIncluded[vertSize];

    int pathCost[vertSize];

    for (int i = 0; i < vertSize; i++){
        pathCost[i] = INT_MAX;
        isIncluded[i] = false;
        parent[i] = INT_MAX;
    }
    pathCost[0] = 0;
    parent[0] = -1;
    int minCost = 0;
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
    if (isPrintOut) {
        cout<<"Edge  Weight"<<endl;
        for (int i = 1; i < vertSize; i++){
            if (parent[i] != INT_MAX) {
                cout << "(" << parent[i] << ", " << i << ") " << adjMatrix[parent[i]][i] << endl;
                minCost += pathCost[i];
            }
        }
        cout<<"MST = "<<minCost<<endl;
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
