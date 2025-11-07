#pragma once

#include <cstddef>
#include <stdexcept>


template <typename T>
class StackInterface {
    virtual void push(const T& data)= 0;
    virtual void pop() = 0;
    virtual T peek() const = 0;
    virtual size_t getSize() const noexcept = 0;

    virtual ~StackInterface() = default;
};


template <typename T>
class QueueInterface {
    void enqueue(const T& item)= 0;
    T dequeue() = 0;
    T peek() const = 0;
    size_t getSize() const noexcept = 0;

    virtual ~QueueInterface() = default;
};


template <typename T>
class DequeInterface {
    void pushFront(const T& item) = 0;
    void pushBack(const T& item) = 0;
    T popFront() = 0;
    T popBack() = 0;
    const T& front() const = 0;
    const T& back() const = 0;
    size_t getSize() const noexcept = 0;

    virtual ~DequeInterface() = default;
};

