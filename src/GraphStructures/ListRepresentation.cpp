//
// Created by Wladyslaw Nowak on 17.05.2021.
//

#include <stdexcept>
#include "ListRepresentation.h"

ListRepresentation::ListRepresentation(int vertSize, int edgeSize, int startVert, int endVert) : vertSize(vertSize),
                                                                                                 edgeSize(edgeSize),
                                                                                                 startVert(startVert),
                                                                                                 endVert(endVert) {
    adjLists = new AdjList*[vertSize];

    for (int i = 0; i < vertSize; i++) {
        adjLists[i] = new AdjList();
    }
}

void ListRepresentation::addConnection(int begin, int end, int weight) {
    if (begin < 0 || begin > vertSize || end < 0 || end > vertSize)
        throw std::invalid_argument("Invalid vertices were passed.");
    if ((!adjLists[begin]->containsVert(end) && weight != 0 && currEdgeSize + 1 > edgeSize))
        throw std::logic_error("Graph is already completed, you can't add any more edges to this graph.");
    if (!adjLists[begin]->containsVert(end) && weight != 0) {
        adjLists[begin]->add(Connection(end, weight));
        currEdgeSize++;
    }
    if (adjLists[begin]->containsVert(end) && weight == 0) {
        adjLists[begin]->deleteVert(end);
        currEdgeSize--;
    } else{
        adjLists[begin]->findNodeWithVert(Connection(end, weight))->data.edge = weight;
    }
}
