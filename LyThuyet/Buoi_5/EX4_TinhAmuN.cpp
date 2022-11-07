#include <bits/stdc++.h>
using namespace std;

// Tính a mũ n bằng chiến lược chia để trị (a thực, n nguyên dương).
double long Pow(float a, int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return a;
    int m = n / 2;
    double long x = Pow(a, m);
    return n % 2 == 0 ? x * x : x * x * a;
}

int main(int argc, char const *argv[])
{
    cout << Pow(2, 64) << endl;
    cout << pow(2, 64);
    return 0;
}
