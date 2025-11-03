#include <vector>
#include <iostream>
#include "context.h"
#include <algorithm>
#include <string>
#include <random>
#include "sortStrategy.h"
#include "bubbleSort.tpp"
#include "heapSort.tpp"
#include "quickSort.tpp"

//change typing based on desired vector type
SortStrategy<int>* chooseIntSortStrategy(const char*sortStrat){
    switch(*sortStrat){
        case 'h':
            return new HeapSortStrategy<int>();
            break;

        case 'b':
            return new BubbleSortStrategy<int>();
            break;

        case 'q':
            return new QuickSortStrategy<int>();
            break;
        default:
            return new BubbleSortStrategy<int>();
            break;
    }
}

//change typing based on desired vector type
SortStrategy<std::pair<std::string, int>>* choosePairSortStrategy(const char*sortStrat){
    switch(*sortStrat){
        case 'h':
            return new HeapSortStrategy<std::pair<std::string, int>>();
            break;

        case 'b':
            return new BubbleSortStrategy<std::pair<std::string, int>>();
            break;

        case 'q':
            return new QuickSortStrategy<std::pair<std::string, int>>();
            break;
        default:
            return new BubbleSortStrategy<std::pair<std::string, int>>();
            break;
    }
}



void populateIntVector(std::vector<int>&v){
    v.reserve(1000);
    for (int x = 0; x <= 1000; ++x) {
        v.push_back(x);
    }

    std::random_device rd;
    std::mt19937 rng(rd());
    std::shuffle(v.begin(), v.end(), rng);
}
void populatePairVector(std::vector<std::pair<std::string, int>>& v){
    v.reserve(1001);

    // prepare 0..1000, then shuffle that order
    std::vector<int> nums;
    nums.reserve(1001);
    for (int x = 0; x <= 1000; ++x) {
        nums.push_back(x);
    }
    std::random_device rd;
    std::mt19937 rng(rd());
    std::shuffle(nums.begin(), nums.end(), rng);

    // random uppercase letter for each entry’s first
    std::uniform_int_distribution<int> letter(0, 25);
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        char c = static_cast<char>('A' + letter(rng));
        std::string s(1, c);
        v.push_back(std::pair<std::string, int>(s, nums[i]));
    }
}

void chooseVectorPopulationStrategy(const char*vecStrat, const char*sortStrat){
    char c1 = 'i';
    char c2 = 'p';
    if(vecStrat[0] == c1){
        std::cout<< "int type chosen"<<std::endl;
        StrategySortContext<int> ctx{ chooseIntSortStrategy(sortStrat) };
        std::vector<int> intVec = {};
        populateIntVector(intVec);
        std::cout<<"Pre-Sort First 10: "<<std::endl;
        for(int i=0; i<10; i++){std::cout<<intVec[i]<<std::endl;}
        ctx.sort(intVec);
        std::cout<<"Post-Sort First 10: "<<std::endl;
        for(int i=0; i<10; i++){std::cout<<intVec[i]<<std::endl;}
    }
    else if(vecStrat[0] == c2){
        std::cout<< "pair type chosen"<<std::endl;
        StrategySortContext<std::pair<std::string, int>> ctx{ choosePairSortStrategy(sortStrat) };
        std::vector<std::pair<std::string, int>>pairVec = {};
        populatePairVector(pairVec);
        std::cout<<"Pre-Sort First 10: "<<std::endl;
        for(int i=0; i<10; i++){std::cout<<pairVec[i].first<< "," << pairVec[i].second << std::endl;}
        ctx.sort(pairVec);
        std::cout<<"Post-Sort First 10: "<<std::endl;
        for(int i=0; i<10; i++){std::cout<<pairVec[i].first<< "," << pairVec[i].second << std::endl;}
    }
    else{
        return;
    }
}

int main(int argc, char* argv[]) {
    //1 is the type, 2 is the sort strategy
    chooseVectorPopulationStrategy(argv[1], argv[2]);
    std::cout << '\n';
}
