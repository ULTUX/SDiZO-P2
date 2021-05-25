//
// Created by Wladyslaw Nowak on 24.05.2021.
//

#ifndef SDIZO2_QUEUE_H
#define SDIZO2_QUEUE_H

/**
 * Simple queue implementation.
 */
class Queue {
private:
    /**
     * Array storing data.
     */
    int* arr = nullptr;
    /**
     * Current size of array.
     */
    int size = 0;
public:
    /**
     * Empty constructor.
     */
    Queue()= default;
    /**
     * Push new element into the queue.
     * @param val Element to be pushed.
     */
    void push(int val);
    /**
     * Remove first element from the queue.
     * @return First element in this queue.
     */
    int shift();

    /**
     * Is this queue empty.
     * @return Whether this queue is empty.
     */
    bool isEmpty();
};


#endif //SDIZO2_QUEUE_H
