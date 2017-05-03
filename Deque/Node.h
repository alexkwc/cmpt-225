#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <memory>

class Node {
 public:
 Node(const Node& n) : val{n.val}, next{}
  {
  }
 Node(int v, std::unique_ptr<Node> n) : val{v}, next{move(n)}
  {
  }
 Node(int v) : val{v}
  {
  }

 private:
  int val = 0;
  std::unique_ptr<Node> next = nullptr;

  friend class Deque;
  friend std::ostream& operator<<(std::ostream&, const Node&);
};

#endif

