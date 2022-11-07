#include <iostream>
using namespace std;

// Bài tập 2: Cài đặt bài toán tìm số fibonaci theo thuật toán lặp (khử đệ quy)

long Fibo(int n)
{
    // if (n < 3)
    //     return 1;

    int fn = 1, fn1 = 1, fn2 = 1;
    for (int i = 3; i <= n; i++)
    {
        fn = fn1 + fn2;
        fn2 = fn1;
        fn1 = fn;
    }
    return fn;
}

int main(int argc, char const *argv[])
{
    for (int i = 1; i < 8; i++)
    {
        cout << Fibo(i) << " ";
    }

    return 0;
}
