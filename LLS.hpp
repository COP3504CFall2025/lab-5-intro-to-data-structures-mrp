#pragma once

#include "Interfaces.hpp"
#include "LinkedList.hpp"
#include <stdlib.h>
#include <stdexcept>

template <typename T>
class LLS : public StackInterface<T> {
private:
    LinkedList<T> list;
public:
    // Constructor
    LLS(){
        
    }

    // Insertion
    void push(const T& item) override{
        list.addHead(item);
    }

    // Deletion
    T pop() override{
        T head_data = list.getHead()->data;
        if (list.removeHead()){
            return head_data;
        } else throw std::runtime_error("Stack empty");
    }

    // Access
    T peek() const override{
        if (getSize()==0) throw std::runtime_error("Stack empty");
        return list.getHead()->data;
    }

    //Getters
    std::size_t getSize() const noexcept override{
        return list.getCount();
    }
};