#include "LinkedList.hpp"
#include <iostream>



void LinkedList::printForward() const {
    Node* curr = head;
    while (curr){
        std::cout << curr->data << std::endl;
        curr = curr->next;
    }
}

void LinkedList::printForward() const {
    Node* curr = tail;
    while (curr){
        std::cout << curr->data << std::endl;
        curr = curr->prev;
    }
}