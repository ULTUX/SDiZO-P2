//
// Created by Wladyslaw Nowak on 24.05.2021.
//

#include <climits>
#include <iostream>
#include "FordFulkersonMatrix.h"
#include "../../util/Queue.h"
using namespace std;
bool FordFulkersonMatrix::bfs(int parent[]) {
    bool visited[vertSize];
    for (int i = 0; i < vertSize; i++){
        visited[i] = false;
    }
    Queue queue;
    queue.push(startVert);
    visited[startVert] = true;
    parent[startVert] = -1;

    while (!queue.isEmpty()) {
        int curr = queue.shift();
        for (int i = 0; i < vertSize; i++){
            if (residualGraph[curr][i] != 0 && !visited[i]){
                if (i == endVert) {
                    parent[i] = curr;
                    return true;
                }
                parent[i] = curr;
                visited[i] = true;
                queue.push(i);
            }
        }
    }
    return false;

}

void FordFulkersonMatrix::start() {
    residualGraph = new int*[vertSize];
    //Init residual matrix
    for (int i = 0; i < vertSize; i++){
        residualGraph[i] = new int[vertSize];
        for (int j = 0; j < vertSize; j++){
            residualGraph[i][j] = adjMatrix[i][j];
        }
    }
    int flow = 0;
    int parent[vertSize];
    while (bfs(parent)) {
        //Find min path
        int minFlow = INT_MAX;
        for (int i = endVert; i != startVert; i = parent[i]) {
            int from = parent[i];
            if (residualGraph[from][i] < minFlow) {
                minFlow = residualGraph[from][i];
            }
        }
        flow += minFlow;
        for (int i = endVert; i != startVert; i = parent[i]){
            int from = parent[i];
            residualGraph[from][i] -= minFlow;
            residualGraph[i][from] += minFlow;
        }
    }
    if (isPrintOut) {
        cout << "Edge Flow (max/used)" << endl;
        for (int i = 0; i < vertSize; i++) {
            for (int j = 0; j < vertSize; j++) {
                if (adjMatrix[i][j] != 0) {
                    cout << "(" << i << ", " << j << ")  " << adjMatrix[i][j] << " / " << residualGraph[j][i] << endl;
                }
            }
        }
        cout << "MAX_FLOW = " << flow << endl;
    }

}
