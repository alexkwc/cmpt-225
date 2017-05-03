#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <memory>
#include <string>
#include <vector>

using Val = std::string;

// Define class Node here
class Node{
    public:
        Node(const Node& n): value{n.value}, next{}
        {
        }
        Node(Val v, std::unique_ptr<Node> n) : value{v}, next{move(n)}
        {
        }
        Node(Val v) : value{v}
        {
        }
    private:
        Val value;
        std::unique_ptr<Node> next = nullptr;
        friend class LinkedList;
        friend std::ostream& operator<<(std::ostream&, const Node&);
};


class LinkedList {
 public:
  LinkedList () {}
  LinkedList (const LinkedList& ll);
  ~LinkedList();

  LinkedList& operator=(const LinkedList& ll);

  bool add(const Val& v);
  bool remove(const Val& v);

  bool search(const Val& v) const;
  bool empty() const;

  std::vector<Val> get() const;

  void printList() const;

 private:
  // Add your member variables and any private member functions here
  std::unique_ptr<Node> head = nullptr;
  void deep_copy(const LinkedList& ll);
};

#endif
