/*
  Simple test routine for deque assignment.

  This is not a complete test!  Add your own cases.
 */

#include <iostream>

#include "Deque.h"

using std::cout;
using std::endl;

int main()
{
      Deque dq1;

      cout << dq1.empty() << " - 1" << endl;

      dq1.insert_front(42);
      dq1.insert_back(216);

      cout << dq1.peek_front() << " - 42" << endl;
      cout << dq1.peek_back() << " - 216" << endl;
      cout << dq1.size() << " - 2" << endl;

      dq1.print_queue("dq1 before copy constructor and copy assignment");

      Deque dq2(dq1);


      dq2.print_queue("dq2 after copy constructor");
      Deque dq3;
      dq3 = dq1;


      dq3.print_queue("dq3 after copy assignment");

      cout << dq1.remove_front() << " - 42" << endl;
      cout << dq1.remove_back() << " - 216" << endl;
      dq1.print_queue("dq1 should be empty");

      cout << dq2.peek_front() << " - 42" << endl;
      cout << dq2.peek_back() << " - 216" << endl;

      dq3.print_queue("After two removes from dq1");

      cout << dq3.peek_front() << " - 42" << endl;
      cout << dq3.peek_back() << " - 216" << endl;

      return 0;
}
