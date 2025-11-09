#pragma once

#include <cstddef>
#include <stdexcept>
#include "Interfaces.hpp"

// Technically bad, but size_t isn't likely to conflict with any client code.
using std::size_t;

template<typename T>
class ABQ : public QueueInterface<T>{
private:
    size_t capacity_;
    size_t curr_size_;
    T* array_;
    static constexpr size_t scale_factor_ = 2;

public:
    // Constructors + Big 5
    ABQ() : capacity_(1), curr_size_(0), array_(new T[1]) {}
    explicit ABQ(const size_t capacity): capacity_(capacity), curr_size_(0), array_(new T[capacity]){}
    ABQ(const ABQ& other){
        capacity_ = other.capacity_;
        curr_size_ = other.curr_size_;
        array_ = new T[capacity_];
        for(size_t i = 0; i < curr_size_; ++i){
            array_[i] = other.array_[i];
        }
    }
    ABQ& operator=(const ABQ& rhs) {
    if (this != &rhs) {
        delete[] array_;
        capacity_ = rhs.capacity_;
        curr_size_ = rhs.curr_size_;
        array_ = new T[capacity_];
        for (size_t i = 0; i < curr_size_; ++i) {
            array_[i] = rhs.array_[i];
        }
    }
    return *this;
}
    ABQ(ABQ&& other) noexcept{
    capacity_ = other.capacity_;
    curr_size_ = other.curr_size_;
    array_ = other.array_;
    other.array_ = nullptr;
    other.capacity_ = 0;
    other.curr_size_ = 0;
}
    ABQ& operator=(ABQ&& rhs) noexcept{
        if (this != &rhs) {
            delete[] array_;
            capacity_ = rhs.capacity_;
            curr_size_ = rhs.curr_size_;
            array_ = rhs.array_;
            rhs.array_ = nullptr;
            rhs.capacity_ = 0;
            rhs.curr_size_ = 0;
        }
        return *this;
    }
    ~ABQ() noexcept override{
        delete[] array_;
    }

    // Getters
    [[nodiscard]] size_t getSize() const noexcept override{
        return curr_size_;
    }
    [[nodiscard]] size_t getMaxCapacity() const noexcept{
        return capacity_;
    }
    [[nodiscard]] T* getData() const noexcept{
        return array_;
    }

    // Insertion
    void enqueue(const T& data) override {
        if (curr_size_ == capacity_) {
            size_t newC = capacity_ * scale_factor_;
            T* newA = new T[newC];
            for (size_t i = 0; i < curr_size_; ++i) {
                newA[i] = array_[i];
            }
            delete[] array_;
            array_ = newA;
            capacity_ = newC;
        }
        array_[curr_size_] = data;
        curr_size_++;
    }

    // Access
    T peek() const override {
        if (curr_size_ == 0) {
            throw std::underflow_error("empty");
        }
        return array_[0];
    }

    // Deletion
    T dequeue() override {
        if (curr_size_ == 0) {
            throw std::underflow_error("empty");
        }
        T front = array_[0];
        for (size_t t = 1; t < curr_size_; t++) {
            array_[t - 1] = array_[t];
        }
        return front;
    }
};
