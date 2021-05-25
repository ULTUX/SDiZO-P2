//
// Created by Wladyslaw Nowak on 24.05.2021.
//

#include <climits>
#include <iostream>
#include "BellmanFordMatrix.h"
using namespace std;
void BellmanFordMatrix::start() {

    int shortestPath[vertSize];
    for (int i = 0; i < vertSize; i++){
        shortestPath[i] = INT_MAX;
    }

    shortestPath[startVert] = 0;

    for (int i = 0; i < vertSize-1; i++){
        for (int j = 0; j < vertSize; j++){
            int edge = adjMatrix[i][j];
            if (edge != 0 && shortestPath[i] != INT_MAX && shortestPath[i] + edge < shortestPath[j]){
                shortestPath[j] = shortestPath[i] + edge;
            }
        }
    }

    //Fix negative weight cycles
    for (int i = 0; i < vertSize; i++){
        for (int j = 0; j < vertSize; j++){
            int edge = adjMatrix[i][j];
            if (edge != 0 && shortestPath[i] != INT_MAX && shortestPath[i] + edge < shortestPath[j]) {
                cout<<"Graph has negative cycles, stopping algorithm..."<<endl;
                return;
            }
        }
    }
    for (int i = 1; i < vertSize; i++) {
        cout << startVert << " - " << i << " (" << shortestPath[i] << ")" << endl;
    }
}
