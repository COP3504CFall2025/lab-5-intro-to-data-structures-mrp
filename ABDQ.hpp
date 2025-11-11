#pragma once

#include <cstddef>
#include <stdexcept>
#include "Interfaces.hpp"
#include <utility>

template <typename T>
class ABDQ : public DequeInterface<T> {
private:
    T* data_;                 // underlying dynamic array
    std::size_t capacity_;    // total allocated capacity
    std::size_t size_;        // number of stored elements
    std::size_t front_;       // index of front element
    std::size_t back_;        // index after the last element (circular)

    static constexpr std::size_t SCALE_FACTOR = 2;

public:
    // Big 5
    ABDQ(){
        capacity_ = 4;
        size_ = 0;
        front_ = 0;
        back_ = 0;
        data_ = new T[capacity_];
    }
    explicit ABDQ(std::size_t capacity){
        capacity_ = capacity;
        size_ = 0;
        front_ = 0;
        back_ = 0;
        data_ = new T[capacity_];
    }
    ABDQ(const ABDQ& other){
        capacity_ = other.capacity_;
        size_ = other.size_;
        front_ = other.front_;
        back_ = other.back_;
        data_ = new T[capacity_];

        for (size_t i = 0; i < size_; i++){
            data_[i] = other.data_[i];
        }
    }
    ABDQ(ABDQ&& other) noexcept{
        capacity_ = other.capacity_;
        size_ = other.size_;
        front_ = other.front_;
        back_ = other.back_;
        data_ = other.data_;

        other.capacity_ = 0;
        other.size_ = 0;
        other.front_ = 0;
        other.back_ = 0;
        other.data_ = nullptr;
    }
    ABDQ& operator=(const ABDQ& other){
        if (this == &other) return *this;

        T* newArr = new T[other.capacity_];
        delete[] data_;
        
        capacity_ = other.capacity_;
        size_ = other.size_;
        front_ = other.front_;
        back_ = other.back_;
        data_ = newArr;

        for (size_t i = 0; i < size_; i++){
            data_[i] = other.data_[i];
        }

        return *this;

    }
    ABDQ& operator=(ABDQ&& other) noexcept{
        if (this == &other) return *this;
        delete[] data_;
        
        capacity_ = other.capacity_;
        size_ = other.size_;
        front_ = other.front_;
        back_ = other.back_;
        data_ = other.data_;

        other.capacity_ = 0;
        other.size_ = 0;
        other.front_ = 0;
        other.back_ = 0;
        other.data_ = nullptr;

        return *this;
    }
    ~ABDQ() override{
        capacity_ = 0;
        size_ = 0;
        front_ = 0;
        back_ = 0;
        delete[] data_;

        data_ = nullptr;
        
    }

    // Insertion
    void pushFront(const T& item) override{
        if (capacity_ == size_) {
            capacity_*= SCALE_FACTOR;
            T* newArr = new T[capacity_];
            for (size_t i = 0; i < size_; i++){
                newArr[i] = data_[i];
            }
            delete[] data_;
            data_ = newArr;
        }

        for (size_t i = size_; i>0; i--){
            data_[i] = data_[i-1];
        }

        data_[0] = item;
        size_++;
    }
    void pushBack(const T& item) override{
        if (capacity_ == size_) {
            capacity_*= SCALE_FACTOR;
            T* newArr = new T[capacity_];
            for (size_t i = 0; i < size_; i++){
                newArr[i] = data_[i];
            }
            delete[] data_;
            data_ = newArr;
        }

        data_[size_] = item;
        size_++;
    }

    // Deletion
    T popFront() override{
        if(size_==0) throw std::runtime_error("Deque Empty");

        T front = data_[0];

        for (size_t i = 1; i<size_; i++){
            data_[i-1] = data_[i];
        }

        size_--;

        if (size_ < capacity_/SCALE_FACTOR){
            capacity_/=SCALE_FACTOR;
            T* newArr = new T[capacity_];
            for (size_t i = 0; i < size_; i++){
                newArr[i] = data_[i];
            }
            delete[] data_;
            data_ = newArr;
        }

        return front;

    }
    T popBack() override{
        if(size_==0) throw std::runtime_error("Deque Empty");

        T back = data_[size_-1];

        size_--;

        if (size_ < capacity_/SCALE_FACTOR){
            capacity_/=SCALE_FACTOR;
            T* newArr = new T[capacity_];
            for (size_t i = 0; i < size_; i++){
                newArr[i] = data_[i];
            }
            delete[] data_;
            data_ = newArr;
        }

        return back;
    }

    // Access
    const T& front() const override{
        if(size_==0) throw std::runtime_error("Deque Empty");

        return data_[0];
    }
    const T& back() const override{
        if(size_==0) throw std::runtime_error("Deque Empty");

        return data_[size_-1];
    }

    // Getters
    std::size_t getSize() const noexcept override{
        return size_;
    }

};
