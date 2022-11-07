#include <bits/stdc++.h>
#include <math.h>
using namespace std;

// Bài tập 1: Cài đặt bài toán tìm ước số chung lớn nhất theo thuật toán đệ quy

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main(int argc, char const *argv[])
{
    cout << gcd(4, 6);
    cout << __gcd(4, 6);
    return 0;
}
