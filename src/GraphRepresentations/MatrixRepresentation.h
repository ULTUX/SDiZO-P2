//
// Created by Wladyslaw Nowak on 17.05.2021.
//

#ifndef SDIZO2_MATRIXREPRESENTATION_H
#define SDIZO2_MATRIXREPRESENTATION_H


class MatrixRepresentation {
protected:
    /**
     * Adjacency matrix.
     */
    int **adjMatrix;

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
    /**
     * Create new matrix representation, set all graph parameters and allocate new adjacency matrix.
     * @param vertSize Amount of vertices in this graph.
     * @param edgeSize Amount of edges in this graph.
     * @param startVert Starting vertex.
     * @param endVert Ending vertex.
     */
    MatrixRepresentation(int vertSize, int edgeSize, int startVert, int endVert, bool isDirected);

    virtual /**
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
     * @return 2D array vertSize x vertSize.
     * @throws logic_error If graph was not fully created.
     */
    int **getAdjMatrix();

    /**
     * Display whole matrix representation of this graph.
     */
    void print();

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
     * Set vertex size of this graph.
     * @param n Size.
     */
    void setVertSize(int n);

    /**
     * Set edge size of this graph.
     * @param n Size.
     */
    void setEdgeSize(int n);

};


#endif //SDIZO2_MATRIXREPRESENTATION_H
