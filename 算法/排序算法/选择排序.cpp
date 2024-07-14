#include <iostream>
using std::cout;
using std::endl;

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        // 寻找[i,n)区间里的最小值
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

int main()
{
    int a[10] = {10, 9, 6, 3, 1, 4, 2, 5, 8, 7};
    selectionSort(a, 10);
    for (auto &i : a)
    {
        cout << i << " ";
    }
}