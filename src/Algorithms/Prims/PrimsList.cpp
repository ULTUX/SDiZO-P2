//
// Created by Wladyslaw Nowak on 20.05.2021.
//

#include <climits>
#include <iostream>
#include "PrimsList.h"
using namespace std;
void PrimsList::start() {
    int* parent = new int[vertSize];

    bool* isIncluded = new bool[vertSize];

    int* pathCost = new int[vertSize];

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
        for (int j = 0; j < adjLists[currVert]->getSize(); j++){
            auto vert = adjLists[currVert]->get(j);
            if (!isIncluded[vert.vertex] && vert.edge < pathCost[vert.vertex]) {
               parent[vert.vertex] = currVert;
               pathCost[vert.vertex] = vert.edge;
            }
        }
    }
    if (isPrintOut) {
        cout << "Edge  Weight" << endl;
        for (int i = 1; i < vertSize; i++) {
            if (parent[i] != INT_MAX) {
                cout << "(" << parent[i] << ", " << i << ") " << adjLists[parent[i]]->getByVert(i).edge << endl;
                minCost += pathCost[i];
            }
        }
        cout << "MST = " << minCost << endl;
    }
    delete[] parent;
    delete[] isIncluded;
    delete[] pathCost;
}

int PrimsList::findMin(int *pathCost, bool *isIncluded) {
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
