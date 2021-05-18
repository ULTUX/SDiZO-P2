//
// Created by Władysław Nowak on 18/05/2021.
//

#include "KruskalMatrix.h"

void KruskalMatrix::findMST(int **graph) {

}

void KruskalMatrix::sort() {
    int lastMin;
    int ind = 0;
    for (int i = 0; i < vertSize; i++){
        for (int j = 0; j < vertSize; j++){
            minConnections[ind] = Connection(i, adjMatrix[i][j]);
        }
    }
}
