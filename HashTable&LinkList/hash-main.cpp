/*
  Simple test driver for Hash Table assignment.
  CMPT 225 D200 Fall 2016.
 */

#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

#include "HashTable.h"

using std::cout;
using std::endl;
using std::sort;
using std::string;
using std::vector;

void printVec(const vector<string>& vec) {
  for (auto s : vec)
    cout << s << " ";
  cout << endl;
}

void linkedListTest() {
  cout << "Start LinkedList tests" << endl;
  auto ll = LinkedList{}; // Default constructor

  ll.add("hello"); // add
  cout << endl << "Test of get (should be \"hello\") ";
  printVec(ll.get());

  cout << "Test of empty (should be 0) " << ll.empty() << endl;

  cout << "Test of search (should be 1) " << ll.search("hello") << endl;

  auto ll2 = ll; // Test of copy constructor

  cout << endl << "Test of remove (should be 1) " << ll.remove("hello") << endl;

  auto ll3 = LinkedList {};
  ll3.add("goodbye");
  ll3 = ll2; // Test of copy assignment

  auto items = ll3.get();
  cout << endl << "Test of result of copy assignment (should be \"hello\") ";
  printVec(ll3.get());

  cout << endl << "Test of printList (whatever format you use)" << endl;
  ll.printList();

  cout << endl << "End LinkedList tests" << endl << endl;
}

void hashTableTest()
{
  cout << "Start HashTable tests" << endl;

  cout << "Default capacity " << HashTable::defaultCapacity << endl;

  HashTable ht0 {}; // Default constructor; also (implied) destructor
  cout << "Default table size: " << ht0.size() << ", capacity: " << ht0.capacity() << endl; // size and capacity
  HashTable ht1 {9}; // Constructor specifying number of items
  //cout << "h1 table size: " << ht0.size() << ", capacity: " << ht0.capacity() << endl; // size and capacity
  ht0.add("bat"); // add
  //cout <<"ht1";
  ht1.add("bat"); // add
  //cout << "Default table size: " << ht1.size() << ", capacity: " << ht1.capacity() << endl; // size and capacity
  //cout <<"added";
  ht1.add("cat");
  ht1.add("rhinoceros");
  ht1.add("ocelot");
  ht1.add("elephant");
  ht1.add("hippopotamus");
  ht1.add("giraffe");
  ht1.add("camel");
  ht1.add("lion");
  ht1.add("panther");
  ht1.add("bear");
  ht1.add("wolf");

  cout << "Load factor (should be around 63%): " << ht1.loadFactor() << endl; // loadFactor

  // Test search
  cout << endl << "Search examples" << endl;
  string test1 = "frog";
  string test2 = "camel";
  cout << test1 << " (should be 0): " << ht1.search(test1) << endl;
  cout << test2 << " (should be 1): " << ht1.search(test2) << endl;

  // Test copy constructor and remove
  HashTable ht2 {ht1};
  cout<<"Size of ht2 ="<<ht2.size();

  ht2.remove("ocelot");
  cout<<"Size of ht2 ="<<ht2.size();

  ht2.remove("camel");
  cout<<"Size of ht2 ="<<ht2.size();

  ht2.remove("rhinoceros");

  cout << endl;
  ht2.printTable("Test of printTable---whatever your output is"); // printTable

  vector<string> keys = ht2.keys(); // keys

  HashTable ht3 {};
  ht3 = ht1; // Copy assignment
  cout<<"Size of ht2 ="<< ht2.size();
  // Test set union
  ht2.add("kraken");
  cout<<"Size of ht2 ="<<ht2.size();
  cout<<"Size of ht1 ="<<ht1.size();

  HashTable un = ht1.setunion(ht2);
  vector<string> unionKeys = un.keys();
  sort(unionKeys.begin(), unionKeys.end());
  cout << endl << "Set union example. Result should be:" << endl;
  cout << "bat bear camel cat elephant giraffe hippopotamus kraken lion ocelot panther rhinoceros wolf" << endl;
  cout << "Result was:" << endl;
  printVec(unionKeys);

  HashTable ht5{30};
  ht5.printTable("Test of printTable h5---whatever your output is");
  cout << ht5.loadFactor()<<" size="<<ht5.capacity();
  cout << endl << "Hash of \"Hello\" (should be 15263440): " << HashTable::hash("Hello") << endl;

  cout << endl << "Compress of 15263440 for ht1 (should be 18) " << ht1.compress(std::uint32_t(15263440U)) << endl;

  cout << endl << "End HashTable tests" << endl;
}

int main()
{
  linkedListTest();
  hashTableTest();
  return 0;
}
