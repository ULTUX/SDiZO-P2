
#include <iostream>
#include "src/GraphStructures/util/AdjList.h"
using namespace std;
int main() {
    AdjList list = AdjList(Connection(2, 3));
    list.add(Connection(2, 10));
    list.add(Connection(3, 10));
    list.deleteVert(3);
    list.print();
    cout<<list.findNodeWithVert(Connection(2, 10))->data.edge<<endl;
    std::cout<<list.containsVert(3);
    return 0;
}
