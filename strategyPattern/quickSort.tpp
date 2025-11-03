#ifndef QUICKSORT_TPP
#define QUICKSORT_TPP
#include "sortStrategy.h"

template<typename T>
class QuickSortStrategy : public SortStrategy<T>{
    public:
        void sort(std::vector<T>& v) override;
    private:
        void partition(std::vector<T>&v, int low, int high);
        void quickSortHelper(std::vector<T>&v, int low, int high);
};

template<typename T>
void QuickSortStrategy<T>::partition(std::vector<T>&v, int low, int high){
    //lomuto partition login
    int size = v.size();
    int pivot = v[n-1];
    
    for(int j=0; j<size; j++){
        if(v[j]<pivot){i++; std::swap(v[j], v[pivot]);}
    }
    swap(v[i+1], v[j]);
}

template<typename T>
void QuickSortStrategy<T>::quickSortHelper(std::vector<T>&v, int low, int high){
    //actual sort logic
    if(low>=high){return;}
    int partition = partition(v, low, high);
    quickSortHelper(v, low, partition-1);
    quickSortHelper(v, partition+1, high);
}

template<typename T>
void QuickSortStrategy<T>::sort(std::vector<T>&v){
    //abstracted sort logic (calls helper)
    if(v.size()<=1){return;}
    quickSortHelper(v, 0, v.size()-1);
}
#endif