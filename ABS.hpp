#pragma once

#include <cstddef>
#include <stdexcept>
#include "Interfaces.hpp"

// Technically bad, but size_t isn't likely to conflict with any client code.
using std::size_t;

template<typename T>
class ABS : public StackInterface<T> {
public:
    // Big 5 + Parameterized Constructor
    ABS(){
        capacity_ = 1;
        curr_size_ = 0;
        array_ = new T[capacity_];
    }
    explicit ABS(const size_t capacity){
        capacity_ = capacity;
        curr_size_ = 0;
        array_ = new T[capacity_];
    }
    ABS(const ABS& other);
    ABS& operator=(const ABS& rhs);
    ABS(ABS&& other) noexcept;
    ABS& operator=(ABS&& rhs) noexcept;
    ~ABS() noexcept override;

    // Get the number of items in the ABS
    [[nodiscard]] size_t getSize() const noexcept override{
        return curr_size_;
    }

    // Get the max size of the ABS
    [[nodiscard]] size_t getMaxCapacity() const noexcept{
        return capacity_;
    }

    // Return underlying data for the stack
    [[nodiscard]] T* getData() const noexcept{
        return array_;
    }

    // Push item onto the stack
    void push(const T& data) override{
        if (curr_size_==capacity_){
            capacity_*=2;
            T* newArr = new T[capacity_];
            for (int i = 0; i < curr_size_; i++){
                newArr[i] = array_[i];
            }

            delete[] array_;
            array_ = newArr;
        }
        array_[curr_size_] = data;
        curr_size_++;
    }

    T peek() const override{
        return array_[curr_size_];
    }

    T pop() override{
        curr_size_--;
        return array_[curr_size_+1];
    }

private:
    size_t capacity_;
    size_t curr_size_;
    T* array_;
    static constexpr size_t scale_factor_ = 2;
};
