//
// Created by Władysław Nowak on 18/05/2021.
//

#include <climits>
#include <iostream>
#include "KruskalMatrix.h"
using namespace std;
void KruskalMatrix::start() {
    minCost = 0;
    init();
    for (int i = 0; i < vertSize-1; i++) {
        int minV1, minV2, min = INT_MAX;
        for (int x = 0; x < vertSize; x++){
            for (int y = 0; y < vertSize; y++){
                if (find(x) != find(y) && adjMatrix[x][y] < min && adjMatrix[x][y] != 0) {
                    min = adjMatrix[x][y];
                    minV1 = x;
                    minV2 = y;
                }
            }
        }
        cout<<"FOUND MIN: "<<min<<endl;
        cout<<minV1<<"---"<<minV2<<endl;
        unionVert(minV1, minV2);
        cout<<"Adding edge: "<<minV1 <<"--("<<min<<")---"<<minV2<<endl;
        minCost += min;
    }
    cout<<"Min cost: "<<minCost<<endl<<endl;
}


int KruskalMatrix::find(int i) {
    while (parent[i] != i)
        i=parent[i];
    return i;
}

void KruskalMatrix::unionVert(int i, int j) {
    parent[find(i)] = find(j);
}

void KruskalMatrix::init() {
    this->parent = new int[vertSize];
    for (int i = 0; i < vertSize; i++){
        parent[i] = i;
    }
}
