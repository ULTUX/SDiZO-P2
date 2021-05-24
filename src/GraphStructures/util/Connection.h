class Connection {
public:
    Connection(int vertex, int edge): edge(edge), vertex(vertex){};
    Connection(){};
    int edge;
    int vertex;
    void setEdge(int weight){this->edge = weight;};
    void setVert(int vert){this->vertex = vert;};
};