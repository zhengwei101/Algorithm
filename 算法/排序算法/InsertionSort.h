#pragma once

template <typename T>
void insertionSort(T arr[], int n) {
    for (int i = 1; i < n; i++) {
        // Ѱ��Ԫ��arr[i]���ʵĲ���λ��
        for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
            std::swap(arr[j], arr[j - 1]);
        }
    }
}