#pragma once
#include "ABQ.hpp"
#include <cstddef>
#include <stdexcept>

using std::size_t;

template<typename T>
ABQ<T>::ABQ() : capacity(1), curr_size_(0), array_(new T[1]) {}

template<typename T>
ABQ<T>::ABQ(const size_t capacity) : capacity_(capacity), curr_size_(0), array_(new T[capacity]) {}

//copy const
template<typename T>
ABQ<T>::ABQ(const ABQ& other){
    capacity_ = other.capacity_;
    curr_size_ = other.curr_size_;
    array_ = new T[capacity_];
    for (size_t i = 0; i < curr_size_; ++i) {
        array_[i] = other.array_[i];
    }
}

//copy assignment
template<typename T>
ABQ<T>& ABQ<T>::operator=(const ABQ& rhs){
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
//move const
template <typename T>
ABQ<T>::ABQ(ABQ&& other) noexcept{
    capacity_ = other.capacity_;
    curr_size_ = other.curr_size_;
    array_ = other.array_;
    other.array_ = nullptr;
    other.capacity_ = 0;
    other.curr_size_ = 0;
}
//move assignment
template <typename T>
ABQ<T>& ABQ<T>::operator=(ABQ&& rhs) noexcept {
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
//dest
template<typename T>
ABQ<T>::~ABQ() noexcept {
    delete[] array_;
}

template<typename T>
size_t ABQ<T>::getSize() const noexcept {
    return curr_size_;
}

template<typename T>
size_t ABQ<T>::getMaxCapacity() const noexcept {
    return capacity_;
}  
template<typename T>
T* ABQ<T>::getData() const noexcept {
    return array_;
}

template <typename T>
T ABQ<T>::peek() const {
    if (curr_size_ == 0) {
        throw std::out_of_range("no top");
    }
    return array_[0];
}

template <typename T>
void ABQ<T>::enqueue(const T& data) {
    if (curr_size_ >= capacity_) {
        size_t new_capacity = capacity_ * scale_factor_;
        T* new_array = new T[new_capacity];
        for (size_t i = 0; i < curr_size_; ++i) {
            new_array[i] = array_[i];
        }
        delete[] array_;
        array_ = new_array;
        capacity_ = new_capacity;
    }
    for
}

