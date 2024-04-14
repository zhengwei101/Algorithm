#include <iostream>
#include <stack>
#include <chrono>

using std::cout;
using std::endl;

// 递归
int recur(int n)
{
    if (n == 1)
        return 1;

    return n + recur(n - 1);
}

//使用迭代模拟递归
int forLoopRecur(int n)
{
    std::stack<int> stack;
    int res = 0;
    for(int i=n; i>0; i--)
    {
        stack.push(i); //通过“入栈操作”模拟“递”
    }

    //res = 1+2+3+...+n
    while(!stack.empty())
    {
        res += stack.top(); //通过“出栈操作”模拟“归”
        stack.pop();
    }

    return res;
}

// 尾递归
int tailRecur(int n, int res)
{
    if (n == 0)
        return res;

    return tailRecur(n - 1, res + n);
}

// 斐波那契数列(Fibonacci sequence)
int fib(int n)
{
    if (n == 1 || n == 2)
        return n - 1;

    //递归调用 f(n) = f(n-1) + f(n-2)
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    system("chcp 65001"); //支持中文输出

    int n = 1000;
    int res = 0;

    auto start{std::chrono::steady_clock::now()};
    res = recur(n);
    auto end{std::chrono::steady_clock::now()};
    std::chrono::duration<double> elapsed_seconds = end - start; 
    cout << "递归函数求和, res = " << res << " ,time cost: " << elapsed_seconds.count() << endl;
    
    start = std::chrono::steady_clock::now();
    res = forLoopRecur(n);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end - start; 
    cout << "使用迭代模拟递归求和, res = " << res << " ,time const: " << elapsed_seconds.count() << endl;

    start = std::chrono::steady_clock::now();
    res = recur(n);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end - start; 
    cout << "尾递归函数求和, res = " << res << " ,time const: " << elapsed_seconds.count() << endl;

    n = 5;
    res = fib(n);
    cout << "斐波那契数列的第 " << n << " 项为 " << res << endl;
}