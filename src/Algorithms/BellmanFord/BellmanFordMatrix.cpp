//
// Created by Wladyslaw Nowak on 24.05.2021.
//

#include <climits>
#include <iostream>
#include "BellmanFordMatrix.h"
using namespace std;
void BellmanFordMatrix::start() {

    int* shortestPath = new int[vertSize];
    int* parent = new int[vertSize];

    for (int i = 0; i < vertSize; i++){
        shortestPath[i] = INT_MAX;
        parent[i]= INT_MAX;
    }

    parent[startVert] = -1;
    shortestPath[startVert] = 0;

    bool wasRelaxation = false;
    for (int i = 0; i < vertSize-1; i++){
        wasRelaxation = false;
        for (int j = 0; j < vertSize; j++){
            int edge = adjMatrix[i][j];
            if (edge != 0 && shortestPath[i] != INT_MAX && shortestPath[i] + edge < shortestPath[j]){
                shortestPath[j] = shortestPath[i] + edge;
                parent[j] = i;
                wasRelaxation = true;
            }
        }
        if (!wasRelaxation) {
            if (isPrintOut) printResult(parent, shortestPath);
            return;
        }
    }

    //Fix negative weight cycles
    for (int i = 0; i < vertSize; i++){
        for (int j = 0; j < vertSize; j++){
            int edge = adjMatrix[i][j];
            if (shortestPath[j] == INT_MAX) continue;
            if (edge != 0 && shortestPath[i] != INT_MAX && shortestPath[i] + edge < shortestPath[j]) {
                if (isPrintOut) cout<<"Graph has negative cycles, stopping algorithm..."<<endl;
                return;
            }
        }
    }
    if (isPrintOut) printResult(parent, shortestPath);

    delete[] shortestPath;
    delete[] parent;
}
void BellmanFordMatrix::printPath(int *parent, int vert) {
    int curr = vert;
    while (curr != -1){
        cout<<curr<<" ";
        curr = parent[curr];
    }
    cout<<endl;
}

void BellmanFordMatrix::printResult(int *parent, int *shortestPath) {
    cout << "Start = " << startVert << endl;
    cout << "End Dist Path" << endl;
    for (int i = 1; i < vertSize; i++) {
        if (parent[i] != INT_MAX) {
            cout << i << " | " << shortestPath[i] << " | ";
            printPath(parent, i);
        }
    }
}
