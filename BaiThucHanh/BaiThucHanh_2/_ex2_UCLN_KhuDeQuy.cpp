#include <bits/stdc++.h>
#include <math.h>
using namespace std;

// Bài tập 2: Cài đặt bài toán tìm ước số chung lớn nhất theo thuật toán lặp (khử đệ quy)

int gcd(int a, int b)
{
    int tmp;
    while (b != 0)
    {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main(int argc, char const *argv[])
{
    cout << gcd(4, 6);
    cout << __gcd(4, 6);
    return 0;
}
