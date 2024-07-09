#include <iostream>
#include <utility>
#include <string>
#include "myList.hpp"
#include "myInteger.hpp"

// default constructor
template <typename T>
MyList<T>::MyList() {
}

// copy constructor
template <typename T>
MyList<T>::MyList(const MyList& other) {
    head_ = new Node(other.head_->data);
    Node* tempCurr = head_;
    Node* tempNext = other.head_->next;
    while (tempNext != nullptr) {
        tempCurr->next = new Node(tempNext->data);
        tempCurr->next->prev = tempCurr;
        tempCurr = tempCurr->next;
        tempNext = tempNext->next;
    }
    tail_ = tempCurr;
    tail_->next = nullptr;
    delete tempNext;
    size_ = other.size_;
}

// assignment operator
template <typename T>
MyList<T>& MyList<T>::operator=(MyList other) {
    std::swap(head_, other.head_);
    std::swap(tail_, other.tail_);
    std::swap(size_, other.size_);
    return *this;
}


// destructor
template <typename T>
MyList<T>::~MyList() {
    for (Node* cur = head_; cur != nullptr;) {
        Node* temp = cur;
        cur = cur->next;
        delete temp;
        --size_;
    }
}

// constructor from an initializer list
template <typename T>
MyList<T>::MyList(std::initializer_list<T> vals) {
    for (auto it = std::begin(vals); it != std::end(vals); ++it) {
      this->push_back(*it);
    }
}

// push back
template <typename T>
void MyList<T>::push_back(T val) {
    if (head_ == nullptr){
        Node* temp = new Node(val);
        head_ = temp;
        tail_ = temp;
        ++size_;
    }
    else{
        Node* temp = new Node(val, tail_, nullptr);
        tail_->next = temp;
        tail_ = temp;
        tail_->next = nullptr;
        ++size_;
    }
}

// pop back
template <typename T>
void MyList<T>::pop_back() {
    if (head_ == tail_){
        delete tail_;
        head_ = nullptr;
        tail_ = nullptr;
        --size_;
    }
    else{
        Node* temp = tail_;
        tail_ = tail_->prev;
        tail_->next = nullptr;
        delete temp;
        --size_;
    }
}

template <typename T>
void MyList<T>::push_front(T val) {
    if (head_ == nullptr){
        Node* temp = new Node(val);
        head_ = temp;
        tail_ = temp;
        ++size_;
    }
    else{
        Node* temp = new Node(val, nullptr, head_);
        head_->prev = temp;
        head_ = temp;
        head_->prev = nullptr;
        ++size_;
    }
}

template <typename T>
void MyList<T>::pop_front() {
    if (head_ == tail_){
        delete head_;
        head_ = nullptr;
        tail_ = nullptr;
        --size_;
    }
    else{
        Node *temp = head_;
        head_ = head_->next;
        head_->prev = nullptr;
        delete temp;
        --size_;
    }
}

// return the first element by reference
template <typename T>
T& MyList<T>::front() {
    return head_->data;
}

// return the first element by const reference
template <typename T>
const T& MyList<T>::front() const {
    return head_->data;
}

// return the last element by reference
template <typename T>
T& MyList<T>::back() {
    return tail_->data;
}

// return the last element by const reference
template <typename T>
const T& MyList<T>::back() const {
    return tail_->data;
}

// is the list empty?
template <typename T>
bool MyList<T>::empty() const {
    return size_ == 0;
}

// return the number of elements in the list
template <typename T>
int MyList<T>::size() const {
    return this->size_;
}

// These lines let the compiler know with which types we will be
// instantiating MyList
template class MyList<int>;
template class MyList<std::string>;
template class MyList<MyInteger>;

