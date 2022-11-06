#include <bits/stdc++.h>
using namespace std;

// Bài tập 7: Cài đặt chương trình tìm số Fibonaci thứ n bằng đệ quy có nhớ.
// 1 1 2 3 5 8 ...

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
