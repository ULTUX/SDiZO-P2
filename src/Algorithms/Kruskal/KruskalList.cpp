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
    for (int i = 0; i < vertSize; i++){
        parent[i] = i;
    }
}

void KruskalList::start() {
    init();

    minCost = 0;

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
            cout<<"Adding edge: "<<vert1 <<"--("<<min<<")---"<<vert2<<endl;
            minCost += min;
    }
    cout<<"Min cost: "<<minCost<<endl<<endl;

}

void KruskalList::print() {
    for (int i = 0; i < vertSize; i++){
        cout<<i<<": ";
        for (int j = 0; j < adjLists[i]->getSize(); j++){
            cout<<"("<<adjLists[i]->get(j).vertex<<", "<<adjLists[i]->get(j).edge<<") ";
        }
        cout<<endl;
    }
}
