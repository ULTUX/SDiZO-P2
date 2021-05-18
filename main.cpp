
#include <iostream>
#include "src/GraphStructures/util/AdjList.h"
#include "src/GraphStructures/Algorithms/KruskalMatrix.h"
#include "src/GraphStructures/Algorithms/KruskalList.h"

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
    KruskalList list(5,7);
    list.addConnection(0, 1, 4);
    list.addConnection(0, 3, 1);
    list.addConnection(0, 2, 2);
    list.addConnection(1, 2, 3);
    list.addConnection(2, 3, 7);
    list.addConnection(2, 4, 6);
    list.addConnection(3, 4, 5);
    list.findMst();
//    list.print();
    return 0;
}
