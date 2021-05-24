//
// Created by Wladyslaw Nowak on 17.05.2021.
//

#include <stdexcept>
#include "ListRepresentation.h"

ListRepresentation::ListRepresentation(int vertSize, int edgeSize, int startVert, int endVert, bool isDirected) : vertSize(vertSize),
                                                                                                 edgeSize(edgeSize),
                                                                                                 startVert(startVert),
                                                                                                 endVert(endVert),
                                                                                                 isDirected(isDirected){
    adjLists = new AdjList*[vertSize];

    for (int i = 0; i < vertSize; i++) {
        adjLists[i] = new AdjList();
    }
}

void ListRepresentation::addConnection(int begin, int end, int weight) {
    if (isDirected){
        if (begin < 0 || begin > vertSize || end < 0 || end > vertSize)
            throw std::invalid_argument("Invalid vertices were passed.");
        if ((!adjLists[begin]->containsVert(end) && weight != 0 && currEdgeSize + 1 > edgeSize))
            throw std::logic_error("Graph is already completed, you can't add any more edges to this graph.");
        if (!adjLists[begin]->containsVert(end) && weight != 0) {
            adjLists[begin]->add(Connection(end, weight));
            currEdgeSize++;
        }
        else if (adjLists[begin]->containsVert(end) && weight == 0) {
            adjLists[begin]->deleteVert(end);
            currEdgeSize--;
        } else{
            adjLists[begin]->findNodeWithVert(Connection(end, weight))->data.edge = weight;
        }
    }
    else {
        if (begin < 0 || begin > vertSize || end < 0 || end > vertSize)
            throw std::invalid_argument("Invalid vertices were passed.");
        if ((!adjLists[begin]->containsVert(end) && weight != 0 && currEdgeSize + 1 > edgeSize))
            throw std::logic_error("Graph is already completed, you can't add any more edges to this graph.");
        if ((!adjLists[begin]->containsVert(end) && weight != 0 && currEdgeSize + 1 > edgeSize))
            throw std::logic_error("Graph is already completed, you can't add any more edges to this graph.");
        if (!adjLists[begin]->containsVert(end) && weight != 0) {
            adjLists[begin]->add(Connection(end, weight));
            adjLists[end]->add(Connection(begin, weight));
            currEdgeSize++;
        }
        else if (adjLists[begin]->containsVert(end) && weight == 0) {
            adjLists[begin]->deleteVert(end);
            adjLists[end]->deleteVert(begin);
            currEdgeSize--;
        }
        else{
            adjLists[begin]->findNodeWithVert(Connection(end, weight))->data.edge = weight;
            adjLists[end]->findNodeWithVert(Connection(begin, weight))->data.edge = weight;
        }
    }
}

AdjList **ListRepresentation::getAdjLists() {
    return this->adjLists;
}
