#include "ABS.hpp"

template<typename T>
ABS<T>::ABS() : capacity_(1), curr_size_(0), array_(new T[1]) {}

template<typename T>
ABS<T>::ABS(const size_t capacity) : capacity_(capacity), curr_size_(0), array_(new T[capacity]) {}

//copy const
template<typename T>
ABS<T>::ABS(const ABS& other){
    capacity_ = other.capacity_;
    curr_size_ = other.curr_size_;
    array_ = new T[capacity_];
    for (size_t i = 0; i < curr_size_; ++i) {
        array_[i] = other.array_[i];
    }
}

//copy assignment
template<typename T>
ABS<T>& ABS<T>::operator=(const ABS& rhs){
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

template <typename T>
ABS<T>::ABS(ABS&& other) noexcept{
    capacity_ = other.capacity_;
    curr_size_ = other.curr_size_;
    array_ = other.array_;
    other.array_ = nullptr;
    other.capacity_ = 0;
    other.curr_size_ = 0;
}
template <typename T>
ABS<T>& ABS<T>::operator=(ABS&& rhs) noexcept {
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

template<typename T>
ABS<T>::~ABS() noexcept {
    delete[] array_;
}
/*    [[nodiscard]] size_t getSize() const noexcept override;

    // Get the max size of the ABS
    [[nodiscard]] size_t getMaxCapacity() const noexcept;

    // Return underlying data for the stack
    [[nodiscard]] T* getData() const noexcept;

    // Push item onto the stack
    void push(const T& data) override;

    T peek() const override;

    T pop() override;

private:*/
template<typename T>
size_t ABS<T>::getSize() const noexcept {
    return curr_size_;
}

template<typename T>
size_t ABS<T>::getMaxCapacity() const noexcept {
    return capacity_;
}  
template<typename T>
T* ABS<T>::getData() const noexcept {
    return array_;
}
template<typename T>
void ABS<T>::push(const T& data) {
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
    curr_size_++;
    array_[curr_size_ - 1] = data;
}

template <typename T>
T ABS<T>::peek() const {
    if (curr_size_ == 0) {
        throw std::out_of_range("no top");
    }
    return array_[curr_size_ - 1];
}

template <typename T>
T ABS<T>::pop() {
    if (curr_size_ == 0) {
        throw std::out_of_range("no top");
    }
    T top_item = array_[curr_size_ - 1];
    curr_size_--;
    return top_item;
}

