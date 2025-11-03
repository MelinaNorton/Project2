#include <string>
#include "sortStrategy.h"
#include "bubbleSort.tpp"
#include "heapSort.tpp"
#include "quickSort.tpp"

//change typing based on desired vector type
SortStrategy<int>* chooseIntSortStrategy(char&sortStrat){
    switch(sortStrat){
        case 'h':
            return new HeapSortStrategy<int>();
            break;

        case 'b':
            return new BubbleSortStrategy<int>();
            break;

        case 'q':
            return new QuickSortStrategy<int>();
            break;
    }
}