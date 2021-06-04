//
// Created by Władysław Nowak on 18/05/2021.
//

#include <climits>
#include <iostream>
#include "KruskalList.h"

using namespace std;

int KruskalList::find(int i, int* parent) {
    while (parent[i] != i)
        i=parent[i];
    return i;
}

void KruskalList::unionVert(int i, int j, int* parent) {
    parent[find(i, parent)] = find(j, parent);
}


void KruskalList::start() {
    int minCost = 0;
    int* parent = new int[vertSize];
    for (int i = 0; i < vertSize; i++){
        parent[i] = i;
    }
    if (isPrintOut) cout<<"Edge  Weight"<<endl;
    for (int i = 0; i < vertSize - 1; i++){
        int min = INT_MAX;
        int vert1, vert2;

        for (int x = 0; x < vertSize; x++) {
            for (int y = 0; y < adjLists[x]->getSize(); y++) {
                Connection con = adjLists[x]->get(y);
                if (find(con.vertex, parent) != find(x, parent) && con.edge < min) {
                    min = con.edge;
                    vert1 = x;
                    vert2 = con.vertex;
                }
            }
        }
            unionVert(vert1, vert2, parent);
            if (isPrintOut) cout<<"("<<vert1 <<", "<<vert2<<") "<<min<<endl;
            minCost += min;
    }
    if (isPrintOut) cout<<"MST = "<<minCost<<endl<<endl;
    delete[] parent;
}