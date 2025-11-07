#include "LinkedList.hpp"

template <typename T>
void LinkedList<T>::addHead(const T& data) {
    Node<T>* newNode = new Node<T>(data);
    if (count == 0) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    count++;
}
template <typename T>
void LinkedList<T>::addTail(const T& data){
    Node<T>* newNode = new Node<T>(data);
    if (count == 0) {
        head = tail = newNode;
    } 
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    count++;
}
template <typename T>
bool LinkedList<T>::removeHead(){
    if (count == 0) {
        return false;
    }
    Node<T>* temp = head;
    head = head->next;
    if (head) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }
    delete temp;
    count--;
    return true;
}
template <typename T>
bool LinkedList<T>::removeTail(){
    if (count == 0) {
        return false;
    }
    Node<T>* temp = tail;
    tail = tail->prev;
    if(tail) {
        tail->next = nullptr;
    } else {
        head = nullptr;
    }
    delete temp;
    count--;
    return true;
}