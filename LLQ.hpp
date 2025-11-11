#pragma once

#include "Interfaces.hpp"
#include "LinkedList.hpp"
#include <stdlib.h>
#include <stdexcept>

template <typename T>
class LLQ : public QueueInterface<T> {
private:
    LinkedList<T> list;
public:
    // Constructor
    LLQ(){}

    // Insertion
    void enqueue(const T& item) override{
        list.addTail(item);
    }

    // Deletion
    T dequeue() override{
        if (!list.getHead()) throw std::runtime_error("Stack empty");

        T head_data = list.getHead()->data;
        
        list.removeHead();
        
        return head_data;
    }

    // Access
    T peek() const override{
        if (getSize()==0) throw std::runtime_error("Stack empty");
        return list.getHead()->data;
    }

    // Getter
    std::size_t getSize() const noexcept override{
        return list.getCount();
    }

};