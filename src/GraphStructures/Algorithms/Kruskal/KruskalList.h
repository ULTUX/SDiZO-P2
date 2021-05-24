//
// Created by Władysław Nowak on 18/05/2021.
//

#ifndef SDIZO2_KRUSKALLIST_H
#define SDIZO2_KRUSKALLIST_H


#include "../../ListRepresentation.h"

class KruskalList: public ListRepresentation {
private:

    int find(int i);

    void unionVert(int i, int j);

    void init();

    int *parent;

    int minCost;

public:
    KruskalList(int vertSize, int edgeSize) : ListRepresentation(vertSize, edgeSize, 0, 0, false) {
        parent = new int[vertSize];
    };

    void findMst();

    void print();

};

#endif //SDIZO2_KRUSKALLIST_H
