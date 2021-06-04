//
// Created by Wladyslaw Nowak on 24.05.2021.
//

#include <climits>
#include <iostream>
#include "DijsktraMatrix.h"
using namespace std;
void DijsktraMatrix::start() {
    //Array storing bool values, true is vertex is included in spt.
    bool* isIncluded = new bool[vertSize];

    //Stores shortest path from start to given node
    int* shortestPath = new int[vertSize];

    int* parent = new int[vertSize];

    for (int i = 0; i < vertSize; i++) {
        isIncluded[i] = false;
        shortestPath[i] = INT_MAX;
        parent[i] = INT_MAX;
    }
    parent[startVert]=-1;
    shortestPath[startVert] = 0;
    for (int i = 0; i < vertSize - 1; i++) {
        int minV = findMin(shortestPath, isIncluded);
        isIncluded[minV] = true;
        for (int adj = 0; adj < vertSize; adj++) {
            if (!isIncluded[adj] && adjMatrix[minV][adj] != 0 && shortestPath[minV] != INT_MAX &&
                shortestPath[minV] + adjMatrix[minV][adj] < shortestPath[adj]){
                shortestPath[adj] = shortestPath[minV] + adjMatrix[minV][adj];
                parent[adj] = minV;
            }
        }
    }
    if (isPrintOut) {
        cout << "Start = " << startVert << endl;
        cout << "End Dist Path" << endl;
        for (int i = 1; i < vertSize; i++) {
            if (parent[i] != INT_MAX) {
                cout << i << " | " << shortestPath[i] << " | ";
                printPath(parent, i);
            }
        }
    }

    delete[] isIncluded;
    delete[] shortestPath;
    delete[] parent;
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
void DijsktraMatrix::printPath(int *parent, int vert) {
    int curr = vert;
    while (curr != -1){
        cout<<curr<<" ";
        curr = parent[curr];
    }
    cout<<endl;
}