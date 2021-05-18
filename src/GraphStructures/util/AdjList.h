//
// Created by Wladyslaw Nowak on 17.05.2021.
//

#ifndef SDIZO2_ADJLIST_H
#define SDIZO2_ADJLIST_H

class Connection {
public:
    Connection(int vertex, int edge): edge(edge), vertex(vertex){};
    Connection(){};
    int edge;
    int vertex;
};

class ListNode {
public:
    ListNode(){};
    Connection data;
    struct ListNode *next = nullptr;
};

class AdjList {
private:
    ListNode *head = nullptr;

    /**
     * Get last element of this list.
     * @return Node that is last in this list.
     */
    ListNode *getLastElement();

    /**
     * Search and return list element with selected value.
     * @param x Value to be searched for.
     * @return Node that is holding that value.
     * @throws illegal_argument If list is empty.
     */
    ListNode *findNode(Connection x);

    /**
     * Get node at index.
     * @param i Index.
     * @return Node at index.
     * @throws illegal_argument If list is empty or index too high.
     */
    ListNode *getAtIndex(int i);

    ListNode* getByVert(int v);

public:
    /**
     * Init new list with starting value.
     * @param startValue Value to init the list with.
     */
    explicit AdjList(Connection startValue);

    /**
     * For creating arrays, empty lists.
     */
    explicit AdjList() {};

    /**
     * Add new element to this list.
     * @param x Element to be added.
     */
    void add(Connection x);


    /**
     * Remove elemet at index.
     * @param i Index
     * @throws illegal_argument If list is empty.
     */
    void remove(int i);

    /**
     * Remove last element from this list.
     * @return Removed element.
     * @throws out_of_range If list is empty.
     */
    Connection pop();

    /**
     * Remove first element from this list.
     * @return Removed element.
     * @throws out_of_range If list is empty.
     */
    Connection shift();

    /**
     * Get i-th element from this array.
     * @param i Index of element to get returned.
     * @return Element at given index.
     * @throws illegal_argument If invalid index was given.
     */
    Connection get(int i);

    /**
     * Print this node.
     */
    void print();

    /**
     * Get index of element.
     * @param x Element.
     * @return Index.
     * @throws illegal_argument If list is empty or element does not exist.
     */
    int indexOf(Connection x);

    ListNode *findNodeWithVert(Connection x);

    /**
     * Check if this list contains vertex.
     * @param v Vertex
     * @return If this vertex is present.
     */
    bool containsVert(int v);

    void deleteVert(int v);

};


#endif //SDIZO2_ADJLIST_H