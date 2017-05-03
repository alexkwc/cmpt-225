#include "sort.h"
#include <memory>
#include <vector>
#include <stdlib.h>

int insertionSort(Container& arr, Iter start, Iter end){
    if(end - start <= 1) return 0;
    long count = 0;

    for(auto cur = start+1 ; cur < end ; ++cur){
        count++;
        if(arr[cur]<arr[cur-1]){
            for(auto sweep = start ; sweep < cur ; ++sweep){
                count++;
                if(arr[cur]<arr[sweep]){
                    auto tmp = arr[cur];
                    std::move_backward(&arr[sweep],&arr[cur],&arr[cur+1]);
                    arr[sweep] = tmp;
                    break;
                }
            }
        }
    }

    return count;
}

int mergeSort(Container& arr, Iter start, Iter end){
    if(end-start < 2) return 0;
    auto mid = end + start;
    mid = mid/2;
    auto count = mergeSort(arr,start,mid);
    count += mergeSort(arr,mid,end);
    Container tmp {};
    auto i = start;
    auto j = mid;
    while(i < mid && j < end){
            count++;
            if(arr[i]<arr[j]){
                tmp.push_back(arr[i++]);

            }else{
                tmp.push_back(arr[j++]);
            }
    }
    while(i < mid){
        tmp.push_back(arr[i++]);
    }
    while(j < end){
        tmp.push_back(arr[j++]);
    }
    for(auto k = start; k < end; k++){
        arr[k] = tmp[k-start];
    }
    return count;
}
int quickSort(Container& arr, Iter start, Iter end){
    if(end-start<=1) return 0;
    auto count = Iter{0};
    auto pivot = Iter{start};
    auto random = rand() % (end-start);
    auto tmp = arr[pivot];
    arr[pivot] = arr[random+start];
    arr[random+start] = tmp;
    auto mid = pivot;
    auto sweep = mid+1;
    while(sweep<end){
        count++;
        if(arr[sweep]<arr[pivot]){
            mid++;
            auto tmp = arr[sweep];
            arr[sweep] = arr[mid];
            arr[mid] = tmp;
        }
        sweep++;
    }
    tmp = arr[pivot];
    arr[pivot] = arr[mid];
    arr[mid] = tmp;
    count += quickSort(arr,start,mid);
    count += quickSort(arr,mid+1,end);
    return count;
}
int shellSort(Container& arr, Iter start, Iter end){
    auto gap = end-start/2;
    auto count = Iter{0};
    while(gap > 0){
        auto i = start;
        while(i+gap<end){
            count++;
            if(arr[i]>arr[i+gap]){
                //cout<<arr[i]<<">"<<arr[i+gap]<<endl;
                auto tmp = arr[i+gap];
                arr[i+gap] = arr[i];
                arr[i] = tmp;
                if(i-gap>= start) i -= gap;
            }else{
                i++;
            }
        }
        gap = gap/2;
    }
    return count;
}
