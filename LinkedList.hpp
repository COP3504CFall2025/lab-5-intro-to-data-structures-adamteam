#pragma once
#include <iostream>
using namespace std;

template <typename T>
struct Node {
	T data;
	Node* next;
	Node* prev;
	Node(const T& data) : data(data), next(nullptr), prev(nullptr) {}
};

template <typename T>
class LinkedList {
public:
	// Behaviors
	void printForward() const{
		Node<T>* current = head;
		while(current != nullptr){
			cout<<current->data<<" ";
			current=current->next;
		}
	cout<<endl;
	}

	void printReverse() const {
		Node<T>* current = tail;
		while(current != nullptr) {
			cout << current->data << " ";
			current = current->prev;
		}
	}

	// Accessors
	[[nodiscard]] unsigned int getCount() const {
		return count;
	}
	Node<T>* getHead(){
		return head;
	}
	const Node<T>* getHead() const{
		return head;
	}
	Node<T>* getTail(){
		return tail;
	}
	const Node<T>* getTail() const{
		return tail;
	}

	// Insertion
	void addHead(const T& data) {
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
	void addTail(const T& data){
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

	// Removal
	bool removeHead(){
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
	bool removeTail(){
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
	void Clear(){
	while (count > 0) {
		removeHead();
	}
}

	// Operators
	LinkedList<T>& operator=(LinkedList<T>&& other) noexcept{
		if (this == &other) {
			return *this;
		}
		Clear();
		head = other.head;
		tail = other.tail;
		count = other.count;
		other.head = nullptr;
		other.tail = nullptr;
		other.count = 0;
		return *this;
	}
	LinkedList<T>& operator=(const LinkedList<T>& rhs){
		if (this == &rhs) {
			return *this;
		}
		Clear();
		Node<T>* current = rhs.head;
		while (current != nullptr) {
			addTail(current->data);
			current = current->next;
	}
		return *this;
}

	// Construction/Destruction
	LinkedList() : head(nullptr), tail(nullptr), count(0) {}
	LinkedList(const LinkedList<T>& list){
		head = nullptr;
		tail = nullptr;
		count = 0;
		Node<T>* current = list.head;
		while (current!= nullptr) {
			addTail(current->data);
			current = current->next;
		}
	}
	LinkedList(LinkedList<T>&& other) noexcept{
		head = other.head;
		tail = other.tail;
		count = other.count;
		other.head = nullptr;
		other.tail = nullptr;
		other.count = 0;
	}
	~LinkedList() {
		Clear();
	}

private:
	// Stores pointers to first and last nodes and count
	Node<T>* head;
	Node<T>* tail;
	unsigned int count;

};


