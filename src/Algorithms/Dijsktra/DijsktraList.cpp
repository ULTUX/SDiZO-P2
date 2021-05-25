//
// Created by Wladyslaw Nowak on 24.05.2021.
//

#include <climits>
#include <iostream>
#include "DijsktraList.h"

using namespace std;

int DijsktraList::findMin(int *shortestPath, bool *isIncluded) {
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

void DijsktraList::start() {
    int shortestPath[vertSize];
    bool isIncluded[vertSize];
    for (int i = 0; i < vertSize; i++) {
        shortestPath[i] = INT_MAX;
        isIncluded[i] = false;
    }
    shortestPath[startVert] = 0;
    for (int i = 0; i < vertSize - 1; i++) {
        int minVert = findMin(shortestPath, isIncluded);
        isIncluded[minVert] = true;
        for (int j = 0; j < adjLists[minVert]->getSize(); j++) {
            int adj = adjLists[minVert]->get(j).vertex;
            if (!isIncluded[adj] && shortestPath[minVert] != INT_MAX &&
                shortestPath[minVert] + adjLists[minVert]->get(j).edge < shortestPath[adj]) {
                shortestPath[adj] = shortestPath[minVert] + adjLists[minVert]->get(j).edge;
            }
        }
    }
    for (int i = 1; i < vertSize; i++) {
        cout << startVert << " - " << i << " (" << shortestPath[i] << ")" << endl;
    }
}
