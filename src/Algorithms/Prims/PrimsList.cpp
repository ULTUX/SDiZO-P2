//
// Created by Wladyslaw Nowak on 20.05.2021.
//

#include <climits>
#include <iostream>
#include "PrimsList.h"
using namespace std;
void PrimsList::start() {
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
        for (int j = 0; j < adjLists[currVert]->getSize(); j++){

           if (!isIncluded[adjLists[currVert]->get(j).vertex] && adjLists[currVert]->get(j).edge < pathCost[adjLists[currVert]->get(j).vertex]) {
               parent[adjLists[currVert]->get(j).vertex] = currVert;
               pathCost[adjLists[currVert]->get(j).vertex] = adjLists[currVert]->get(j).edge;
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
