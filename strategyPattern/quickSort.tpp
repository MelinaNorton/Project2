#ifndef QUICKSORT_TPP
#define QUICKSORT_TPP
#include "sortStrategy.h"

template<typename T>
class QuickSortStrategy : public SortStrategy<T>{
    public:
        void sort(std::vector<T>& v) override;
    private:
        int partitionLomuto(std::vector<T>&v, int low, int high);
        void quickSortHelper(std::vector<T>&v, int low, int high);
};

template<typename T>
int QuickSortStrategy<T>::partitionLomuto(std::vector<T>&v, int low, int high){
    //lomuto partition logic
    const T& pivot = v[high];
    int i = low-1;

    for(int j=low; j<high; j++){
        if(v[j]<pivot){++i; std::swap(v[i], v[j]);}
    }
    std::swap(v[i+1], v[high]);
    return i+1;
}

template<typename T>
void QuickSortStrategy<T>::quickSortHelper(std::vector<T>&v, int low, int high){
    //actual sort logic
    if(low>=high){return;}
    int part = partitionLomuto(v, low, high);
    quickSortHelper(v, low, part-1);
    quickSortHelper(v, part+1, high);
}

template<typename T>
void QuickSortStrategy<T>::sort(std::vector<T>&v){
    //abstracted sort logic (calls helper)
    if(v.size()<=1){return;}
    quickSortHelper(v, 0, v.size()-1);
}
#endif