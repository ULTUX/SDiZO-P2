//
// Created by Wladyslaw Nowak on 17.05.2021.
//

#ifndef SDIZO2_ADJLIST_H
#define SDIZO2_ADJLIST_H

#include "Connection.h"

/**
 * Represents single linked node in AdjList.
 */
class ListNode {
public:
    ListNode()= default;
    /**
     * Connection this node represents.
     */
    Connection data;
    /**
     * Ptr to next node.
     */
    struct ListNode *next = nullptr;
};

class AdjList {
private:
    /**
     * Head of this list.
     */
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

    /**
     * Delete vertex from list.
     * @param v Vertex to be deleted.
     */
    void deleteVert(int v);

    /**
     * Get size of this list.
     * @return Size
     */
    int getSize();

    /**
     * Get connection that includes this vertex.
     * @param v Vertex to look for.
     * @return
     */
    Connection getByVert(int v);

    /**
     * Set edge weight of given vertex's edge. If 0 is given the vertex will be deleted from list.
     * @param vert Given vertex.
     * @param weight Given weight to be set.
     */
    void setEdge(int vert, int weight);

};


#endif //SDIZO2_ADJLIST_H
