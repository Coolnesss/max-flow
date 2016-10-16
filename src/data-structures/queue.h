#ifndef queue_h
#define queue_h

#include "node.h"

// Queue data structure for breath-first search
template <class T> class queue {
  
  private:
    node<T>* _head;
    node<T>* _tail;
    
  public:
  
    // Constructor with value
    queue(T value) {
        _head = node<T>(value);
        _tail = nullptr;
    }
    
    // Destructor
    ~queue() {
        while(!empty()) pop(); 
    }
    
    // Constructor without value
    queue() {
        _head = nullptr;
        _tail = nullptr;
    }
    
    // Access element in the front of the queue
    T front() {
        return _head->value;
    }
    
    // Add to the front of the queue
    void push(T value) {
        node<T>* newNode = new node<T>(value);
        if (empty()) {
            _head = newNode;
            _tail = newNode;
        } else {
            _tail->next = newNode;
            _tail = newNode;
        }
    }
    
    // Retrieve and remove head of the queue
    T pop() {
        T value = _head->value;
        auto next = _head->next;
        delete _head;
        _head = next;
        if (_head == nullptr) {
            _tail = nullptr;
        }
        return value;
    }
    
    // Check if queue is empty
    bool empty() {
        return _head == nullptr;
    }    
};       
 
#endif