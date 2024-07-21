#include <iostream>
using std::cout;
using std::endl;

#include <cstdlib>
#include <ctime>

int getRandomIndex(int size)
{
    srand((unsigned)time(NULL));

    // 获取指定范围[m,n]的随机数, 注意：n - m 的绝对值不能超过32767
    int m = 0;
    int n = size - 1;
    int index = rand() % (n - m + 1) + m;
    return index;
}

template <typename T>
void printArray(T *arr, int n)
{
    cout << "[";
    for (int i = 0; i < n - 1; i++)
    {
        cout << arr[i] << ", ";
    }
    if (n >= 1)
        cout << arr[n - 1] << "]" << endl;
    else
        cout << "]" << endl;
}

#include <random>

// 随机访问元素
int randomAccess(int *nums, int size)
{
    std::random_device random_device;                     // create object for seeding
    std::mt19937 engine{random_device()};                 // create engine and seed it
    std::uniform_int_distribution<int> dist(0, size - 1); // create distribution for integers with range [x:y]
    int random_number = dist(engine);                    // finally get a pseudo-random integer number

    // 获取并返回随机元素
    return nums[random_number];
}

int main()
{
    system("chcp 65001"); // 支持中文输出

    // 初始化数组
    int size = 6;
    int *nums = new int[size]{1, 3, 2, 5, 4, 6};

    cout << "数组 nums = ";
    printArray(nums, size);

    // 随机访问
    for(int i=0; i<2; i++)
    {
        cout << "在 nums 中获取随机元素 " << randomAccess(nums, size) << endl;
    }
}