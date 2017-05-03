#ifndef Deque_header
#define Deque_header

#include"Node.h"

class Deque{
    public:

    //Default constructor
    Deque() = default;

    //constructor
    Deque(const Deque&);

    //distructor
    ~Deque();

    //
    Deque& operator=(const Deque&);

    //insert value from the front of deque
    void insert_front(int);

    //insert vslue from the back of deque
    void insert_back(int);

    //remove 1st item from the deque
    int remove_front();

    //remove last item from the deque
    int remove_back();

    //return value from the front
    int peek_front() const;

    //return value from the back
    int peek_back() const;

    //return true if empty
    bool empty() const;

    //return number of items in deque
    int size() const;

    //printing the whole deque(debugging only)
    void print_queue(const std::string& label) const;

    private:
    //return the only item and set both pointer to 0
    int remove_oneItem();

    void insert_empty(int);
    void deep_copy(const Deque&);

    int currentSize = 0;
    std::unique_ptr<Node> head = nullptr;
    Node* tail= nullptr;

};

#endif // Deque_header
