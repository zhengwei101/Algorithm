#pragma once

template <typename T>
void insertionSort(T arr[], int n) {
    //for (int i = 1; i < n; i++) {
    //    // Ѱ��Ԫ��arr[i]���ʵĲ���λ��
    //    for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
    //        std::swap(arr[j], arr[j - 1]);
    //    }
    //}

    //�Ż�ʵ��
    for (int i = 1; i < n; i++) {
        T e = arr[i];
        int j = i; // j����Ԫ��eӦ�ò����λ��
        for (; j > 0 && arr[j - 1] > e; j--) {
            arr[j] = arr[j - 1];
        }
        arr[j] = e;
    }
}