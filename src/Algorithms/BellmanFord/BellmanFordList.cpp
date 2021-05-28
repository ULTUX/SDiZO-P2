//
// Created by Wladyslaw Nowak on 24.05.2021.
//

#include <climits>
#include <iostream>
#include "BellmanFordList.h"
using namespace std;
void BellmanFordList::start() {

    int shortestPath[vertSize];
    int parent[vertSize];

    for (int i = 0; i < vertSize; i++){
        shortestPath[i] = INT_MAX;
        parent[i] = INT_MAX;
    }

    shortestPath[startVert] = 0;
    parent[startVert] = -1;


    for (int i = 0; i < vertSize-1; i++){
        for (int j = 0; j < adjLists[i]->getSize(); j++){
            int dest = adjLists[i]->get(j).vertex;
            int edge = adjLists[i]->get(j).edge;
            if (shortestPath[i] != INT_MAX && shortestPath[i] + edge < shortestPath[dest]){
                shortestPath[dest] = shortestPath[i] + edge;
                parent[dest] = i;
            }
        }
    }

    //Fix negative weight cycles
    for (int i = 0; i < vertSize; i++){
        for (int j = 0; j < adjLists[i]->getSize(); j++){
            int dest = adjLists[i]->get(j).vertex;
            int edge = adjLists[i]->get(j).edge;
            if (shortestPath[j] == INT_MAX) continue;
            if (shortestPath[i] != INT_MAX && shortestPath[i] + edge < shortestPath[dest]) {
                if (isPrintOut) cout<<"Graph has negative cycles, stopping algorithm..."<<endl;
                return;
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
}

void BellmanFordList::printPath(int *parent, int vert) {
    int curr = vert;
    while (curr != -1){
        cout<<curr<<" ";
        curr = parent[curr];
    }
    cout<<endl;
}