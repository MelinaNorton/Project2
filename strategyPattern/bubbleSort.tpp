#ifndef BUBBLESORT_TPP
#define BUBBLESORT_TPP
#include "sortStrategy.h"

template<typename T>
class BubbleSortStrategy : public SortStrategy<T>{
    public:
        void sort(std::vector<T>& v) override;
};

template<typename T>
void SortStrategy<T>::sort(std::vector<T>&v){
    //sort logic
}
#endif