#ifndef STRATEGY_SORT_CONTEXT_H
#define STRATEGY_SORT_CONTEXT_H
#include "sortStrategy.h"

template <typename T>
class StrategySortContext{
    public:
        StrategySortContext(SortStrategy<T>* s) : sortStrategy(s) {}
        void setStrategy(SortStrategy<T>* s) { sortStrategy = s; }
        void sort(std::vector<T>& vec) {
            sortStrategy->sort(vec); 
         }
    private:
        SortStrategy<T>* sortStrategy;
};
#endif