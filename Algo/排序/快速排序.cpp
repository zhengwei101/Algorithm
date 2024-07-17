#include "SortTestHelper.h"
#include "MergeSort.h"
#include "QuickSort.h"


// �Ƚ�Merge Sort��Quick Sort���������㷨������Ч��
// ���������㷨��Ȼ����O(nlogn)�����, ����Quick Sort�㷨�г�����������
// Quick SortҪ��Merge Sort��, ��ʹ���Ƕ�Merge Sort�������Ż�

int main() {
    int n = 1000000;

    // ����1 һ���Բ���
    cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
    int* arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int* arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);

    delete[] arr1;
    delete[] arr2;

    cout << endl;

    // ����2 ���Խ������������
    // ���Ƕ��ڽ������������, ���ǵĿ��������㷨�˻�����O(n^2)������㷨
    // ˼��һ��Ϊʲô���ڽ������������, �����˻�����O(n^2)���㷨? :)
    //    int swapTimes = 100;
    //    cout<<"Test for nearly ordered array, size = "<<n<<", swap time = "<<swapTimes<<endl;
    //    arr1 = SortTestHelper::generateNearlyOrderedArray(n,swapTimes);
    //    arr2 = SortTestHelper::copyIntArray(arr1, n);
    //
    //    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    //    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
    //
    //    delete[] arr1;
    //    delete[] arr2;

    return 0;
}