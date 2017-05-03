#include "Node.h"

std::ostream& operator<<(std::ostream& out, const Node& n) {
  return out << &n << ": " << n.val << " -> " << n.next.get();
}
