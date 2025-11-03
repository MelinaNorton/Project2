#ifndef BUBBLESORT_TPP
#define BUBBLESORT_TPP
#include "sortStrategy.h"

template<typename T>
class BubbleSortStrategy : public SortStrategy<T>{
    public:
        void sort(std::vector<T>& v) override;
};

template<typename T>
void BubbleSortStrategy<T>::sort(std::vector<T>&v){
    int size = v.size();
    bool swapped = false;

    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-i-1; j++){
            if(v[j]>v[j+1]){std::swap(v[j], v[j+1]); swapped = true;}
        }
        if(!swapped){break;}
    }
}
#endif