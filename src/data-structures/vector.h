#ifndef vector_h
#define vector_h
typedef long long ll;

// General use dynamic array
template <class T> class vector {
    
    private:
        T* array;
        ll _capacity = 0;
        ll _size = 0;
    
    public:
        // Initialize a vector with size n with elements of type a
        vector(int n, const T &a) :vector(n) {    
            for(int i = 0; i < n; i++) {
                array[i] = a;
            }
        }
        // Destructor
        ~vector() {
            delete[] array;
        }
        
        // Copy constructor
        vector(const vector<T> &vec) {
            *this = vec;
        }
        
        // Initialize empty vector
        vector() :vector(0) {}
        
        // Initialize a vector of size n
        vector(int n) :_size(n) {
            _capacity = n;
            array = new T[n]();
        }
        
        
        // Assigment operator does a deep copy of the given array into the one on the left
        vector& operator= (const vector& other) {
            _size = other._size;
            _capacity = other._capacity;
            array = new T[other._capacity]();
            
            for(int i = 0; i < other._size; i++) {
                array[i] = other.array[i];
            }
            
            return *this;
        }
        
        // Get the element at the i:th index 
        T& operator [](int i) {
            return array[i];
        }
        
        // Get the amount of elements in the vector
        int size() {
            return _size;    
        }

        // Clear the vector
        void clear() {
            _size = 0;
        }

        // Get a pointer to the beginning of the vector
        T* begin() {
            return array;
        }

        // Get a pointer to the end of the vector

        T* end() {
            return array + _size;
        }

        // Add an element to the end of the list. Double capacity if capacity is reached
        void push_back(T e) {
            if (_size == _capacity) {
                // Double capacity, unless it is zero, then it should be increased to 1.
                _capacity = _capacity == 0 ? 1 : _capacity * 2;
                T* copy = new T[_capacity];
                for(int i = 0; i < _size; i++) {
                    copy[i] = array[i];
                }
                array = copy;
            }
            array[_size++] = e;
        }

};
#endif