//
// Created by Wladyslaw Nowak on 24.05.2021.
//

#include <climits>
#include <iostream>
#include "FordFulkersonList.h"
#include "../../util/Queue.h"

using namespace std;
bool FordFulkersonList::bfs(int parent[]) {
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
            if (!visited[i] && residualGraph[curr]->containsVert(i)){
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

void FordFulkersonList::start() {
    ListRepresentation* list = new ListRepresentation(vertSize, edgeSize, startVert, endVert, true);
    //Init residual matrix
    for (int i = 0; i < vertSize; i++){
        for (int j = 0; j < adjLists[i]->getSize(); j++){
            list->addConnection(i, adjLists[i]->get(j).vertex, adjLists[i]->get(j).edge);
        }
    }
    residualGraph = list->getAdjLists();
    int flow = 0;
    int parent[vertSize];
    while (bfs(parent)) {
        //Find min path
        int minFlow = INT_MAX;
        for (int i = endVert; i != startVert; i = parent[i]) {
            int from = parent[i];
            if (residualGraph[from]->containsVert(i) && residualGraph[from]->getByVert(i).edge < minFlow) {
                minFlow = residualGraph[from]->getByVert(i).edge;
            }
        }
        flow += minFlow;
        for (int i = endVert; i != startVert; i = parent[i]){
            int from = parent[i];
            residualGraph[from]->setEdge(i, residualGraph[from]->getByVert(i).edge - minFlow);
            if (!residualGraph[i]->containsVert(from)) {
                residualGraph[i]->add(Connection(from, minFlow));
            }
            else residualGraph[i]->setEdge(from, residualGraph[i]->getByVert(from).edge + minFlow);
        }
    }
    for (int i = 0; i < vertSize; i++){
        for (int j = 0; j < adjLists[i]->getSize(); j++){
            int remaining = 0;
            if (residualGraph[adjLists[i]->get(j).vertex]->containsVert(i)) remaining = residualGraph[adjLists[i]->get(j).vertex]->getByVert(i).edge;
            cout<<"("<<i<<", "<<adjLists[i]->get(j).vertex<<")  "<<adjLists[i]->get(j).edge<<" / "<<remaining<<endl;
        }
    }
    cout<<flow<<endl;
}
