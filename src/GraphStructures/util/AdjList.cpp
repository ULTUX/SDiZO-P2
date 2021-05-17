//
// Created by Wladyslaw Nowak on 17.05.2021.
//

#include <stdexcept>
#include <iostream>
#include "AdjList.h"

AdjList::AdjList(Connection startValue) {
    head = new ListNode();
    head->data = startValue;
}

ListNode *AdjList::getLastElement() {
    ListNode* curr = head;
    if (head == nullptr) return nullptr;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    return curr;
}

void AdjList::add(Connection x) {
    if (head == nullptr) {
        head = new ListNode();
        head->data = x;
        return;
    }
    ListNode* node = findNodeWithVert(x);
    if (node != nullptr){
        node->data.edge = x.edge;
        node->data.vertex = x.vertex;
        return;
    }
    auto* newNode = new ListNode();
    getLastElement()->next =newNode;
    newNode->data = x;
}


ListNode *AdjList::findNode(Connection x) {
    if (head == nullptr) throw std::logic_error("AdjList is empty.");
    ListNode* curr = this->head;
    while (curr->next != nullptr && (curr->data.vertex != x.vertex && curr->data.edge != x.edge)) {
        curr = curr->next;
    }
    if ((curr->data.vertex != x.vertex && curr->data.edge != x.edge)) return nullptr;
    return curr;
}

ListNode *AdjList::findNodeWithVert(Connection x) {
    if (head == nullptr) throw std::logic_error("AdjList is empty.");
    ListNode* curr = this->head;
    while (curr->next != nullptr && (curr->data.vertex != x.vertex)) {
        curr = curr->next;
    }
    if ((curr->data.vertex != x.vertex)) return nullptr;
    return curr;
}


ListNode *AdjList::getAtIndex(int i) {
    ListNode* curr = head;
    int in = 0;
    if (head == nullptr) throw std::logic_error("AdjList is empty");
    while (curr->next != nullptr && in < i) {
        curr = curr->next;
        in++;
    }
    if (curr->next == nullptr && in < i) throw std::logic_error("Too high index.");
    return curr;
}

Connection AdjList::pop() {
    ListNode *curr = head;
    ListNode *lastElement = getLastElement();
    if (lastElement == nullptr) throw std::logic_error("AdjList is empty");
    if (lastElement == head) {
        Connection x = head->data;
        delete head;
        head = nullptr;
        return x;
    }
    while (curr->next != nullptr && curr->next != lastElement) {
        curr = curr->next;
    }
    if (curr->next == nullptr) throw std::logic_error("Unknown exception");
    curr->next = nullptr;
    Connection x = lastElement->data;
    delete lastElement;
    return x;
}
Connection AdjList::shift() {
    if (head == nullptr) throw std::logic_error("AdjList is empty.");
    Connection x = head->data;
    ListNode* newHead = head->next;
    delete head;
    head = newHead;
    return x;
}

Connection AdjList::get(int i) {
    return getAtIndex(i)->data;
}


int AdjList::indexOf(Connection x) {
    int in = 0;
    if (head == nullptr) throw std::logic_error("AdjList is empty.");
    ListNode* curr = head;
    while (curr->next != nullptr && (curr->data.vertex != x.vertex && curr->data.edge != x.edge)){
        curr = curr->next;
        in++;
    }
    if (curr->next == nullptr && (curr->data.vertex != x.vertex && curr->data.edge != x.edge))
        throw std::logic_error("AdjList does noe contain this value.");
    return in;
}

void AdjList::remove(int i) {
    if (head == nullptr) throw std::logic_error("AdjList is empty.");
    if (i == 0) {
        shift();
        return;
    }
    ListNode* prev = getAtIndex(i-1);
    ListNode* toDelete = prev->next;
    prev->next = toDelete->next;
    delete toDelete;
}

void AdjList::print() {
    ListNode* node = head;
    if (head == nullptr) return;
    while (node->next != nullptr) {
        std::cout<<"Vert: "<<node->data.vertex<<" "<<"Edge: "<<node->data.edge<<std::endl;
        node = node->next;
    }
    std::cout<<"Vert: "<<node->data.vertex<<" "<<"Edge: "<<node->data.edge<<std::endl;
}

bool AdjList::containsVert(int v) {
    bool contains = false;
    if (head == nullptr) return false;
    ListNode* curr = head;
    while (curr->next != nullptr && (curr->data.vertex != v)){
        curr = curr->next;
    }
    if (curr->next == nullptr && (curr->data.vertex != v))
        return false;
    return true;
}

ListNode *AdjList::getByVert(int v) {
    if (head == nullptr) return nullptr;
    ListNode* curr = head;
    while (curr->next != nullptr && (curr->data.vertex != v)){
        curr = curr->next;
    }
    if (curr->next == nullptr && (curr->data.vertex != v))
        return nullptr;
    return curr;
}

void AdjList::deleteVert(int v) {
    if (head == nullptr) throw std::logic_error("AdjList is empty.");
    ListNode* curr = head;
    if (head->data.vertex == v) {
        shift();
        return;
    }
    while (curr->next != nullptr && (curr->next->data.vertex != v)){
        curr = curr->next;
    }
    if (curr->next == nullptr && (curr->next->data.vertex != v)) throw std::logic_error("AdjList does not have this element.");
    ListNode* toDel = curr->next;
    curr->next=toDel->next;
    delete toDel;
}
