#ifndef node_h
#define node_h

// A node in a linked list. Used to create the queue data structure.
template <class T> class node {
    
    public:
        node* next;
        T value;
    
    // Constructor with next and value
    node(T value, node* _next) :node(value) {
        next = _next;
    }
    
    // Constructor with value
    node(T value) :value(value) {
        next = nullptr;
    }
    
};        
#endif