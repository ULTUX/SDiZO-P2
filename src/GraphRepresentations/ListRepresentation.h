//
// Created by Wladyslaw Nowak on 17.05.2021.
//

#ifndef SDIZO2_LISTREPRESENTATION_H
#define SDIZO2_LISTREPRESENTATION_H


#include "../util/AdjList.h"

class ListRepresentation {

protected:

    /**
     * Adjacency list of this representation.
     */
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


    bool isDirected;
public:
    ListRepresentation(int vertSize, int edgeSize, int startVert, int endVert, bool isDirected);

    /**
     * Should the results be printed on the screen.
     */
    bool isPrintOut = true;

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
    AdjList** getAdjLists();

     /**
     * Start algorithm (for derived classes).
     */
     virtual void start(){};

    /**
    * Set starting vertex of this graph.
    * @param v Vertex num.
    */
    void setStartingVertex(int v);

    /**
     * Set ending vertex of this graph.
     * @param v Vertex num.
     */
    void setEndingVertex(int v);

    /**
     * Set vertex size of this graph. <br/>
     * WARNING: This operation completely clears graph data.
     * @param n Size.
     */
    void setVertSize(int n);

    /**
     * Set edge size oof this graph.
     * @param n Size.
     */
    void setEdgeSize(int n);

    /**
     * Print graph.
     */
    void print();

    /**
     * Clone graph data.
     * @param representation Object to be cloned from.
     */
    void clone(ListRepresentation* representation);

    bool getisDirected(){return isDirected;};

    /**
     * Returns true if this graph has negative weights.
     * @return True if this graph has negative edges.
     */
    bool hasNegativeWeights();
};


#endif //SDIZO2_LISTREPRESENTATION_H
