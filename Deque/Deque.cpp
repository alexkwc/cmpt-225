#include"Deque.h"
#include"Node.h"

using std::move;
using std::endl;

int Deque::size() const{
    return currentSize;
}

bool Deque::empty() const{
    return currentSize == 0;
}

int Deque::peek_back() const{
    if(empty())
        throw std::runtime_error("peeking a empty deque");
    return tail->val;
}

int Deque::peek_front() const{
    if(empty())
        throw std::runtime_error("peeking a empty deque");
    return head->val;
}

int Deque::remove_back(){
    if(empty())
        throw std::runtime_error("removing from empty deque");
    if(size() == 1){
        return remove_oneItem();
    }
    tail = head.get();
    for(int i = currentSize-2; i > 0; i--){
        tail = tail->next.get();
    }
    auto tmp = move(tail->next);
    currentSize--;
    return tmp->val;
}

int Deque::remove_front(){
    if(empty())
        throw std::runtime_error("removing from empty deque");
     if(size() == 1){
        return remove_oneItem();
    }
    auto tmp = move(head);
    head = move(tmp->next);
    currentSize--;
    return tmp->val;
}

int Deque::remove_oneItem(){
    auto tmp = move(head);
    tail = nullptr;
    currentSize--;
    return tmp->val;
}

void Deque::insert_front(int value){
    if(empty())
    {
        insert_empty(value);
        return;
    }
    std::unique_ptr<Node> tmp = std::make_unique<Node>(value);
    tmp->next = move(head);
    head = move(tmp);
    currentSize++;
}

void Deque::insert_back(int value){
    if(empty()){
        insert_empty(value);
        return;
    }
    std::unique_ptr<Node> tmp = std::make_unique<Node>(value);
    tail->next = move(tmp);
    tail = tail->next.get();
    currentSize++;
}

void Deque::print_queue(const std::string& label) const{
    auto tmp = head.get();
    std::cout<<label<<":";
    for(int i = currentSize; i > 0; i--){
        std::cout<<tmp->val<<", ";
        tmp = tmp->next.get();
    }
    std::cout<<endl;
}

Deque::Deque(const Deque& dq)
{
    deep_copy(dq);
}

Deque::~Deque()
{
    while(!empty())
    {
        remove_front();
    }
}

void Deque::insert_empty(int value){
    head = std::make_unique<Node>(value);
    tail = head.get();
    currentSize++;
}

Deque& Deque::operator=(const Deque& dq){
    deep_copy(dq);
    return *this;
}

void Deque::deep_copy(const Deque& dq){
    auto tmp = dq.head.get();
    while(tmp != nullptr){
        insert_back(tmp->val);
        tmp = tmp->next.get();
    }
}
