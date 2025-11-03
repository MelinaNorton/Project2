#ifndef HEAPSORT_TPP
#define HEAPSORT_TPP
#include "sortStrategy.h"
#include <vector>

template<typename T>
class HeapSortStrategy : public SortStrategy<T>{
    public:
        void sort(std::vector<T>& v) override;
    private:
        void heapify(std::vector<T>& v, int root, int size);
};

template<typename T>
void HeapSortStrategy<T>::heapify(std::vector<T>&v, int root, int size){
    //max heap logic
    int largest = root;
    int leftChild = 2 * root + 1; 
    int rightChild = 2 * root + 2;

    if(root < size && v[leftChild] > v[largest]){largest = leftChild;}
    if(root < size && v[rightChild] > v[largest]){largest = rightChild;}

    if(largest != root){
        swap(v[root], v[largest]);
        heapify(v, size, largest)
    }
}

template<typename T>
void HeapSortStrategy<T>::sort(std::vector<T>&v){
    //sort logic
    for (int i = n/2 - 1; i >= 0; --i){
        heapify(arr, n, i);
    }

    for(int i= n-1; i>0; i--){
        swap(v[0], v[i]);
        heapify(v, i, 0);
    }
}
#endif