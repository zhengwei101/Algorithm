#include <iostream>
#include <string>
using std::cout;
using std::endl;

template <typename T>
void selectionSort(T arr[], int n)
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

struct Student {
    std::string name;
    int score;

    bool operator<(const Student& otherStudent){
        return score < otherStudent.score;
    }
    friend std::ostream& operator<<(std::ostream& os, const Student& s){
        os << "Student: " << s.name << " " << s.score << endl;
        return os;
    }
};
int main()
{
    int a[10] = {10, 9, 6, 3, 1, 4, 2, 5, 8, 7};
    selectionSort(a, 10);
    for (auto &i : a)
        cout << i << " ";
    cout << endl;

    float b[4] = {4.4, 1.1, 3.3, 2.2};
    selectionSort(b, 4);
    for (auto &i : b)
        cout << i << " ";
    cout << endl;

    std::string c[4] = {"D", "A", "B", "C"};
    selectionSort(c, 4);
    for (auto &i : c)
        cout << i << " ";
    cout << endl;

    Student d[4] = {{"D",90}, {"A",100}, {"C",95},{"B",95}};
    selectionSort(d, 4);
    for (auto &i : d)
        cout << i;
}