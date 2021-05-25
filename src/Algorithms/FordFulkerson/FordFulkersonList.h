//
// Created by Wladyslaw Nowak on 24.05.2021.
//

#ifndef SDIZO2_FORDFULKERSONLIST_H
#define SDIZO2_FORDFULKERSONLIST_H


#include "../../GraphRepresentations/ListRepresentation.h"

/**
 * Ford-Fulkerson list implementation. <br/>
 * Based on: https://www.geeksforgeeks.org/ford-fulkerson-algorithm-for-maximum-flow-problem/.
 */
class FordFulkersonList: public ListRepresentation{
private:
    /**
     * Use BFS algorithm to find path from s to t.
     * @param parent Array to create path.
     * @return True if there is path from start to end vertices.
     */
    bool bfs(int* parent);

    AdjList** residualGraph;
public:
    /**
     * Create new graph.
     * @param vertSize Amount of vertices in this graph.
     * @param edgeSize Amount of edges in this graph.
     * @param startVert Starting vertex.
     */
    FordFulkersonList(int vertSize, int edgeSize, int startVert, int endVert)
            : ListRepresentation(vertSize, edgeSize, startVert, endVert, true) {};
    /**
     * Start the algorithm.
     */
    void start() override;
};


#endif //SDIZO2_FORDFULKERSONLIST_H
