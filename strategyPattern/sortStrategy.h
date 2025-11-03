#ifndef SORTSTRATEGY_H
#define SORTSTRATEGY_H
#include <vector>

template <typename T>
class SortStrategy{
    public:
        SortStrategy() = default;
        virtual void sort(std::vector<T>&v) = 0;
        virtual ~SortStrategy() = default;
};
#endif