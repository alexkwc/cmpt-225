#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "LinkedList.h"


bool LinkedList::empty() const
{
    return (head == nullptr);
}

bool LinkedList::add(const Val& v)
{
    if(empty())
    {
        head = std::make_unique<Node>(v);
        return true;
    }
    if(search(v)) return false;
    auto tmp = std::make_unique<Node>(v);
    tmp->next = move(head);
    head = move(tmp);
    return true;
}

bool LinkedList::remove(const Val& v)
{
    if(empty()) return false;
    auto tmp = head.get();
    if(tmp->value == v)
    {
        if(head->next.get() != nullptr)
        {
            head = move(head->next);
            return true;
        }else
        {
            auto dump = move(head);
            return true;
        }
    }
    while(tmp->next!= nullptr)
    {
        if(tmp->next->value == v)
        {
            if(tmp->next->next.get() != nullptr)
            {
                tmp->next = move(tmp->next->next);
                return true;
            }else
            {
                auto dump = move(tmp->next);
                return true;
            }
        }
        tmp = tmp->next.get();
    }
    return false;
}

bool LinkedList::search(const Val& v) const
{
    if(empty()) return false;
    auto tmp = head.get();
    while(tmp != nullptr)
    {
        if(tmp->value == v) return true;
        tmp = tmp->next.get();
    }
    return false;
}

void LinkedList::printList() const
{
    if(empty()) return;
    auto tmp = head.get();
    while (tmp != nullptr)
    {
        std::cout<<tmp->value<<" ";
        tmp = tmp->next.get();
    }
    std::cout<<std::endl;
    return;
}

LinkedList::LinkedList (const LinkedList& ll)
{
    deep_copy(ll);
}

LinkedList::~LinkedList()
{
    while(!empty())
    {
        head = move(head->next);
    }
}
void LinkedList::deep_copy(const LinkedList& ll)
{
    if(ll.empty()) return;
    auto tmp = ll.head.get();
    while (tmp != nullptr)
    {
        add(tmp->value);
        tmp = tmp->next.get();
    }
    return;
}

LinkedList& LinkedList::operator=(const LinkedList& ll)
{
    if(ll.empty())
    {
        auto dump = move(head);
        return *this;
    }
    auto tmp = head.get();
    while(tmp != nullptr)
    {
        if(!(ll.search(tmp->value)))
        {
            auto dump = tmp->value;
            tmp = tmp->next.get();
            remove(dump);
        }else
        {
            tmp = tmp->next.get();
        }
    }
    tmp = ll.head.get();
    while(tmp != nullptr)
    {
        if(!(search(tmp->value))) add(tmp->value);
        tmp = tmp->next.get();
    }
    return *this;
}


std::vector<Val> LinkedList::get() const
{
    std::vector<Val> output;
    if(empty()) return output;
    auto tmp = head.get();
    while (tmp != nullptr)
    {
        output.push_back(tmp->value);
        tmp = tmp->next.get();
    }
    return output;
}

