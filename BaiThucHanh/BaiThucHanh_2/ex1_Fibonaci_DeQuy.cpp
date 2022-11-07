#include <iostream>
using namespace std;

// Bài tập 1: Cài đặt bài toán tìm số fibonaci theo thuật toán đệ quy

long Fibo(int n)
{
    if (n < 3)
        return 1;

    return Fibo(n - 1) + Fibo(n - 2);
}

int main(int argc, char const *argv[])
{
    cout << Fibo(5);
    return 0;
}
