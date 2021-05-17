//
// Created by Wladyslaw Nowak on 17.05.2021.
//

#ifndef SDIZO2_LISTREPRESENTATION_H
#define SDIZO2_LISTREPRESENTATION_H


#include "util/AdjList.h"

class ListRepresentation {

private:

    AdjList** adjLists;

    /**
     * Amount of vertices in this graph.
     */
    int vertSize;

    /**
     * Amount of edges in this graph.
     */
    int edgeSize;

    /**
     * Starting vertex.
     */
    int startVert;

    /**
     * Ending vertex.
     */
    int endVert;

    /**
     * Current amount of edges in this graph (must be lower than edgeSize).
     */
    int currEdgeSize = 0;

public:
    ListRepresentation(int vertSize, int edgeSize, int startVert, int endVert);

    /**
     * Add new connection to this graph (new edge).
     * @param begin Edges starting vertex.
     * @param end Edges ending vertex.
     * @param weight Weight of edge.
     * @throws invalid_argument If wrong parameters were passed.
     * @throws logic_error If edgeSize is reached.
     */
    void addConnection(int begin, int end, int weight);

    /**
     * Get adjacency matrix.
     * @return Array of lists.
     * @throws logic_error If graph was not fully created.
     */
    int *getAdjLists();
};


#endif //SDIZO2_LISTREPRESENTATION_H
