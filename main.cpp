
#include <iostream>
#include "src/GraphStructures/util/AdjList.h"
#include "src/GraphStructures/Algorithms/Kruskal/KruskalMatrix.h"
#include "src/GraphStructures/Algorithms/Kruskal/KruskalList.h"
#include "src/GraphStructures/Algorithms/Prims/PrimsMatrix.h"
#include "src/GraphStructures/Algorithms/Prims/PrimsList.h"
#include "src/GraphStructures/Algorithms/Dijsktra/DijsktraMatrix.h"
#include "src/GraphStructures/Algorithms/Dijsktra/DijsktraList.h"
#include "src/GraphStructures/Algorithms/BellmanFord/BellmanFordList.h"
#include "src/GraphStructures/Algorithms/BellmanFord/BellmanFordMatrix.h"
#include "src/GraphStructures/Algorithms/FordFulkerson/FordFulkersonMatrix.h"
#include "src/GraphStructures/Algorithms/FordFulkerson/FordFulkersonList.h"

using namespace std;
int main() {
//    KruskalMatrix matrix(5, 7);
//    matrix.addConnection(0, 1, 4);
//    matrix.addConnection(0, 3, 1);
//    matrix.addConnection(0, 2, 2);
//    matrix.addConnection(1, 2, 3);
//    matrix.addConnection(2, 3, 7);
//    matrix.addConnection(2, 4, 6);
//    matrix.addConnection(3, 4, 5);
//    matrix.findMST();

//    KruskalList list(5,7);
//    list.addConnection(0, 1, 4);
//    list.addConnection(0, 3, 1);
//    list.addConnection(0, 2, 2);
//    list.addConnection(1, 2, 3);
//    list.addConnection(2, 3, 7);
//    list.addConnection(2, 4, 6);
//    list.addConnection(3, 4, 5);
//    list.findMst();
//    list.print();

//    PrimsList matrix(5, 7);
//    matrix.addConnection(0, 1, 4);
//    matrix.addConnection(0, 3, 1);
//    matrix.addConnection(0, 2, 2);
//    matrix.addConnection(1, 2, 3);
//    matrix.addConnection(2, 3, 7);
//    matrix.addConnection(2, 4, 6);
//    matrix.addConnection(3, 4, 5);
//    matrix.findMST();

//    DijsktraMatrix matrix(5, 7, 0);
//    matrix.addConnection(0, 1, 4);
//    matrix.addConnection(0, 3, 1);
//    matrix.addConnection(0, 2, 2);
//    matrix.addConnection(1, 2, 3);
//    matrix.addConnection(2, 3, 7);
//    matrix.addConnection(2, 4, 6);
//    matrix.addConnection(3, 4, 5);
//    matrix.start();

//    DijsktraList list(5, 7, 0);
//    list.addConnection(0, 1, 4);
//    list.addConnection(0, 3, 1);
//    list.addConnection(0, 2, 2);
//    list.addConnection(1, 2, 3);
//    list.addConnection(2, 3, 7);
//    list.addConnection(2, 4, 6);
//    list.addConnection(3, 4, 5);
//    list.start();

//    BellmanFordList list(6, 9, 0);
//    list.addConnection(0, 1, 10);
//    list.addConnection(0, 2, 20);
//    list.addConnection(1, 3, 50);
//    list.addConnection(1, 4, 10);
//    list.addConnection(2, 3, 20);
//    list.addConnection(2, 4, 33);
//    list.addConnection(3, 4, -20);
//    list.addConnection(3, 5, -2);
//    list.addConnection(4, 5, 1);
//    list.start();

//    BellmanFordMatrix matrix(6, 9, 0);
//    matrix.addConnection(0, 1, 10);
//    matrix.addConnection(0, 2, 20);
//    matrix.addConnection(1, 3, 50);
//    matrix.addConnection(1, 4, 10);
//    matrix.addConnection(2, 3, 20);
//    matrix.addConnection(2, 4, 33);
//    matrix.addConnection(3, 4, -20);
//    matrix.addConnection(3, 5, -2);
//    matrix.addConnection(4, 5, 1);
//    matrix.start();

    FordFulkersonMatrix matrix(5, 7, 0, 4);
    matrix.addConnection(0, 1, 4);
    matrix.addConnection(0, 3, 1);
    matrix.addConnection(0, 2, 2);
    matrix.addConnection(1, 2, 3);
    matrix.addConnection(2, 3, 7);
    matrix.addConnection(2, 4, 6);
    matrix.addConnection(3, 4, 5);
    matrix.start();

    FordFulkersonList  list(5, 7, 0, 4);
    list.addConnection(0, 1, 4);
    list.addConnection(0, 3, 1);
    list.addConnection(0, 2, 2);
    list.addConnection(1, 2, 3);
    list.addConnection(2, 3, 7);
    list.addConnection(2, 4, 6);
    list.addConnection(3, 4, 5);
    list.start();
    return 0;
}
