
#ifndef SDIZO2_CONNECTION_H
#define SDIZO2_CONNECTION_H
class Connection {
public:
    Connection(int vertex, int edge): edge(edge), vertex(vertex){};
    Connection(){};
    int edge;
    int vertex;
    void setEdge(int weight){
        edge = weight;
    };
    void setVert(int vert){
        vertex = vert;
    };
};
#endif