//  Define prototypes for sorting assignment, Fall 2016 CMPT 225.
//

#ifndef SORT_H
#define SORT_H

#include <vector>

using Val = int;
using Container = std::vector<Val>;
using Iter = long;

int insertionSort(Container& arr, Iter start, Iter end);
int mergeSort(Container& arr, Iter start, Iter end);
int quickSort(Container& arr, Iter start, Iter end);
int shellSort(Container& arr, Iter start, Iter end);

#endif
