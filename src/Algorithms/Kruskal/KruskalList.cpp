//
// Created by Władysław Nowak on 18/05/2021.
//

#include <climits>
#include <iostream>
#include "KruskalList.h"

using namespace std;
int KruskalList::find(int i) {
    while (parent[i] != i)
        i=parent[i];
    return i;
}

void KruskalList::unionVert(int i, int j) {
    parent[find(i)] = find(j);
}

void KruskalList::init() {
    this->parent = new int[vertSize];
    for (int i = 0; i < vertSize; i++){
        parent[i] = i;
    }
}

void KruskalList::start() {
    init();
    minCost = 0;
    if (isPrintOut) cout<<"Edge  Weight"<<endl;
    for (int i = 0; i < vertSize - 1; i++){
        int min = INT_MAX;
        int vert1, vert2;

        for (int x = 0; x < vertSize; x++) {
            for (int y = 0; y < adjLists[x]->getSize(); y++) {
                Connection con = adjLists[x]->get(y);
                if (find(con.vertex) != find(x) && con.edge < min) {
                    min = con.edge;
                    vert1 = x;
                    vert2 = con.vertex;
                }
            }
        }
            unionVert(vert1, vert2);
            if (isPrintOut) cout<<"("<<vert1 <<", "<<vert2<<") "<<min<<endl;
            minCost += min;
    }
    if (isPrintOut) cout<<"MST = "<<minCost<<endl<<endl;
}