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

    if(leftChild < size && v[leftChild] > v[largest]){largest = leftChild;}
    if(rightChild < size && v[rightChild] > v[largest]){largest = rightChild;}

    if(largest != root){
        std::swap(v[root], v[largest]);
        heapify(v, largest, size);
    }
};

template<typename T>
void HeapSortStrategy<T>::sort(std::vector<T>&v){
    //sort logic
    int size = v.size();
    for (int i = size/2 - 1; i >= 0; --i){
        heapify(v, i, size);
    }

    for(int i= size-1; i>0; i--){
        std::swap(v[0], v[i]);
        heapify(v, 0, i);
    }
}
#endif