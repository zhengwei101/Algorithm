#include "SortTestHelper.h"

template<typename T>
void insertionSort(T arr[], int n) {
    for (int i = 1; i < n; i++) {
        // 寻找元素arr[i]合适的插入位置
        for(int j=i; j>0;j--) {
            if(arr[j] < arr[j-1]) {
                std::swap(arr[j], arr[j-1]);
            }
            else {
                break;
            } 
        }
    }

}